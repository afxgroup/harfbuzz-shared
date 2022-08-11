/*
 * Copyright © 2022  Google, Inc.
 *
 *  This is part of HarfBuzz, a text shaping library.
 *
 * Permission is hereby granted, without written agreement and without
 * license or royalty fees, to use, copy, modify, and distribute this
 * software and its documentation for any purpose, provided that the
 * above copyright notice and the following two paragraphs appear in
 * all copies of this software.
 *
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE TO ANY PARTY FOR
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES
 * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN
 * IF THE COPYRIGHT HOLDER HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 *
 * THE COPYRIGHT HOLDER SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING,
 * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
 * ON AN "AS IS" BASIS, AND THE COPYRIGHT HOLDER HAS NO OBLIGATION TO
 * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
 *
 * Google Author(s): Garret Rieger
 */

#ifndef GRAPH_MARKBASEPOS_GRAPH_HH
#define GRAPH_MARKBASEPOS_GRAPH_HH

#include "split-helpers.hh"
#include "coverage-graph.hh"
#include "../OT/Layout/GPOS/MarkBasePos.hh"
#include "../OT/Layout/GPOS/PosLookupSubTable.hh"

namespace graph {

struct AnchorMatrix : public OT::Layout::GPOS_impl::AnchorMatrix
{
  bool sanitize (graph_t::vertex_t& vertex) const
  {
    // TODO
    return false;
  }

  bool shrink (gsubgpos_graph_context_t& c,
               unsigned this_index,
               unsigned old_class_count,
               unsigned new_class_count)
  {
    if (new_class_count >= old_class_count) return false;
    auto& o = c.graph.vertices_[this_index].obj;
    unsigned base_count = rows;
    o.tail = o.head +
             AnchorMatrix::min_size +
             OT::Offset16::static_size * base_count * new_class_count;

    // Reposition links into the new indexing scheme.
    for (auto& link : o.real_links.writer ())
    {
      unsigned index = (link.position - 2) / 2;
      unsigned base = index / old_class_count;
      unsigned klass = index % old_class_count;
      if (klass >= new_class_count)
        // should have already been removed
        return false;

      unsigned new_index = base * new_class_count + klass;

      link.position = (char*) &(this->matrixZ[new_index]) - (char*) this;
    }

    return true;
  }

  unsigned clone (gsubgpos_graph_context_t& c,
                  unsigned this_index,
                  const hb_hashmap_t<unsigned, unsigned>& pos_to_index,
                  unsigned start,
                  unsigned end,
                  unsigned class_count)
  {
    unsigned base_count = rows;
    unsigned new_class_count = end - start;
    unsigned size = AnchorMatrix::min_size +
                    OT::Offset16::static_size * new_class_count * rows;
    unsigned prime_id = c.create_node (size);
    if (prime_id == (unsigned) -1) return -1;
    AnchorMatrix* prime = (AnchorMatrix*) c.graph.object (prime_id).head;
    prime->rows = base_count;

    for (unsigned base = 0; base < base_count; base++)
    {
      for (unsigned klass = start; klass < end; klass++)
      {
        unsigned new_klass = klass - start;

        unsigned old_index = base * class_count + klass;
        unsigned new_index = base * new_class_count + new_klass;

        unsigned offset_pos = (char*) &(this->matrixZ[old_index]) -
                              (char*) this;
        unsigned* objidx;
        if (pos_to_index.has (offset_pos, &objidx))
          c.graph.move_child (this_index,
                              &(this->matrixZ[old_index]),
                              prime_id,
                              &(prime->matrixZ[new_index]));
      }
    }

    return prime_id;
  }
};

struct MarkArray : public OT::Layout::GPOS_impl::MarkArray
{
  bool sanitize (graph_t::vertex_t& vertex) const
  {
    // TODO
    return false;
  }

  unsigned clone (gsubgpos_graph_context_t& c,
                  unsigned this_index,
                  const hb_hashmap_t<unsigned, unsigned>& pos_to_index,
                  hb_set_t& marks)
  {
    unsigned size = MarkArray::min_size +
                    OT::Layout::GPOS_impl::MarkRecord::static_size *
                    marks.get_population ();
    unsigned prime_id = c.create_node (size);
    if (prime_id == (unsigned) -1) return -1;
    MarkArray* prime = (MarkArray*) c.graph.object (prime_id).head;
    prime->len = marks.get_population ();


    unsigned i = 0;
    for (hb_codepoint_t mark : marks)
    {
      (*prime)[i].klass = (*this)[mark].klass;
      unsigned offset_pos = (char*) &((*this)[mark].markAnchor) - (char*) this;
      unsigned* anchor_index;
      if (pos_to_index.has (offset_pos, &anchor_index))
        c.graph.move_child (this_index,
                            &((*this)[mark].markAnchor),
                            prime_id,
                            &((*prime)[i].markAnchor));

      i++;
    }

    return prime_id;
  }
};

struct MarkBasePosFormat1 : public OT::Layout::GPOS_impl::MarkBasePosFormat1_2<SmallTypes>
{
  bool sanitize (graph_t::vertex_t& vertex) const
  {
    int64_t vertex_len = vertex.obj.tail - vertex.obj.head;
    unsigned min_size = OT::Layout::GPOS_impl::MarkBasePosFormat1_2<SmallTypes>::min_size;
    if (vertex_len < min_size) return false;

    // TODO
    return true;
  }

  hb_vector_t<unsigned> split_subtables (gsubgpos_graph_context_t& c, unsigned this_index)
  {
    hb_set_t visited;

    const unsigned base_coverage_id = c.graph.index_for_offset (this_index, &baseCoverage);
    const unsigned base_size =
        OT::Layout::GPOS_impl::PairPosFormat1_3<SmallTypes>::min_size +
        c.graph.vertices_[base_coverage_id].table_size ();

    hb_vector_t<class_info_t> class_to_info = get_class_info (c, this_index);

    unsigned partial_coverage_size = 4;
    unsigned accumulated = base_size;
    hb_vector_t<unsigned> split_points;
    unsigned class_count = classCount;
    for (unsigned klass = 0; klass < class_count; klass++)
    {
      class_info_t& info = class_to_info[klass];
      partial_coverage_size += OT::HBUINT16::static_size * info.marks.get_population ();
      unsigned accumulated_delta = OT::Layout::GPOS_impl::MarkRecord::static_size * info.marks.get_population ();
      // TODO this doesn't count up null offsets.
      accumulated_delta += OT::Offset16::static_size * info.child_indices.length;
      for (unsigned objidx : info.child_indices)
        accumulated_delta += c.graph.find_subgraph_size (objidx, visited);

      accumulated += accumulated_delta;
      unsigned total = accumulated + partial_coverage_size;

      if (total >= (1 << 16))
      {
        split_points.push (klass);
        accumulated = base_size + accumulated_delta;
        partial_coverage_size = 4 + OT::HBUINT16::static_size * info.marks.get_population ();
        visited.clear (); // node sharing isn't allowed between splits.
      }
    }


    const unsigned mark_array_id = c.graph.index_for_offset (this_index, &markArray);
    const unsigned base_array_id = c.graph.index_for_offset (this_index, &baseArray);


    split_context_t split_context {
      c,
      this,
      this_index,
      std::move (class_to_info),
      c.graph.vertices_[mark_array_id].position_to_index_map (),
      c.graph.vertices_[base_array_id].position_to_index_map ()
    };

    return actuate_subtable_split<split_context_t> (split_context, split_points);
  }

 private:

  struct class_info_t {
    hb_set_t marks;
    hb_vector_t<unsigned> child_indices;
  };

  struct split_context_t {
    gsubgpos_graph_context_t& c;
    MarkBasePosFormat1* thiz;
    unsigned this_index;
    hb_vector_t<class_info_t> class_to_info;
    hb_hashmap_t<unsigned, unsigned> mark_array_links;
    hb_hashmap_t<unsigned, unsigned> base_array_links;

    hb_set_t marks_for (unsigned start, unsigned end)
    {
      hb_set_t marks;
      for (unsigned klass = start; klass < end; klass++)
      {
        + class_to_info[klass].marks.iter ()
        | hb_sink (marks)
        ;
      }
      return marks;
    }

    unsigned original_count ()
    {
      return thiz->classCount;
    }

    unsigned clone_range (unsigned start, unsigned end)
    {
      return thiz->clone_range (*this, this->this_index, start, end);
    }

    bool shrink (unsigned count)
    {
      return thiz->shrink (*this, this->this_index, count);
    }
  };

  hb_vector_t<class_info_t> get_class_info (gsubgpos_graph_context_t& c,
                                            unsigned this_index)
  {
    hb_vector_t<class_info_t> class_to_info;

    unsigned class_count= classCount;
    class_to_info.resize (class_count);

    auto mark_array = c.graph.as_table<MarkArray> (this_index, &markArray);
    if (!mark_array) return hb_vector_t<class_info_t> ();
    unsigned mark_count = mark_array.table->len;
    for (unsigned mark = 0; mark < mark_count; mark++)
    {
      unsigned klass = (*mark_array.table)[mark].get_class ();
      class_to_info[klass].marks.add (mark);
    }

    for (const auto& link : mark_array.vertex->obj.real_links)
    {
      unsigned mark = (link.position - 2) /
                     OT::Layout::GPOS_impl::MarkRecord::static_size;
      unsigned klass = (*mark_array.table)[mark].get_class ();
      class_to_info[klass].child_indices.push (link.objidx);
    }

    unsigned base_array_id =
        c.graph.index_for_offset (this_index, &baseArray);
    auto& base_array_v = c.graph.vertices_[base_array_id];

    for (const auto& link : base_array_v.obj.real_links)
    {
      unsigned index = (link.position - 2) / OT::Offset16::static_size;
      unsigned klass = index % class_count;
      class_to_info[klass].child_indices.push (link.objidx);
    }

    return class_to_info;
  }

  bool shrink (split_context_t& sc,
               unsigned this_index,
               unsigned count)
  {
    DEBUG_MSG (SUBSET_REPACK, nullptr,
               "  Shrinking MarkBasePosFormat1 (%u) to [0, %u).",
               this_index,
               count);

    unsigned old_count = classCount;
    if (count >= old_count)
      return true;

    classCount = count;

    auto mark_coverage = sc.c.graph.as_table<Coverage> (this_index,
                                                        &markCoverage);
    if (!mark_coverage) return false;
    hb_set_t marks = sc.marks_for (0, count);
    auto new_coverage =
        + hb_zip (hb_range (), mark_coverage.table->iter ())
        | hb_filter (marks, hb_first)
        | hb_map_retains_sorting (hb_second)
        ;
    if (!Coverage::make_coverage (sc.c, + new_coverage,
                                  mark_coverage.index,
                                  4 + 2 * marks.get_population ()))
      return false;


    auto base_array = sc.c.graph.as_table<AnchorMatrix> (this_index,
                                                         &baseArray);
    if (!base_array || !base_array.table->shrink (sc.c,
                                                  base_array.index,
                                                  old_count,
                                                  count))
      return false;

    // TODO: markArray
    /*


    return Coverage::make_coverage (c, new_coverage, coverage_id, coverage_size);
    */
    return -1; // TODO
  }

  // Create a new PairPos including PairSet's from start (inclusive) to end (exclusive).
  // Returns object id of the new object.
  unsigned clone_range (split_context_t& sc,
                        unsigned this_index,
                        unsigned start, unsigned end) const
  {
    DEBUG_MSG (SUBSET_REPACK, nullptr,
               "  Cloning MarkBasePosFormat1 (%u) range [%u, %u).", this_index, start, end);

    graph_t& graph = sc.c.graph;
    unsigned prime_size = OT::Layout::GPOS_impl::MarkBasePosFormat1_2<SmallTypes>::static_size;

    unsigned prime_id = sc.c.create_node (prime_size);
    if (prime_id == (unsigned) -1) return -1;

    MarkBasePosFormat1* prime = (MarkBasePosFormat1*) graph.object (prime_id).head;
    prime->format = this->format;
    prime->classCount = this->classCount;

    unsigned base_coverage_id =
        graph.index_for_offset (sc.this_index, &baseCoverage);
    graph.add_link (&(prime->baseCoverage), prime_id, base_coverage_id);
    graph.duplicate (prime_id, base_coverage_id);

    auto mark_coverage = sc.c.graph.as_table<Coverage> (this_index,
                                                        &markCoverage);
    if (!mark_coverage) return false;
    hb_set_t marks = sc.marks_for (start, end);
    auto new_coverage =
        + hb_zip (hb_range (), mark_coverage.table->iter ())
        | hb_filter (marks, hb_first)
        | hb_map_retains_sorting (hb_second)
        ;
    if (!Coverage::add_coverage (sc.c,
                                 prime_id,
                                 2,
                                 + new_coverage,
                                 marks.get_population () * 2 + 4))
      return -1;

    auto mark_array =
        graph.as_table <MarkArray> (sc.this_index, &markArray);
    if (!mark_array) return -1;
    unsigned new_mark_array =
        mark_array.table->clone (sc.c,
                                 mark_array.index,
                                 sc.mark_array_links,
                                 marks);
    graph.add_link (&(prime->markArray), prime_id, new_mark_array);

    auto base_array =
        graph.as_table<AnchorMatrix> (sc.this_index, &baseArray);
    if (!base_array) return -1;
    unsigned new_base_array =
        base_array.table->clone (sc.c,
                                 mark_array.index,
                                 sc.base_array_links,
                                 start, end, this->classCount);
    graph.add_link (&(prime->baseArray), prime_id, new_base_array);

    return prime_id;
  }
};


struct MarkBasePos : public OT::Layout::GPOS_impl::MarkBasePos
{
  hb_vector_t<unsigned> split_subtables (gsubgpos_graph_context_t& c,
                                         unsigned this_index)
  {
    switch (u.format) {
    case 1:
      return ((MarkBasePosFormat1*)(&u.format1))->split_subtables (c, this_index);
#ifndef HB_NO_BORING_EXPANSION
    case 2: HB_FALLTHROUGH;
      // Don't split 24bit PairPos's.
#endif
    default:
      return hb_vector_t<unsigned> ();
    }
  }

  bool sanitize (graph_t::vertex_t& vertex) const
  {
    int64_t vertex_len = vertex.obj.tail - vertex.obj.head;
    if (vertex_len < u.format.get_size ()) return false;

    switch (u.format) {
    case 1:
      return ((PairPosFormat1*)(&u.format1))->sanitize (vertex);
#ifndef HB_NO_BORING_EXPANSION
    case 2: HB_FALLTHROUGH;
#endif
    default:
      // We don't handle format 3 and 4 here.
      return false;
    }
  }
};


}

#endif  // GRAPH_MARKBASEPOS_GRAPH_HH
