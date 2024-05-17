#include <stdarg.h>
#include <exec/exec.h>
#include <proto/exec.h>
#include <proto/harfbuzz.h>

#include <cairo.h>
#include <freetype/freetype.h>
#include <hb.h>
#include <hb-aat.h>
#include <hb-cairo.h>
#include <hb-ft.h>
#include <hb-subset.h>
#include <hb-subset-repacker.h>

#include <stdarg.h>

uint32 _impl_Obtain(struct HarfbuzzIFace *Self)
{
	uint32 res;
	__asm__ __volatile__(
		"1:	lwarx	%0,0,%1\n"
		"addic	%0,%0,1\n"
		"stwcx.	%0,0,%1\n"
		"bne-	1b"
		: "=&r"(res)
		: "r"(&Self->Data.RefCount)
		: "cc", "memory");

	return res;
}

uint32 _impl_Release(struct HarfbuzzIFace *Self)
{
	uint32 res;
	__asm__ __volatile__(
		"1:	lwarx	%0,0,%1\n"
		"addic	%0,%0,-1\n"
		"stwcx.	%0,0,%1\n"
		"bne-	1b"
		: "=&r"(res)
		: "r"(&Self->Data.RefCount)
		: "cc", "memory");

	return res;
}


unsigned int _impl_hb_aat_layout_get_feature_types(struct HarfbuzzIFace *Self, hb_face_t * face, unsigned int start_offset, unsigned int * feature_count, hb_aat_layout_feature_type_t * features) {
	return hb_aat_layout_get_feature_types(face,start_offset,feature_count,features);
}

hb_ot_name_id_t _impl_hb_aat_layout_feature_type_get_name_id(struct HarfbuzzIFace *Self, hb_face_t * face, hb_aat_layout_feature_type_t feature_type) {
	return hb_aat_layout_feature_type_get_name_id(face,feature_type);
}

unsigned int _impl_hb_aat_layout_feature_type_get_selector_infos(struct HarfbuzzIFace *Self, hb_face_t * face, hb_aat_layout_feature_type_t feature_type, unsigned int start_offset, unsigned int * selector_count, hb_aat_layout_feature_selector_info_t * selectors, unsigned int * default_index) {
	return hb_aat_layout_feature_type_get_selector_infos(face,feature_type,start_offset,selector_count,selectors,default_index);
}

hb_bool_t _impl_hb_aat_layout_has_substitution(struct HarfbuzzIFace *Self, hb_face_t * face) {
	return hb_aat_layout_has_substitution(face);
}

hb_bool_t _impl_hb_aat_layout_has_positioning(struct HarfbuzzIFace *Self, hb_face_t * face) {
	return hb_aat_layout_has_positioning(face);
}

hb_bool_t _impl_hb_aat_layout_has_tracking(struct HarfbuzzIFace *Self, hb_face_t * face) {
	return hb_aat_layout_has_tracking(face);
}

hb_blob_t * _impl_hb_blob_create(struct HarfbuzzIFace *Self, const char * data, unsigned int length, hb_memory_mode_t mode, void * user_data, hb_destroy_func_t destroy) {
	return hb_blob_create(data,length,mode,user_data,destroy);
}

hb_blob_t * _impl_hb_blob_create_or_fail(struct HarfbuzzIFace *Self, const char * data, unsigned int length, hb_memory_mode_t mode, void * user_data, hb_destroy_func_t destroy) {
	return hb_blob_create_or_fail(data,length,mode,user_data,destroy);
}

hb_blob_t * _impl_hb_blob_create_from_file(struct HarfbuzzIFace *Self, const char * file_name) {
	return hb_blob_create_from_file(file_name);
}

hb_blob_t * _impl_hb_blob_create_from_file_or_fail(struct HarfbuzzIFace *Self, const char * file_name) {
	return hb_blob_create_from_file_or_fail(file_name);
}

hb_blob_t * _impl_hb_blob_create_sub_blob(struct HarfbuzzIFace *Self, hb_blob_t * parent, unsigned int offset, unsigned int length) {
	return hb_blob_create_sub_blob(parent,offset,length);
}

hb_blob_t * _impl_hb_blob_copy_writable_or_fail(struct HarfbuzzIFace *Self, hb_blob_t * blob) {
	return hb_blob_copy_writable_or_fail(blob);
}

hb_blob_t * _impl_hb_blob_get_empty(struct HarfbuzzIFace *Self) {
	return hb_blob_get_empty();
}

hb_blob_t * _impl_hb_blob_reference(struct HarfbuzzIFace *Self, hb_blob_t * blob) {
	return hb_blob_reference(blob);
}

void _impl_hb_blob_destroy(struct HarfbuzzIFace *Self, hb_blob_t * blob) {
	hb_blob_destroy(blob);
}

hb_bool_t _impl_hb_blob_set_user_data(struct HarfbuzzIFace *Self, hb_blob_t * blob, hb_user_data_key_t * key, void * data, hb_destroy_func_t destroy, hb_bool_t replace) {
	return hb_blob_set_user_data(blob,key,data,destroy,replace);
}

void * _impl_hb_blob_get_user_data(struct HarfbuzzIFace *Self, const hb_blob_t * blob, hb_user_data_key_t * key) {
	return hb_blob_get_user_data(blob,key);
}

void _impl_hb_blob_make_immutable(struct HarfbuzzIFace *Self, hb_blob_t * blob) {
	hb_blob_make_immutable(blob);
}

hb_bool_t _impl_hb_blob_is_immutable(struct HarfbuzzIFace *Self, hb_blob_t * blob) {
	return hb_blob_is_immutable(blob);
}

unsigned int _impl_hb_blob_get_length(struct HarfbuzzIFace *Self, hb_blob_t * blob) {
	return hb_blob_get_length(blob);
}

const char * _impl_hb_blob_get_data(struct HarfbuzzIFace *Self, hb_blob_t * blob, unsigned int * length) {
	return hb_blob_get_data(blob,length);
}

char * _impl_hb_blob_get_data_writable(struct HarfbuzzIFace *Self, hb_blob_t * blob, unsigned int * length) {
	return hb_blob_get_data_writable(blob,length);
}

hb_glyph_flags_t _impl_hb_glyph_info_get_glyph_flags(struct HarfbuzzIFace *Self, const hb_glyph_info_t * info) {
	return hb_glyph_info_get_glyph_flags(info);
}

hb_bool_t _impl_hb_segment_properties_equal(struct HarfbuzzIFace *Self, const hb_segment_properties_t * a, const hb_segment_properties_t * b) {
	return hb_segment_properties_equal(a,b);
}

unsigned int _impl_hb_segment_properties_hash(struct HarfbuzzIFace *Self, const hb_segment_properties_t * p) {
	return hb_segment_properties_hash(p);
}

void _impl_hb_segment_properties_overlay(struct HarfbuzzIFace *Self, hb_segment_properties_t * p, const hb_segment_properties_t * src) {
	hb_segment_properties_overlay(p,src);
}

hb_buffer_t * _impl_hb_buffer_create(struct HarfbuzzIFace *Self) {
	return hb_buffer_create();
}

hb_buffer_t * _impl_hb_buffer_create_similar(struct HarfbuzzIFace *Self, const hb_buffer_t * src) {
	return hb_buffer_create_similar(src);
}

void _impl_hb_buffer_reset(struct HarfbuzzIFace *Self, hb_buffer_t * buffer) {
	hb_buffer_reset(buffer);
}

hb_buffer_t * _impl_hb_buffer_get_empty(struct HarfbuzzIFace *Self) {
	return hb_buffer_get_empty();
}

hb_buffer_t * _impl_hb_buffer_reference(struct HarfbuzzIFace *Self, hb_buffer_t * buffer) {
	return hb_buffer_reference(buffer);
}

void _impl_hb_buffer_destroy(struct HarfbuzzIFace *Self, hb_buffer_t * buffer) {
	hb_buffer_destroy(buffer);
}

hb_bool_t _impl_hb_buffer_set_user_data(struct HarfbuzzIFace *Self, hb_buffer_t * buffer, hb_user_data_key_t * key, void * data, hb_destroy_func_t destroy, hb_bool_t replace) {
	return hb_buffer_set_user_data(buffer,key,data,destroy,replace);
}

void * _impl_hb_buffer_get_user_data(struct HarfbuzzIFace *Self, const hb_buffer_t * buffer, hb_user_data_key_t * key) {
	return hb_buffer_get_user_data(buffer,key);
}

void _impl_hb_buffer_set_content_type(struct HarfbuzzIFace *Self, hb_buffer_t * buffer, hb_buffer_content_type_t content_type) {
	hb_buffer_set_content_type(buffer,content_type);
}

hb_buffer_content_type_t _impl_hb_buffer_get_content_type(struct HarfbuzzIFace *Self, const hb_buffer_t * buffer) {
	return hb_buffer_get_content_type(buffer);
}

void _impl_hb_buffer_set_unicode_funcs(struct HarfbuzzIFace *Self, hb_buffer_t * buffer, hb_unicode_funcs_t * unicode_funcs) {
	hb_buffer_set_unicode_funcs(buffer,unicode_funcs);
}

hb_unicode_funcs_t * _impl_hb_buffer_get_unicode_funcs(struct HarfbuzzIFace *Self, const hb_buffer_t * buffer) {
	return hb_buffer_get_unicode_funcs(buffer);
}

void _impl_hb_buffer_set_direction(struct HarfbuzzIFace *Self, hb_buffer_t * buffer, hb_direction_t direction) {
	hb_buffer_set_direction(buffer,direction);
}

hb_direction_t _impl_hb_buffer_get_direction(struct HarfbuzzIFace *Self, const hb_buffer_t * buffer) {
	return hb_buffer_get_direction(buffer);
}

void _impl_hb_buffer_set_script(struct HarfbuzzIFace *Self, hb_buffer_t * buffer, hb_script_t script) {
	hb_buffer_set_script(buffer,script);
}

hb_script_t _impl_hb_buffer_get_script(struct HarfbuzzIFace *Self, const hb_buffer_t * buffer) {
	return hb_buffer_get_script(buffer);
}

void _impl_hb_buffer_set_language(struct HarfbuzzIFace *Self, hb_buffer_t * buffer, hb_language_t language) {
	hb_buffer_set_language(buffer,language);
}

hb_language_t _impl_hb_buffer_get_language(struct HarfbuzzIFace *Self, const hb_buffer_t * buffer) {
	return hb_buffer_get_language(buffer);
}

void _impl_hb_buffer_set_segment_properties(struct HarfbuzzIFace *Self, hb_buffer_t * buffer, const hb_segment_properties_t * props) {
	hb_buffer_set_segment_properties(buffer,props);
}

void _impl_hb_buffer_get_segment_properties(struct HarfbuzzIFace *Self, const hb_buffer_t * buffer, hb_segment_properties_t * props) {
	hb_buffer_get_segment_properties(buffer,props);
}

void _impl_hb_buffer_guess_segment_properties(struct HarfbuzzIFace *Self, hb_buffer_t * buffer) {
	hb_buffer_guess_segment_properties(buffer);
}

void _impl_hb_buffer_set_flags(struct HarfbuzzIFace *Self, hb_buffer_t * buffer, hb_buffer_flags_t flags) {
	hb_buffer_set_flags(buffer,flags);
}

hb_buffer_flags_t _impl_hb_buffer_get_flags(struct HarfbuzzIFace *Self, const hb_buffer_t * buffer) {
	return hb_buffer_get_flags(buffer);
}

void _impl_hb_buffer_set_cluster_level(struct HarfbuzzIFace *Self, hb_buffer_t * buffer, hb_buffer_cluster_level_t cluster_level) {
	hb_buffer_set_cluster_level(buffer,cluster_level);
}

hb_buffer_cluster_level_t _impl_hb_buffer_get_cluster_level(struct HarfbuzzIFace *Self, const hb_buffer_t * buffer) {
	return hb_buffer_get_cluster_level(buffer);
}

void _impl_hb_buffer_set_replacement_codepoint(struct HarfbuzzIFace *Self, hb_buffer_t * buffer, hb_codepoint_t replacement) {
	hb_buffer_set_replacement_codepoint(buffer,replacement);
}

hb_codepoint_t _impl_hb_buffer_get_replacement_codepoint(struct HarfbuzzIFace *Self, const hb_buffer_t * buffer) {
	return hb_buffer_get_replacement_codepoint(buffer);
}

void _impl_hb_buffer_set_invisible_glyph(struct HarfbuzzIFace *Self, hb_buffer_t * buffer, hb_codepoint_t invisible) {
	hb_buffer_set_invisible_glyph(buffer,invisible);
}

hb_codepoint_t _impl_hb_buffer_get_invisible_glyph(struct HarfbuzzIFace *Self, const hb_buffer_t * buffer) {
	return hb_buffer_get_invisible_glyph(buffer);
}

void _impl_hb_buffer_set_not_found_glyph(struct HarfbuzzIFace *Self, hb_buffer_t * buffer, hb_codepoint_t not_found) {
	hb_buffer_set_not_found_glyph(buffer,not_found);
}

hb_codepoint_t _impl_hb_buffer_get_not_found_glyph(struct HarfbuzzIFace *Self, const hb_buffer_t * buffer) {
	return hb_buffer_get_not_found_glyph(buffer);
}

void _impl_hb_buffer_set_random_state(struct HarfbuzzIFace *Self, hb_buffer_t * buffer, unsigned state) {
	hb_buffer_set_random_state(buffer,state);
}

unsigned _impl_hb_buffer_get_random_state(struct HarfbuzzIFace *Self, const hb_buffer_t * buffer) {
	return hb_buffer_get_random_state(buffer);
}

void _impl_hb_buffer_clear_contents(struct HarfbuzzIFace *Self, hb_buffer_t * buffer) {
	hb_buffer_clear_contents(buffer);
}

hb_bool_t _impl_hb_buffer_pre_allocate(struct HarfbuzzIFace *Self, hb_buffer_t * buffer, unsigned int size) {
	return hb_buffer_pre_allocate(buffer,size);
}

hb_bool_t _impl_hb_buffer_allocation_successful(struct HarfbuzzIFace *Self, hb_buffer_t * buffer) {
	return hb_buffer_allocation_successful(buffer);
}

void _impl_hb_buffer_reverse(struct HarfbuzzIFace *Self, hb_buffer_t * buffer) {
	hb_buffer_reverse(buffer);
}

void _impl_hb_buffer_reverse_range(struct HarfbuzzIFace *Self, hb_buffer_t * buffer, unsigned int start, unsigned int end) {
	hb_buffer_reverse_range(buffer,start,end);
}

void _impl_hb_buffer_reverse_clusters(struct HarfbuzzIFace *Self, hb_buffer_t * buffer) {
	hb_buffer_reverse_clusters(buffer);
}

void _impl_hb_buffer_add(struct HarfbuzzIFace *Self, hb_buffer_t * buffer, hb_codepoint_t codepoint, unsigned int cluster) {
	hb_buffer_add(buffer,codepoint,cluster);
}

void _impl_hb_buffer_add_utf8(struct HarfbuzzIFace *Self, hb_buffer_t * buffer, const char * text, int text_length, unsigned int item_offset, int item_length) {
	hb_buffer_add_utf8(buffer,text,text_length,item_offset,item_length);
}

void _impl_hb_buffer_add_utf16(struct HarfbuzzIFace *Self, hb_buffer_t * buffer, const uint16_t * text, int text_length, unsigned int item_offset, int item_length) {
	hb_buffer_add_utf16(buffer,text,text_length,item_offset,item_length);
}

void _impl_hb_buffer_add_utf32(struct HarfbuzzIFace *Self, hb_buffer_t * buffer, const uint32_t * text, int text_length, unsigned int item_offset, int item_length) {
	hb_buffer_add_utf32(buffer,text,text_length,item_offset,item_length);
}

void _impl_hb_buffer_add_latin1(struct HarfbuzzIFace *Self, hb_buffer_t * buffer, const uint8_t * text, int text_length, unsigned int item_offset, int item_length) {
	hb_buffer_add_latin1(buffer,text,text_length,item_offset,item_length);
}

void _impl_hb_buffer_add_codepoints(struct HarfbuzzIFace *Self, hb_buffer_t * buffer, const hb_codepoint_t * text, int text_length, unsigned int item_offset, int item_length) {
	hb_buffer_add_codepoints(buffer,text,text_length,item_offset,item_length);
}

void _impl_hb_buffer_append(struct HarfbuzzIFace *Self, hb_buffer_t * buffer, const hb_buffer_t * source, unsigned int start, unsigned int end) {
	hb_buffer_append(buffer,source,start,end);
}

hb_bool_t _impl_hb_buffer_set_length(struct HarfbuzzIFace *Self, hb_buffer_t * buffer, unsigned int length) {
	return hb_buffer_set_length(buffer,length);
}

unsigned int _impl_hb_buffer_get_length(struct HarfbuzzIFace *Self, const hb_buffer_t * buffer) {
	return hb_buffer_get_length(buffer);
}

hb_glyph_info_t * _impl_hb_buffer_get_glyph_infos(struct HarfbuzzIFace *Self, hb_buffer_t * buffer, unsigned int * length) {
	return hb_buffer_get_glyph_infos(buffer,length);
}

hb_glyph_position_t * _impl_hb_buffer_get_glyph_positions(struct HarfbuzzIFace *Self, hb_buffer_t * buffer, unsigned int * length) {
	return hb_buffer_get_glyph_positions(buffer,length);
}

hb_bool_t _impl_hb_buffer_has_positions(struct HarfbuzzIFace *Self, hb_buffer_t * buffer) {
	return hb_buffer_has_positions(buffer);
}

void _impl_hb_buffer_normalize_glyphs(struct HarfbuzzIFace *Self, hb_buffer_t * buffer) {
	hb_buffer_normalize_glyphs(buffer);
}

hb_buffer_serialize_format_t _impl_hb_buffer_serialize_format_from_string(struct HarfbuzzIFace *Self, const char * str, int len) {
	return hb_buffer_serialize_format_from_string(str,len);
}

const char * _impl_hb_buffer_serialize_format_to_string(struct HarfbuzzIFace *Self, hb_buffer_serialize_format_t format) {
	return hb_buffer_serialize_format_to_string(format);
}

const char ** _impl_hb_buffer_serialize_list_formats(struct HarfbuzzIFace *Self) {
	return hb_buffer_serialize_list_formats();
}

unsigned int _impl_hb_buffer_serialize_glyphs(struct HarfbuzzIFace *Self, hb_buffer_t * buffer, unsigned int start, unsigned int end, char * buf, unsigned int buf_size, unsigned int * buf_consumed, hb_font_t * font, hb_buffer_serialize_format_t format, hb_buffer_serialize_flags_t flags) {
	return hb_buffer_serialize_glyphs(buffer,start,end,buf,buf_size,buf_consumed,font,format,flags);
}

unsigned int _impl_hb_buffer_serialize_unicode(struct HarfbuzzIFace *Self, hb_buffer_t * buffer, unsigned int start, unsigned int end, char * buf, unsigned int buf_size, unsigned int * buf_consumed, hb_buffer_serialize_format_t format, hb_buffer_serialize_flags_t flags) {
	return hb_buffer_serialize_unicode(buffer,start,end,buf,buf_size,buf_consumed,format,flags);
}

unsigned int _impl_hb_buffer_serialize(struct HarfbuzzIFace *Self, hb_buffer_t * buffer, unsigned int start, unsigned int end, char * buf, unsigned int buf_size, unsigned int * buf_consumed, hb_font_t * font, hb_buffer_serialize_format_t format, hb_buffer_serialize_flags_t flags) {
	return hb_buffer_serialize(buffer,start,end,buf,buf_size,buf_consumed,font,format,flags);
}

hb_bool_t _impl_hb_buffer_deserialize_glyphs(struct HarfbuzzIFace *Self, hb_buffer_t * buffer, const char * buf, int buf_len, const char * *end_ptr, hb_font_t * font, hb_buffer_serialize_format_t format) {
	return hb_buffer_deserialize_glyphs(buffer,buf,buf_len,end_ptr,font,format);
}

hb_bool_t _impl_hb_buffer_deserialize_unicode(struct HarfbuzzIFace *Self, hb_buffer_t * buffer, const char * buf, int buf_len, const char * *end_ptr, hb_buffer_serialize_format_t format) {
	return hb_buffer_deserialize_unicode(buffer,buf,buf_len,end_ptr,format);
}

hb_buffer_diff_flags_t _impl_hb_buffer_diff(struct HarfbuzzIFace *Self, hb_buffer_t * buffer, hb_buffer_t * reference, hb_codepoint_t dottedcircle_glyph, unsigned int position_fuzz) {
	return hb_buffer_diff(buffer,reference,dottedcircle_glyph,position_fuzz);
}

void _impl_hb_buffer_set_message_func(struct HarfbuzzIFace *Self, hb_buffer_t * buffer, hb_buffer_message_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_buffer_set_message_func(buffer,func,user_data,destroy);
}

cairo_font_face_t * _impl_hb_cairo_font_face_create_for_font(struct HarfbuzzIFace *Self, hb_font_t * font) {
	return hb_cairo_font_face_create_for_font(font);
}

hb_font_t * _impl_hb_cairo_font_face_get_font(struct HarfbuzzIFace *Self, cairo_font_face_t * font_face) {
	return hb_cairo_font_face_get_font(font_face);
}

cairo_font_face_t * _impl_hb_cairo_font_face_create_for_face(struct HarfbuzzIFace *Self, hb_face_t * face) {
	return hb_cairo_font_face_create_for_face(face);
}

hb_face_t * _impl_hb_cairo_font_face_get_face(struct HarfbuzzIFace *Self, cairo_font_face_t * font_face) {
	return hb_cairo_font_face_get_face(font_face);
}

void _impl_hb_cairo_font_face_set_font_init_func(struct HarfbuzzIFace *Self, cairo_font_face_t * font_face, hb_cairo_font_init_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_cairo_font_face_set_font_init_func(font_face,func,user_data,destroy);
}

hb_font_t * _impl_hb_cairo_scaled_font_get_font(struct HarfbuzzIFace *Self, cairo_scaled_font_t * scaled_font) {
	return hb_cairo_scaled_font_get_font(scaled_font);
}

void _impl_hb_cairo_font_face_set_scale_factor(struct HarfbuzzIFace *Self, cairo_font_face_t * font_face, unsigned int scale_factor) {
	hb_cairo_font_face_set_scale_factor(font_face,scale_factor);
}

unsigned int _impl_hb_cairo_font_face_get_scale_factor(struct HarfbuzzIFace *Self, cairo_font_face_t * font_face) {
	return hb_cairo_font_face_get_scale_factor(font_face);
}

void _impl_hb_cairo_glyphs_from_buffer(struct HarfbuzzIFace *Self, hb_buffer_t * buffer, hb_bool_t utf8_clusters, double x_scale_factor, double y_scale_factor, double x, double y, const char * utf8, int utf8_len, cairo_glyph_t * *glyphs, unsigned int * num_glyphs, cairo_text_cluster_t * *clusters, unsigned int * num_clusters, cairo_text_cluster_flags_t * cluster_flags) {
	hb_cairo_glyphs_from_buffer(buffer,utf8_clusters,x_scale_factor,y_scale_factor,x,y,utf8,utf8_len,glyphs,num_glyphs,clusters,num_clusters,cluster_flags);
}

hb_tag_t _impl_hb_tag_from_string(struct HarfbuzzIFace *Self, const char * str, int len) {
	return hb_tag_from_string(str,len);
}

void _impl_hb_tag_to_string(struct HarfbuzzIFace *Self, hb_tag_t tag, char * buf) {
	hb_tag_to_string(tag,buf);
}

hb_direction_t _impl_hb_direction_from_string(struct HarfbuzzIFace *Self, const char * str, int len) {
	return hb_direction_from_string(str,len);
}

const char * _impl_hb_direction_to_string(struct HarfbuzzIFace *Self, hb_direction_t direction) {
	return hb_direction_to_string(direction);
}

hb_language_t _impl_hb_language_from_string(struct HarfbuzzIFace *Self, const char * str, int len) {
	return hb_language_from_string(str,len);
}

const char * _impl_hb_language_to_string(struct HarfbuzzIFace *Self, hb_language_t language) {
	return hb_language_to_string(language);
}

hb_language_t _impl_hb_language_get_default(struct HarfbuzzIFace *Self) {
	return hb_language_get_default();
}

hb_bool_t _impl_hb_language_matches(struct HarfbuzzIFace *Self, hb_language_t language, hb_language_t specific) {
	return hb_language_matches(language,specific);
}

hb_script_t _impl_hb_script_from_iso15924_tag(struct HarfbuzzIFace *Self, hb_tag_t tag) {
	return hb_script_from_iso15924_tag(tag);
}

hb_script_t _impl_hb_script_from_string(struct HarfbuzzIFace *Self, const char * str, int len) {
	return hb_script_from_string(str,len);
}

hb_tag_t _impl_hb_script_to_iso15924_tag(struct HarfbuzzIFace *Self, hb_script_t script) {
	return hb_script_to_iso15924_tag(script);
}

hb_direction_t _impl_hb_script_get_horizontal_direction(struct HarfbuzzIFace *Self, hb_script_t script) {
	return hb_script_get_horizontal_direction(script);
}

hb_bool_t _impl_hb_feature_from_string(struct HarfbuzzIFace *Self, const char * str, int len, hb_feature_t * feature) {
	return hb_feature_from_string(str,len,feature);
}

void _impl_hb_feature_to_string(struct HarfbuzzIFace *Self, hb_feature_t * feature, char * buf, unsigned int size) {
	hb_feature_to_string(feature,buf,size);
}

hb_bool_t _impl_hb_variation_from_string(struct HarfbuzzIFace *Self, const char * str, int len, hb_variation_t * variation) {
	return hb_variation_from_string(str,len,variation);
}

void _impl_hb_variation_to_string(struct HarfbuzzIFace *Self, hb_variation_t * variation, char * buf, unsigned int size) {
	hb_variation_to_string(variation,buf,size);
}

uint8_t _impl_hb_color_get_alpha(struct HarfbuzzIFace *Self, hb_color_t color) {
	return hb_color_get_alpha(color);
}

uint8_t _impl_hb_color_get_red(struct HarfbuzzIFace *Self, hb_color_t color) {
	return hb_color_get_red(color);
}

uint8_t _impl_hb_color_get_green(struct HarfbuzzIFace *Self, hb_color_t color) {
	return hb_color_get_green(color);
}

uint8_t _impl_hb_color_get_blue(struct HarfbuzzIFace *Self, hb_color_t color) {
	return hb_color_get_blue(color);
}

void _impl_hb_font_funcs_set_glyph_func(struct HarfbuzzIFace *Self, hb_font_funcs_t * ffuncs, hb_font_get_glyph_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_font_funcs_set_glyph_func(ffuncs,func,user_data,destroy);
}

HB_DEPRECATED void _impl_hb_unicode_funcs_set_eastasian_width_func(struct HarfbuzzIFace *Self, hb_unicode_funcs_t * ufuncs, hb_unicode_eastasian_width_func_t func, void * user_data, hb_destroy_func_t destroy) {
	return hb_unicode_funcs_set_eastasian_width_func(ufuncs,func,user_data,destroy);
}

HB_DEPRECATED unsigned int _impl_hb_unicode_eastasian_width(struct HarfbuzzIFace *Self, hb_unicode_funcs_t * ufuncs, hb_codepoint_t unicode) {
	return hb_unicode_eastasian_width(ufuncs,unicode);
}

HB_DEPRECATED void _impl_hb_unicode_funcs_set_decompose_compatibility_func(struct HarfbuzzIFace *Self, hb_unicode_funcs_t * ufuncs, hb_unicode_decompose_compatibility_func_t func, void * user_data, hb_destroy_func_t destroy) {
	return hb_unicode_funcs_set_decompose_compatibility_func(ufuncs,func,user_data,destroy);
}

HB_DEPRECATED unsigned int _impl_hb_unicode_decompose_compatibility(struct HarfbuzzIFace *Self, hb_unicode_funcs_t * ufuncs, hb_codepoint_t u, hb_codepoint_t * decomposed) {
	return hb_unicode_decompose_compatibility(ufuncs,u,decomposed);
}

void _impl_hb_font_funcs_set_glyph_v_kerning_func(struct HarfbuzzIFace *Self, hb_font_funcs_t * ffuncs, hb_font_get_glyph_v_kerning_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_font_funcs_set_glyph_v_kerning_func(ffuncs,func,user_data,destroy);
}

hb_position_t _impl_hb_font_get_glyph_v_kerning(struct HarfbuzzIFace *Self, hb_font_t * font, hb_codepoint_t top_glyph, hb_codepoint_t bottom_glyph) {
	return hb_font_get_glyph_v_kerning(font,top_glyph,bottom_glyph);
}

void _impl_hb_font_funcs_set_glyph_shape_func(struct HarfbuzzIFace *Self, hb_font_funcs_t * ffuncs, hb_font_get_glyph_shape_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_font_funcs_set_glyph_shape_func(ffuncs,func,user_data,destroy);
}

void _impl_hb_font_get_glyph_shape(struct HarfbuzzIFace *Self, hb_font_t * font, hb_codepoint_t glyph, hb_draw_funcs_t * dfuncs, void * draw_data) {
	hb_font_get_glyph_shape(font,glyph,dfuncs,draw_data);
}

void _impl_hb_draw_funcs_set_move_to_func(struct HarfbuzzIFace *Self, hb_draw_funcs_t * dfuncs, hb_draw_move_to_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_draw_funcs_set_move_to_func(dfuncs,func,user_data,destroy);
}

void _impl_hb_draw_funcs_set_line_to_func(struct HarfbuzzIFace *Self, hb_draw_funcs_t * dfuncs, hb_draw_line_to_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_draw_funcs_set_line_to_func(dfuncs,func,user_data,destroy);
}

void _impl_hb_draw_funcs_set_quadratic_to_func(struct HarfbuzzIFace *Self, hb_draw_funcs_t * dfuncs, hb_draw_quadratic_to_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_draw_funcs_set_quadratic_to_func(dfuncs,func,user_data,destroy);
}

void _impl_hb_draw_funcs_set_cubic_to_func(struct HarfbuzzIFace *Self, hb_draw_funcs_t * dfuncs, hb_draw_cubic_to_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_draw_funcs_set_cubic_to_func(dfuncs,func,user_data,destroy);
}

void _impl_hb_draw_funcs_set_close_path_func(struct HarfbuzzIFace *Self, hb_draw_funcs_t * dfuncs, hb_draw_close_path_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_draw_funcs_set_close_path_func(dfuncs,func,user_data,destroy);
}

hb_draw_funcs_t * _impl_hb_draw_funcs_create(struct HarfbuzzIFace *Self) {
	return hb_draw_funcs_create();
}

hb_draw_funcs_t * _impl_hb_draw_funcs_get_empty(struct HarfbuzzIFace *Self) {
	return hb_draw_funcs_get_empty();
}

hb_draw_funcs_t * _impl_hb_draw_funcs_reference(struct HarfbuzzIFace *Self, hb_draw_funcs_t * dfuncs) {
	return hb_draw_funcs_reference(dfuncs);
}

void _impl_hb_draw_funcs_destroy(struct HarfbuzzIFace *Self, hb_draw_funcs_t * dfuncs) {
	hb_draw_funcs_destroy(dfuncs);
}

hb_bool_t _impl_hb_draw_funcs_set_user_data(struct HarfbuzzIFace *Self, hb_draw_funcs_t * dfuncs, hb_user_data_key_t * key, void * data, hb_destroy_func_t destroy, hb_bool_t replace) {
	return hb_draw_funcs_set_user_data(dfuncs,key,data,destroy,replace);
}

void * _impl_hb_draw_funcs_get_user_data(struct HarfbuzzIFace *Self, const hb_draw_funcs_t * dfuncs, hb_user_data_key_t * key) {
	return hb_draw_funcs_get_user_data(dfuncs,key);
}

void _impl_hb_draw_funcs_make_immutable(struct HarfbuzzIFace *Self, hb_draw_funcs_t * dfuncs) {
	hb_draw_funcs_make_immutable(dfuncs);
}

hb_bool_t _impl_hb_draw_funcs_is_immutable(struct HarfbuzzIFace *Self, hb_draw_funcs_t * dfuncs) {
	return hb_draw_funcs_is_immutable(dfuncs);
}

void _impl_hb_draw_move_to(struct HarfbuzzIFace *Self, hb_draw_funcs_t * dfuncs, void * draw_data, hb_draw_state_t * st, float to_x, float to_y) {
	hb_draw_move_to(dfuncs,draw_data,st,to_x,to_y);
}

void _impl_hb_draw_line_to(struct HarfbuzzIFace *Self, hb_draw_funcs_t * dfuncs, void * draw_data, hb_draw_state_t * st, float to_x, float to_y) {
	hb_draw_line_to(dfuncs,draw_data,st,to_x,to_y);
}

void _impl_hb_draw_quadratic_to(struct HarfbuzzIFace *Self, hb_draw_funcs_t * dfuncs, void * draw_data, hb_draw_state_t * st, float control_x, float control_y, float to_x, float to_y) {
	hb_draw_quadratic_to(dfuncs,draw_data,st,control_x,control_y,to_x,to_y);
}

void _impl_hb_draw_cubic_to(struct HarfbuzzIFace *Self, hb_draw_funcs_t * dfuncs, void * draw_data, hb_draw_state_t * st, float control1_x, float control1_y, float control2_x, float control2_y, float to_x, float to_y) {
	hb_draw_cubic_to(dfuncs,draw_data,st,control1_x,control1_y,control2_x,control2_y,to_x,to_y);
}

void _impl_hb_draw_close_path(struct HarfbuzzIFace *Self, hb_draw_funcs_t * dfuncs, void * draw_data, hb_draw_state_t * st) {
	hb_draw_close_path(dfuncs,draw_data,st);
}

unsigned int _impl_hb_face_count(struct HarfbuzzIFace *Self, hb_blob_t * blob) {
	return hb_face_count(blob);
}

hb_face_t * _impl_hb_face_create(struct HarfbuzzIFace *Self, hb_blob_t * blob, unsigned int index) {
	return hb_face_create(blob,index);
}

hb_face_t * _impl_hb_face_create_for_tables(struct HarfbuzzIFace *Self, hb_reference_table_func_t reference_table_func, void * user_data, hb_destroy_func_t destroy) {
	return hb_face_create_for_tables(reference_table_func,user_data,destroy);
}

hb_face_t * _impl_hb_face_get_empty(struct HarfbuzzIFace *Self) {
	return hb_face_get_empty();
}

hb_face_t * _impl_hb_face_reference(struct HarfbuzzIFace *Self, hb_face_t * face) {
	return hb_face_reference(face);
}

void _impl_hb_face_destroy(struct HarfbuzzIFace *Self, hb_face_t * face) {
	hb_face_destroy(face);
}

hb_bool_t _impl_hb_face_set_user_data(struct HarfbuzzIFace *Self, hb_face_t * face, hb_user_data_key_t * key, void * data, hb_destroy_func_t destroy, hb_bool_t replace) {
	return hb_face_set_user_data(face,key,data,destroy,replace);
}

void * _impl_hb_face_get_user_data(struct HarfbuzzIFace *Self, const hb_face_t * face, hb_user_data_key_t * key) {
	return hb_face_get_user_data(face,key);
}

void _impl_hb_face_make_immutable(struct HarfbuzzIFace *Self, hb_face_t * face) {
	hb_face_make_immutable(face);
}

hb_bool_t _impl_hb_face_is_immutable(struct HarfbuzzIFace *Self, const hb_face_t * face) {
	return hb_face_is_immutable(face);
}

hb_blob_t * _impl_hb_face_reference_table(struct HarfbuzzIFace *Self, const hb_face_t * face, hb_tag_t tag) {
	return hb_face_reference_table(face,tag);
}

hb_blob_t * _impl_hb_face_reference_blob(struct HarfbuzzIFace *Self, hb_face_t * face) {
	return hb_face_reference_blob(face);
}

void _impl_hb_face_set_index(struct HarfbuzzIFace *Self, hb_face_t * face, unsigned int index) {
	hb_face_set_index(face,index);
}

unsigned int _impl_hb_face_get_index(struct HarfbuzzIFace *Self, const hb_face_t * face) {
	return hb_face_get_index(face);
}

void _impl_hb_face_set_upem(struct HarfbuzzIFace *Self, hb_face_t * face, unsigned int upem) {
	hb_face_set_upem(face,upem);
}

unsigned int _impl_hb_face_get_upem(struct HarfbuzzIFace *Self, const hb_face_t * face) {
	return hb_face_get_upem(face);
}

void _impl_hb_face_set_glyph_count(struct HarfbuzzIFace *Self, hb_face_t * face, unsigned int glyph_count) {
	hb_face_set_glyph_count(face,glyph_count);
}

unsigned int _impl_hb_face_get_glyph_count(struct HarfbuzzIFace *Self, const hb_face_t * face) {
	return hb_face_get_glyph_count(face);
}

unsigned int _impl_hb_face_get_table_tags(struct HarfbuzzIFace *Self, const hb_face_t * face, unsigned int start_offset, unsigned int * table_count, hb_tag_t * table_tags) {
	return hb_face_get_table_tags(face,start_offset,table_count,table_tags);
}

void _impl_hb_face_collect_unicodes(struct HarfbuzzIFace *Self, hb_face_t * face, hb_set_t * out) {
	hb_face_collect_unicodes(face,out);
}

void _impl_hb_face_collect_nominal_glyph_mapping(struct HarfbuzzIFace *Self, hb_face_t * face, hb_map_t * mapping, hb_set_t * unicodes) {
	hb_face_collect_nominal_glyph_mapping(face,mapping,unicodes);
}

void _impl_hb_face_collect_variation_selectors(struct HarfbuzzIFace *Self, hb_face_t * face, hb_set_t * out) {
	hb_face_collect_variation_selectors(face,out);
}

void _impl_hb_face_collect_variation_unicodes(struct HarfbuzzIFace *Self, hb_face_t * face, hb_codepoint_t variation_selector, hb_set_t * out) {
	hb_face_collect_variation_unicodes(face,variation_selector,out);
}

hb_face_t * _impl_hb_face_builder_create(struct HarfbuzzIFace *Self) {
	return hb_face_builder_create();
}

hb_bool_t _impl_hb_face_builder_add_table(struct HarfbuzzIFace *Self, hb_face_t * face, hb_tag_t tag, hb_blob_t * blob) {
	return hb_face_builder_add_table(face,tag,blob);
}

void _impl_hb_face_builder_sort_tables(struct HarfbuzzIFace *Self, hb_face_t * face, const hb_tag_t * tags) {
	hb_face_builder_sort_tables(face,tags);
}

hb_font_funcs_t * _impl_hb_font_funcs_create(struct HarfbuzzIFace *Self) {
	return hb_font_funcs_create();
}

hb_font_funcs_t * _impl_hb_font_funcs_get_empty(struct HarfbuzzIFace *Self) {
	return hb_font_funcs_get_empty();
}

hb_font_funcs_t * _impl_hb_font_funcs_reference(struct HarfbuzzIFace *Self, hb_font_funcs_t * ffuncs) {
	return hb_font_funcs_reference(ffuncs);
}

void _impl_hb_font_funcs_destroy(struct HarfbuzzIFace *Self, hb_font_funcs_t * ffuncs) {
	hb_font_funcs_destroy(ffuncs);
}

hb_bool_t _impl_hb_font_funcs_set_user_data(struct HarfbuzzIFace *Self, hb_font_funcs_t * ffuncs, hb_user_data_key_t * key, void * data, hb_destroy_func_t destroy, hb_bool_t replace) {
	return hb_font_funcs_set_user_data(ffuncs,key,data,destroy,replace);
}

void * _impl_hb_font_funcs_get_user_data(struct HarfbuzzIFace *Self, const hb_font_funcs_t * ffuncs, hb_user_data_key_t * key) {
	return hb_font_funcs_get_user_data(ffuncs,key);
}

void _impl_hb_font_funcs_make_immutable(struct HarfbuzzIFace *Self, hb_font_funcs_t * ffuncs) {
	hb_font_funcs_make_immutable(ffuncs);
}

hb_bool_t _impl_hb_font_funcs_is_immutable(struct HarfbuzzIFace *Self, hb_font_funcs_t * ffuncs) {
	return hb_font_funcs_is_immutable(ffuncs);
}

void _impl_hb_font_funcs_set_font_h_extents_func(struct HarfbuzzIFace *Self, hb_font_funcs_t * ffuncs, hb_font_get_font_h_extents_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_font_funcs_set_font_h_extents_func(ffuncs,func,user_data,destroy);
}

void _impl_hb_font_funcs_set_font_v_extents_func(struct HarfbuzzIFace *Self, hb_font_funcs_t * ffuncs, hb_font_get_font_v_extents_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_font_funcs_set_font_v_extents_func(ffuncs,func,user_data,destroy);
}

void _impl_hb_font_funcs_set_nominal_glyph_func(struct HarfbuzzIFace *Self, hb_font_funcs_t * ffuncs, hb_font_get_nominal_glyph_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_font_funcs_set_nominal_glyph_func(ffuncs,func,user_data,destroy);
}

void _impl_hb_font_funcs_set_nominal_glyphs_func(struct HarfbuzzIFace *Self, hb_font_funcs_t * ffuncs, hb_font_get_nominal_glyphs_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_font_funcs_set_nominal_glyphs_func(ffuncs,func,user_data,destroy);
}

void _impl_hb_font_funcs_set_variation_glyph_func(struct HarfbuzzIFace *Self, hb_font_funcs_t * ffuncs, hb_font_get_variation_glyph_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_font_funcs_set_variation_glyph_func(ffuncs,func,user_data,destroy);
}

void _impl_hb_font_funcs_set_glyph_h_advance_func(struct HarfbuzzIFace *Self, hb_font_funcs_t * ffuncs, hb_font_get_glyph_h_advance_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_font_funcs_set_glyph_h_advance_func(ffuncs,func,user_data,destroy);
}

void _impl_hb_font_funcs_set_glyph_v_advance_func(struct HarfbuzzIFace *Self, hb_font_funcs_t * ffuncs, hb_font_get_glyph_v_advance_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_font_funcs_set_glyph_v_advance_func(ffuncs,func,user_data,destroy);
}

void _impl_hb_font_funcs_set_glyph_h_advances_func(struct HarfbuzzIFace *Self, hb_font_funcs_t * ffuncs, hb_font_get_glyph_h_advances_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_font_funcs_set_glyph_h_advances_func(ffuncs,func,user_data,destroy);
}

void _impl_hb_font_funcs_set_glyph_v_advances_func(struct HarfbuzzIFace *Self, hb_font_funcs_t * ffuncs, hb_font_get_glyph_v_advances_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_font_funcs_set_glyph_v_advances_func(ffuncs,func,user_data,destroy);
}

void _impl_hb_font_funcs_set_glyph_h_origin_func(struct HarfbuzzIFace *Self, hb_font_funcs_t * ffuncs, hb_font_get_glyph_h_origin_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_font_funcs_set_glyph_h_origin_func(ffuncs,func,user_data,destroy);
}

void _impl_hb_font_funcs_set_glyph_v_origin_func(struct HarfbuzzIFace *Self, hb_font_funcs_t * ffuncs, hb_font_get_glyph_v_origin_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_font_funcs_set_glyph_v_origin_func(ffuncs,func,user_data,destroy);
}

void _impl_hb_font_funcs_set_glyph_h_kerning_func(struct HarfbuzzIFace *Self, hb_font_funcs_t * ffuncs, hb_font_get_glyph_h_kerning_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_font_funcs_set_glyph_h_kerning_func(ffuncs,func,user_data,destroy);
}

void _impl_hb_font_funcs_set_glyph_extents_func(struct HarfbuzzIFace *Self, hb_font_funcs_t * ffuncs, hb_font_get_glyph_extents_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_font_funcs_set_glyph_extents_func(ffuncs,func,user_data,destroy);
}

void _impl_hb_font_funcs_set_glyph_contour_point_func(struct HarfbuzzIFace *Self, hb_font_funcs_t * ffuncs, hb_font_get_glyph_contour_point_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_font_funcs_set_glyph_contour_point_func(ffuncs,func,user_data,destroy);
}

void _impl_hb_font_funcs_set_glyph_name_func(struct HarfbuzzIFace *Self, hb_font_funcs_t * ffuncs, hb_font_get_glyph_name_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_font_funcs_set_glyph_name_func(ffuncs,func,user_data,destroy);
}

void _impl_hb_font_funcs_set_glyph_from_name_func(struct HarfbuzzIFace *Self, hb_font_funcs_t * ffuncs, hb_font_get_glyph_from_name_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_font_funcs_set_glyph_from_name_func(ffuncs,func,user_data,destroy);
}

void _impl_hb_font_funcs_set_draw_glyph_func(struct HarfbuzzIFace *Self, hb_font_funcs_t * ffuncs, hb_font_draw_glyph_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_font_funcs_set_draw_glyph_func(ffuncs,func,user_data,destroy);
}

void _impl_hb_font_funcs_set_paint_glyph_func(struct HarfbuzzIFace *Self, hb_font_funcs_t * ffuncs, hb_font_paint_glyph_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_font_funcs_set_paint_glyph_func(ffuncs,func,user_data,destroy);
}

hb_bool_t _impl_hb_font_get_h_extents(struct HarfbuzzIFace *Self, hb_font_t * font, hb_font_extents_t * extents) {
	return hb_font_get_h_extents(font,extents);
}

hb_bool_t _impl_hb_font_get_v_extents(struct HarfbuzzIFace *Self, hb_font_t * font, hb_font_extents_t * extents) {
	return hb_font_get_v_extents(font,extents);
}

hb_bool_t _impl_hb_font_get_nominal_glyph(struct HarfbuzzIFace *Self, hb_font_t * font, hb_codepoint_t unicode, hb_codepoint_t * glyph) {
	return hb_font_get_nominal_glyph(font,unicode,glyph);
}

hb_bool_t _impl_hb_font_get_variation_glyph(struct HarfbuzzIFace *Self, hb_font_t * font, hb_codepoint_t unicode, hb_codepoint_t variation_selector, hb_codepoint_t * glyph) {
	return hb_font_get_variation_glyph(font,unicode,variation_selector,glyph);
}

unsigned int _impl_hb_font_get_nominal_glyphs(struct HarfbuzzIFace *Self, hb_font_t * font, unsigned int count, const hb_codepoint_t * first_unicode, unsigned int unicode_stride, hb_codepoint_t * first_glyph, unsigned int glyph_stride) {
	return hb_font_get_nominal_glyphs(font,count,first_unicode,unicode_stride,first_glyph,glyph_stride);
}

hb_position_t _impl_hb_font_get_glyph_h_advance(struct HarfbuzzIFace *Self, hb_font_t * font, hb_codepoint_t glyph) {
	return hb_font_get_glyph_h_advance(font,glyph);
}

hb_position_t _impl_hb_font_get_glyph_v_advance(struct HarfbuzzIFace *Self, hb_font_t * font, hb_codepoint_t glyph) {
	return hb_font_get_glyph_v_advance(font,glyph);
}

void _impl_hb_font_get_glyph_h_advances(struct HarfbuzzIFace *Self, hb_font_t* font, unsigned int count, const hb_codepoint_t * first_glyph, unsigned glyph_stride, hb_position_t * first_advance, unsigned advance_stride) {
	hb_font_get_glyph_h_advances(font,count,first_glyph,glyph_stride,first_advance,advance_stride);
}

void _impl_hb_font_get_glyph_v_advances(struct HarfbuzzIFace *Self, hb_font_t* font, unsigned int count, const hb_codepoint_t * first_glyph, unsigned glyph_stride, hb_position_t * first_advance, unsigned advance_stride) {
	hb_font_get_glyph_v_advances(font,count,first_glyph,glyph_stride,first_advance,advance_stride);
}

hb_bool_t _impl_hb_font_get_glyph_h_origin(struct HarfbuzzIFace *Self, hb_font_t * font, hb_codepoint_t glyph, hb_position_t * x, hb_position_t * y) {
	return hb_font_get_glyph_h_origin(font,glyph,x,y);
}

hb_bool_t _impl_hb_font_get_glyph_v_origin(struct HarfbuzzIFace *Self, hb_font_t * font, hb_codepoint_t glyph, hb_position_t * x, hb_position_t * y) {
	return hb_font_get_glyph_v_origin(font,glyph,x,y);
}

hb_position_t _impl_hb_font_get_glyph_h_kerning(struct HarfbuzzIFace *Self, hb_font_t * font, hb_codepoint_t left_glyph, hb_codepoint_t right_glyph) {
	return hb_font_get_glyph_h_kerning(font,left_glyph,right_glyph);
}

hb_bool_t _impl_hb_font_get_glyph_extents(struct HarfbuzzIFace *Self, hb_font_t * font, hb_codepoint_t glyph, hb_glyph_extents_t * extents) {
	return hb_font_get_glyph_extents(font,glyph,extents);
}

hb_bool_t _impl_hb_font_get_glyph_contour_point(struct HarfbuzzIFace *Self, hb_font_t * font, hb_codepoint_t glyph, unsigned int point_index, hb_position_t * x, hb_position_t * y) {
	return hb_font_get_glyph_contour_point(font,glyph,point_index,x,y);
}

hb_bool_t _impl_hb_font_get_glyph_name(struct HarfbuzzIFace *Self, hb_font_t * font, hb_codepoint_t glyph, char * name, unsigned int size) {
	return hb_font_get_glyph_name(font,glyph,name,size);
}

hb_bool_t _impl_hb_font_get_glyph_from_name(struct HarfbuzzIFace *Self, hb_font_t * font, const char * name, int len, hb_codepoint_t * glyph) {
	return hb_font_get_glyph_from_name(font,name,len,glyph);
}

void _impl_hb_font_draw_glyph(struct HarfbuzzIFace *Self, hb_font_t * font, hb_codepoint_t glyph, hb_draw_funcs_t * dfuncs, void * draw_data) {
	hb_font_draw_glyph(font,glyph,dfuncs,draw_data);
}

void _impl_hb_font_paint_glyph(struct HarfbuzzIFace *Self, hb_font_t * font, hb_codepoint_t glyph, hb_paint_funcs_t * pfuncs, void * paint_data, unsigned int palette_index, hb_color_t foreground) {
	hb_font_paint_glyph(font,glyph,pfuncs,paint_data,palette_index,foreground);
}

hb_bool_t _impl_hb_font_get_glyph(struct HarfbuzzIFace *Self, hb_font_t * font, hb_codepoint_t unicode, hb_codepoint_t variation_selector, hb_codepoint_t * glyph) {
	return hb_font_get_glyph(font,unicode,variation_selector,glyph);
}

void _impl_hb_font_get_extents_for_direction(struct HarfbuzzIFace *Self, hb_font_t * font, hb_direction_t direction, hb_font_extents_t * extents) {
	hb_font_get_extents_for_direction(font,direction,extents);
}

void _impl_hb_font_get_glyph_advance_for_direction(struct HarfbuzzIFace *Self, hb_font_t * font, hb_codepoint_t glyph, hb_direction_t direction, hb_position_t * x, hb_position_t * y) {
	hb_font_get_glyph_advance_for_direction(font,glyph,direction,x,y);
}

void _impl_hb_font_get_glyph_advances_for_direction(struct HarfbuzzIFace *Self, hb_font_t* font, hb_direction_t direction, unsigned int count, const hb_codepoint_t * first_glyph, unsigned glyph_stride, hb_position_t * first_advance, unsigned advance_stride) {
	hb_font_get_glyph_advances_for_direction(font,direction,count,first_glyph,glyph_stride,first_advance,advance_stride);
}

void _impl_hb_font_get_glyph_origin_for_direction(struct HarfbuzzIFace *Self, hb_font_t * font, hb_codepoint_t glyph, hb_direction_t direction, hb_position_t * x, hb_position_t * y) {
	hb_font_get_glyph_origin_for_direction(font,glyph,direction,x,y);
}

void _impl_hb_font_add_glyph_origin_for_direction(struct HarfbuzzIFace *Self, hb_font_t * font, hb_codepoint_t glyph, hb_direction_t direction, hb_position_t * x, hb_position_t * y) {
	hb_font_add_glyph_origin_for_direction(font,glyph,direction,x,y);
}

void _impl_hb_font_subtract_glyph_origin_for_direction(struct HarfbuzzIFace *Self, hb_font_t * font, hb_codepoint_t glyph, hb_direction_t direction, hb_position_t * x, hb_position_t * y) {
	hb_font_subtract_glyph_origin_for_direction(font,glyph,direction,x,y);
}

void _impl_hb_font_get_glyph_kerning_for_direction(struct HarfbuzzIFace *Self, hb_font_t * font, hb_codepoint_t first_glyph, hb_codepoint_t second_glyph, hb_direction_t direction, hb_position_t * x, hb_position_t * y) {
	hb_font_get_glyph_kerning_for_direction(font,first_glyph,second_glyph,direction,x,y);
}

hb_bool_t _impl_hb_font_get_glyph_extents_for_origin(struct HarfbuzzIFace *Self, hb_font_t * font, hb_codepoint_t glyph, hb_direction_t direction, hb_glyph_extents_t * extents) {
	return hb_font_get_glyph_extents_for_origin(font,glyph,direction,extents);
}

hb_bool_t _impl_hb_font_get_glyph_contour_point_for_origin(struct HarfbuzzIFace *Self, hb_font_t * font, hb_codepoint_t glyph, unsigned int point_index, hb_direction_t direction, hb_position_t * x, hb_position_t * y) {
	return hb_font_get_glyph_contour_point_for_origin(font,glyph,point_index,direction,x,y);
}

void _impl_hb_font_glyph_to_string(struct HarfbuzzIFace *Self, hb_font_t * font, hb_codepoint_t glyph, char * s, unsigned int size) {
	hb_font_glyph_to_string(font,glyph,s,size);
}

hb_bool_t _impl_hb_font_glyph_from_string(struct HarfbuzzIFace *Self, hb_font_t * font, const char * s, int len, hb_codepoint_t * glyph) {
	return hb_font_glyph_from_string(font,s,len,glyph);
}

hb_font_t * _impl_hb_font_create(struct HarfbuzzIFace *Self, hb_face_t * face) {
	return hb_font_create(face);
}

hb_font_t * _impl_hb_font_create_sub_font(struct HarfbuzzIFace *Self, hb_font_t * parent) {
	return hb_font_create_sub_font(parent);
}

hb_font_t * _impl_hb_font_get_empty(struct HarfbuzzIFace *Self) {
	return hb_font_get_empty();
}

hb_font_t * _impl_hb_font_reference(struct HarfbuzzIFace *Self, hb_font_t * font) {
	return hb_font_reference(font);
}

void _impl_hb_font_destroy(struct HarfbuzzIFace *Self, hb_font_t * font) {
	hb_font_destroy(font);
}

hb_bool_t _impl_hb_font_set_user_data(struct HarfbuzzIFace *Self, hb_font_t * font, hb_user_data_key_t * key, void * data, hb_destroy_func_t destroy, hb_bool_t replace) {
	return hb_font_set_user_data(font,key,data,destroy,replace);
}

void * _impl_hb_font_get_user_data(struct HarfbuzzIFace *Self, const hb_font_t * font, hb_user_data_key_t * key) {
	return hb_font_get_user_data(font,key);
}

void _impl_hb_font_make_immutable(struct HarfbuzzIFace *Self, hb_font_t * font) {
	hb_font_make_immutable(font);
}

hb_bool_t _impl_hb_font_is_immutable(struct HarfbuzzIFace *Self, hb_font_t * font) {
	return hb_font_is_immutable(font);
}

unsigned int _impl_hb_font_get_serial(struct HarfbuzzIFace *Self, hb_font_t * font) {
	return hb_font_get_serial(font);
}

void _impl_hb_font_changed(struct HarfbuzzIFace *Self, hb_font_t * font) {
	hb_font_changed(font);
}

void _impl_hb_font_set_parent(struct HarfbuzzIFace *Self, hb_font_t * font, hb_font_t * parent) {
	hb_font_set_parent(font,parent);
}

hb_font_t * _impl_hb_font_get_parent(struct HarfbuzzIFace *Self, hb_font_t * font) {
	return hb_font_get_parent(font);
}

void _impl_hb_font_set_face(struct HarfbuzzIFace *Self, hb_font_t * font, hb_face_t * face) {
	hb_font_set_face(font,face);
}

hb_face_t * _impl_hb_font_get_face(struct HarfbuzzIFace *Self, hb_font_t * font) {
	return hb_font_get_face(font);
}

void _impl_hb_font_set_funcs(struct HarfbuzzIFace *Self, hb_font_t * font, hb_font_funcs_t * klass, void * font_data, hb_destroy_func_t destroy) {
	hb_font_set_funcs(font,klass,font_data,destroy);
}

void _impl_hb_font_set_funcs_data(struct HarfbuzzIFace *Self, hb_font_t * font, void * font_data, hb_destroy_func_t destroy) {
	hb_font_set_funcs_data(font,font_data,destroy);
}

void _impl_hb_font_set_scale(struct HarfbuzzIFace *Self, hb_font_t * font, int x_scale, int y_scale) {
	hb_font_set_scale(font,x_scale,y_scale);
}

void _impl_hb_font_get_scale(struct HarfbuzzIFace *Self, hb_font_t * font, int * x_scale, int * y_scale) {
	hb_font_get_scale(font,x_scale,y_scale);
}

void _impl_hb_font_set_ppem(struct HarfbuzzIFace *Self, hb_font_t * font, unsigned int x_ppem, unsigned int y_ppem) {
	hb_font_set_ppem(font,x_ppem,y_ppem);
}

void _impl_hb_font_get_ppem(struct HarfbuzzIFace *Self, hb_font_t * font, unsigned int * x_ppem, unsigned int * y_ppem) {
	hb_font_get_ppem(font,x_ppem,y_ppem);
}

void _impl_hb_font_set_ptem(struct HarfbuzzIFace *Self, hb_font_t * font, float ptem) {
	hb_font_set_ptem(font,ptem);
}

float _impl_hb_font_get_ptem(struct HarfbuzzIFace *Self, hb_font_t * font) {
	return hb_font_get_ptem(font);
}

void _impl_hb_font_set_synthetic_bold(struct HarfbuzzIFace *Self, hb_font_t * font, float x_embolden, float y_embolden, hb_bool_t in_place) {
	hb_font_set_synthetic_bold(font,x_embolden,y_embolden,in_place);
}

void _impl_hb_font_get_synthetic_bold(struct HarfbuzzIFace *Self, hb_font_t * font, float * x_embolden, float * y_embolden, hb_bool_t * in_place) {
	hb_font_get_synthetic_bold(font,x_embolden,y_embolden,in_place);
}

void _impl_hb_font_set_synthetic_slant(struct HarfbuzzIFace *Self, hb_font_t * font, float slant) {
	hb_font_set_synthetic_slant(font,slant);
}

float _impl_hb_font_get_synthetic_slant(struct HarfbuzzIFace *Self, hb_font_t * font) {
	return hb_font_get_synthetic_slant(font);
}

void _impl_hb_font_set_variations(struct HarfbuzzIFace *Self, hb_font_t * font, const hb_variation_t * variations, unsigned int variations_length) {
	hb_font_set_variations(font,variations,variations_length);
}

void _impl_hb_font_set_variation(struct HarfbuzzIFace *Self, hb_font_t * font, hb_tag_t tag, float value) {
	hb_font_set_variation(font,tag,value);
}

void _impl_hb_font_set_var_coords_design(struct HarfbuzzIFace *Self, hb_font_t * font, const float * coords, unsigned int coords_length) {
	hb_font_set_var_coords_design(font,coords,coords_length);
}

const float * _impl_hb_font_get_var_coords_design(struct HarfbuzzIFace *Self, hb_font_t * font, unsigned int * length) {
	return hb_font_get_var_coords_design(font,length);
}

void _impl_hb_font_set_var_coords_normalized(struct HarfbuzzIFace *Self, hb_font_t * font, const int * coords, unsigned int coords_length) {
	hb_font_set_var_coords_normalized(font,coords,coords_length);
}

const int * _impl_hb_font_get_var_coords_normalized(struct HarfbuzzIFace *Self, hb_font_t * font, unsigned int * length) {
	return hb_font_get_var_coords_normalized(font,length);
}

void _impl_hb_font_set_var_named_instance(struct HarfbuzzIFace *Self, hb_font_t * font, unsigned int instance_index) {
	hb_font_set_var_named_instance(font,instance_index);
}

unsigned int _impl_hb_font_get_var_named_instance(struct HarfbuzzIFace *Self, hb_font_t * font) {
	return hb_font_get_var_named_instance(font);
}

hb_face_t * _impl_hb_ft_face_create(struct HarfbuzzIFace *Self, FT_Face ft_face, hb_destroy_func_t destroy) {
	return hb_ft_face_create(ft_face,destroy);
}

hb_face_t * _impl_hb_ft_face_create_cached(struct HarfbuzzIFace *Self, FT_Face ft_face) {
	return hb_ft_face_create_cached(ft_face);
}

hb_face_t * _impl_hb_ft_face_create_referenced(struct HarfbuzzIFace *Self, FT_Face ft_face) {
	return hb_ft_face_create_referenced(ft_face);
}

hb_font_t * _impl_hb_ft_font_create(struct HarfbuzzIFace *Self, FT_Face ft_face, hb_destroy_func_t destroy) {
	return hb_ft_font_create(ft_face,destroy);
}

hb_font_t * _impl_hb_ft_font_create_referenced(struct HarfbuzzIFace *Self, FT_Face ft_face) {
	return hb_ft_font_create_referenced(ft_face);
}

FT_Face _impl_hb_ft_font_get_face(struct HarfbuzzIFace *Self, hb_font_t * font) {
	return hb_ft_font_get_face(font);
}

FT_Face _impl_hb_ft_font_lock_face(struct HarfbuzzIFace *Self, hb_font_t * font) {
	return hb_ft_font_lock_face(font);
}

void _impl_hb_ft_font_unlock_face(struct HarfbuzzIFace *Self, hb_font_t * font) {
	hb_ft_font_unlock_face(font);
}

void _impl_hb_ft_font_set_load_flags(struct HarfbuzzIFace *Self, hb_font_t * font, int load_flags) {
	hb_ft_font_set_load_flags(font,load_flags);
}

int _impl_hb_ft_font_get_load_flags(struct HarfbuzzIFace *Self, hb_font_t * font) {
	return hb_ft_font_get_load_flags(font);
}

void _impl_hb_ft_font_changed(struct HarfbuzzIFace *Self, hb_font_t * font) {
	hb_ft_font_changed(font);
}

hb_bool_t _impl_hb_ft_hb_font_changed(struct HarfbuzzIFace *Self, hb_font_t * font) {
	return hb_ft_hb_font_changed(font);
}

void _impl_hb_ft_font_set_funcs(struct HarfbuzzIFace *Self, hb_font_t * font) {
	hb_ft_font_set_funcs(font);
}

hb_map_t * _impl_hb_map_create(struct HarfbuzzIFace *Self) {
	return hb_map_create();
}

hb_map_t * _impl_hb_map_get_empty(struct HarfbuzzIFace *Self) {
	return hb_map_get_empty();
}

hb_map_t * _impl_hb_map_reference(struct HarfbuzzIFace *Self, hb_map_t * map) {
	return hb_map_reference(map);
}

void _impl_hb_map_destroy(struct HarfbuzzIFace *Self, hb_map_t * map) {
	hb_map_destroy(map);
}

hb_bool_t _impl_hb_map_set_user_data(struct HarfbuzzIFace *Self, hb_map_t * map, hb_user_data_key_t * key, void * data, hb_destroy_func_t destroy, hb_bool_t replace) {
	return hb_map_set_user_data(map,key,data,destroy,replace);
}

void * _impl_hb_map_get_user_data(struct HarfbuzzIFace *Self, const hb_map_t * map, hb_user_data_key_t * key) {
	return hb_map_get_user_data(map,key);
}

hb_bool_t _impl_hb_map_allocation_successful(struct HarfbuzzIFace *Self, const hb_map_t * map) {
	return hb_map_allocation_successful(map);
}

hb_map_t * _impl_hb_map_copy(struct HarfbuzzIFace *Self, const hb_map_t * map) {
	return hb_map_copy(map);
}

void _impl_hb_map_clear(struct HarfbuzzIFace *Self, hb_map_t * map) {
	hb_map_clear(map);
}

hb_bool_t _impl_hb_map_is_empty(struct HarfbuzzIFace *Self, const hb_map_t * map) {
	return hb_map_is_empty(map);
}

unsigned int _impl_hb_map_get_population(struct HarfbuzzIFace *Self, const hb_map_t * map) {
	return hb_map_get_population(map);
}

hb_bool_t _impl_hb_map_is_equal(struct HarfbuzzIFace *Self, const hb_map_t * map, const hb_map_t * other) {
	return hb_map_is_equal(map,other);
}

unsigned int _impl_hb_map_hash(struct HarfbuzzIFace *Self, const hb_map_t * map) {
	return hb_map_hash(map);
}

void _impl_hb_map_set(struct HarfbuzzIFace *Self, hb_map_t * map, hb_codepoint_t key, hb_codepoint_t value) {
	hb_map_set(map,key,value);
}

hb_codepoint_t _impl_hb_map_get(struct HarfbuzzIFace *Self, const hb_map_t * map, hb_codepoint_t key) {
	return hb_map_get(map,key);
}

void _impl_hb_map_del(struct HarfbuzzIFace *Self, hb_map_t * map, hb_codepoint_t key) {
	hb_map_del(map,key);
}

hb_bool_t _impl_hb_map_has(struct HarfbuzzIFace *Self, const hb_map_t * map, hb_codepoint_t key) {
	return hb_map_has(map,key);
}

void _impl_hb_map_update(struct HarfbuzzIFace *Self, hb_map_t * map, const hb_map_t * other) {
	hb_map_update(map,other);
}

hb_bool_t _impl_hb_map_next(struct HarfbuzzIFace *Self, const hb_map_t * map, int * idx, hb_codepoint_t * key, hb_codepoint_t * value) {
	return hb_map_next(map,idx,key,value);
}

void _impl_hb_map_keys(struct HarfbuzzIFace *Self, const hb_map_t * map, hb_set_t * keys) {
	hb_map_keys(map,keys);
}

void _impl_hb_map_values(struct HarfbuzzIFace *Self, const hb_map_t * map, hb_set_t * values) {
	hb_map_values(map,values);
}

hb_bool_t _impl_hb_ot_color_has_palettes(struct HarfbuzzIFace *Self, hb_face_t * face) {
	return hb_ot_color_has_palettes(face);
}

unsigned int _impl_hb_ot_color_palette_get_count(struct HarfbuzzIFace *Self, hb_face_t * face) {
	return hb_ot_color_palette_get_count(face);
}

hb_ot_name_id_t _impl_hb_ot_color_palette_get_name_id(struct HarfbuzzIFace *Self, hb_face_t * face, unsigned int palette_index) {
	return hb_ot_color_palette_get_name_id(face,palette_index);
}

hb_ot_name_id_t _impl_hb_ot_color_palette_color_get_name_id(struct HarfbuzzIFace *Self, hb_face_t * face, unsigned int color_index) {
	return hb_ot_color_palette_color_get_name_id(face,color_index);
}

hb_ot_color_palette_flags_t _impl_hb_ot_color_palette_get_flags(struct HarfbuzzIFace *Self, hb_face_t * face, unsigned int palette_index) {
	return hb_ot_color_palette_get_flags(face,palette_index);
}

unsigned int _impl_hb_ot_color_palette_get_colors(struct HarfbuzzIFace *Self, hb_face_t * face, unsigned int palette_index, unsigned int start_offset, unsigned int * color_count, hb_color_t * colors) {
	return hb_ot_color_palette_get_colors(face,palette_index,start_offset,color_count,colors);
}

hb_bool_t _impl_hb_ot_color_has_layers(struct HarfbuzzIFace *Self, hb_face_t * face) {
	return hb_ot_color_has_layers(face);
}

unsigned int _impl_hb_ot_color_glyph_get_layers(struct HarfbuzzIFace *Self, hb_face_t * face, hb_codepoint_t glyph, unsigned int start_offset, unsigned int * layer_count, hb_ot_color_layer_t * layers) {
	return hb_ot_color_glyph_get_layers(face,glyph,start_offset,layer_count,layers);
}

hb_bool_t _impl_hb_ot_color_has_paint(struct HarfbuzzIFace *Self, hb_face_t * face) {
	return hb_ot_color_has_paint(face);
}

hb_bool_t _impl_hb_ot_color_glyph_has_paint(struct HarfbuzzIFace *Self, hb_face_t * face, hb_codepoint_t glyph) {
	return hb_ot_color_glyph_has_paint(face,glyph);
}

hb_bool_t _impl_hb_ot_color_has_svg(struct HarfbuzzIFace *Self, hb_face_t * face) {
	return hb_ot_color_has_svg(face);
}

hb_blob_t * _impl_hb_ot_color_glyph_reference_svg(struct HarfbuzzIFace *Self, hb_face_t * face, hb_codepoint_t glyph) {
	return hb_ot_color_glyph_reference_svg(face,glyph);
}

hb_bool_t _impl_hb_ot_color_has_png(struct HarfbuzzIFace *Self, hb_face_t * face) {
	return hb_ot_color_has_png(face);
}

hb_blob_t * _impl_hb_ot_color_glyph_reference_png(struct HarfbuzzIFace *Self, hb_font_t * font, hb_codepoint_t glyph) {
	return hb_ot_color_glyph_reference_png(font,glyph);
}

hb_bool_t _impl_hb_ot_layout_table_choose_script(struct HarfbuzzIFace *Self, hb_face_t * face, hb_tag_t table_tag, const hb_tag_t * script_tags, unsigned int * script_index, hb_tag_t * chosen_script) {
	return hb_ot_layout_table_choose_script(face,table_tag,script_tags,script_index,chosen_script);
}

hb_bool_t _impl_hb_ot_layout_script_find_language(struct HarfbuzzIFace *Self, hb_face_t * face, hb_tag_t table_tag, unsigned int script_index, hb_tag_t language_tag, unsigned int * language_index) {
	return hb_ot_layout_script_find_language(face,table_tag,script_index,language_tag,language_index);
}

void _impl_hb_ot_tags_from_script(struct HarfbuzzIFace *Self, hb_script_t script, hb_tag_t * script_tag_1, hb_tag_t * script_tag_2) {
	hb_ot_tags_from_script(script,script_tag_1,script_tag_2);
}

hb_tag_t _impl_hb_ot_tag_from_language(struct HarfbuzzIFace *Self, hb_language_t language) {
	return hb_ot_tag_from_language(language);
}

unsigned int _impl_hb_ot_var_get_axes(struct HarfbuzzIFace *Self, hb_face_t * face, unsigned int start_offset, unsigned int * axes_count, hb_ot_var_axis_t * axes_array) {
	return hb_ot_var_get_axes(face,start_offset,axes_count,axes_array);
}

hb_bool_t _impl_hb_ot_var_find_axis(struct HarfbuzzIFace *Self, hb_face_t * face, hb_tag_t axis_tag, unsigned int * axis_index, hb_ot_var_axis_t * axis_info) {
	return hb_ot_var_find_axis(face,axis_tag,axis_index,axis_info);
}

void _impl_hb_ot_font_set_funcs(struct HarfbuzzIFace *Self, hb_font_t * font) {
	hb_ot_font_set_funcs(font);
}

void _impl_hb_ot_tags_from_script_and_language(struct HarfbuzzIFace *Self, hb_script_t script, hb_language_t language, unsigned int * script_count, hb_tag_t * script_tags, unsigned int * language_count, hb_tag_t * language_tags) {
	hb_ot_tags_from_script_and_language(script,language,script_count,script_tags,language_count,language_tags);
}

hb_script_t _impl_hb_ot_tag_to_script(struct HarfbuzzIFace *Self, hb_tag_t tag) {
	return hb_ot_tag_to_script(tag);
}

hb_language_t _impl_hb_ot_tag_to_language(struct HarfbuzzIFace *Self, hb_tag_t tag) {
	return hb_ot_tag_to_language(tag);
}

void _impl_hb_ot_tags_to_script_and_language(struct HarfbuzzIFace *Self, hb_tag_t script_tag, hb_tag_t language_tag, hb_script_t * script, hb_language_t * language) {
	hb_ot_tags_to_script_and_language(script_tag,language_tag,script,language);
}

hb_bool_t _impl_hb_ot_layout_has_glyph_classes(struct HarfbuzzIFace *Self, hb_face_t * face) {
	return hb_ot_layout_has_glyph_classes(face);
}

hb_ot_layout_glyph_class_t _impl_hb_ot_layout_get_glyph_class(struct HarfbuzzIFace *Self, hb_face_t * face, hb_codepoint_t glyph) {
	return hb_ot_layout_get_glyph_class(face,glyph);
}

void _impl_hb_ot_layout_get_glyphs_in_class(struct HarfbuzzIFace *Self, hb_face_t * face, hb_ot_layout_glyph_class_t klass, hb_set_t * glyphs) {
	hb_ot_layout_get_glyphs_in_class(face,klass,glyphs);
}

unsigned int _impl_hb_ot_layout_get_attach_points(struct HarfbuzzIFace *Self, hb_face_t * face, hb_codepoint_t glyph, unsigned int start_offset, unsigned int * point_count, unsigned int * point_array) {
	return hb_ot_layout_get_attach_points(face,glyph,start_offset,point_count,point_array);
}

unsigned int _impl_hb_ot_layout_get_ligature_carets(struct HarfbuzzIFace *Self, hb_font_t * font, hb_direction_t direction, hb_codepoint_t glyph, unsigned int start_offset, unsigned int * caret_count, hb_position_t * caret_array) {
	return hb_ot_layout_get_ligature_carets(font,direction,glyph,start_offset,caret_count,caret_array);
}

unsigned int _impl_hb_ot_layout_table_get_script_tags(struct HarfbuzzIFace *Self, hb_face_t * face, hb_tag_t table_tag, unsigned int start_offset, unsigned int * script_count, hb_tag_t * script_tags) {
	return hb_ot_layout_table_get_script_tags(face,table_tag,start_offset,script_count,script_tags);
}

hb_bool_t _impl_hb_ot_layout_table_find_script(struct HarfbuzzIFace *Self, hb_face_t * face, hb_tag_t table_tag, hb_tag_t script_tag, unsigned int * script_index) {
	return hb_ot_layout_table_find_script(face,table_tag,script_tag,script_index);
}

hb_bool_t _impl_hb_ot_layout_table_select_script(struct HarfbuzzIFace *Self, hb_face_t * face, hb_tag_t table_tag, unsigned int script_count, const hb_tag_t * script_tags, unsigned int * script_index, hb_tag_t * chosen_script) {
	return hb_ot_layout_table_select_script(face,table_tag,script_count,script_tags,script_index,chosen_script);
}

unsigned int _impl_hb_ot_layout_table_get_feature_tags(struct HarfbuzzIFace *Self, hb_face_t * face, hb_tag_t table_tag, unsigned int start_offset, unsigned int * feature_count, hb_tag_t * feature_tags) {
	return hb_ot_layout_table_get_feature_tags(face,table_tag,start_offset,feature_count,feature_tags);
}

unsigned int _impl_hb_ot_layout_script_get_language_tags(struct HarfbuzzIFace *Self, hb_face_t * face, hb_tag_t table_tag, unsigned int script_index, unsigned int start_offset, unsigned int * language_count, hb_tag_t * language_tags) {
	return hb_ot_layout_script_get_language_tags(face,table_tag,script_index,start_offset,language_count,language_tags);
}

hb_bool_t _impl_hb_ot_layout_script_select_language(struct HarfbuzzIFace *Self, hb_face_t * face, hb_tag_t table_tag, unsigned int script_index, unsigned int language_count, const hb_tag_t * language_tags, unsigned int * language_index) {
	return hb_ot_layout_script_select_language(face,table_tag,script_index,language_count,language_tags,language_index);
}

hb_bool_t _impl_hb_ot_layout_script_select_language2(struct HarfbuzzIFace *Self, hb_face_t * face, hb_tag_t table_tag, unsigned int script_index, unsigned int language_count, const hb_tag_t * language_tags, unsigned int * language_index, hb_tag_t * chosen_language) {
	return hb_ot_layout_script_select_language2(face,table_tag,script_index,language_count,language_tags,language_index,chosen_language);
}

hb_bool_t _impl_hb_ot_layout_language_get_required_feature_index(struct HarfbuzzIFace *Self, hb_face_t * face, hb_tag_t table_tag, unsigned int script_index, unsigned int language_index, unsigned int * feature_index) {
	return hb_ot_layout_language_get_required_feature_index(face,table_tag,script_index,language_index,feature_index);
}

hb_bool_t _impl_hb_ot_layout_language_get_required_feature(struct HarfbuzzIFace *Self, hb_face_t * face, hb_tag_t table_tag, unsigned int script_index, unsigned int language_index, unsigned int * feature_index, hb_tag_t * feature_tag) {
	return hb_ot_layout_language_get_required_feature(face,table_tag,script_index,language_index,feature_index,feature_tag);
}

unsigned int _impl_hb_ot_layout_language_get_feature_indexes(struct HarfbuzzIFace *Self, hb_face_t * face, hb_tag_t table_tag, unsigned int script_index, unsigned int language_index, unsigned int start_offset, unsigned int * feature_count, unsigned int * feature_indexes) {
	return hb_ot_layout_language_get_feature_indexes(face,table_tag,script_index,language_index,start_offset,feature_count,feature_indexes);
}

unsigned int _impl_hb_ot_layout_language_get_feature_tags(struct HarfbuzzIFace *Self, hb_face_t * face, hb_tag_t table_tag, unsigned int script_index, unsigned int language_index, unsigned int start_offset, unsigned int * feature_count, hb_tag_t * feature_tags) {
	return hb_ot_layout_language_get_feature_tags(face,table_tag,script_index,language_index,start_offset,feature_count,feature_tags);
}

hb_bool_t _impl_hb_ot_layout_language_find_feature(struct HarfbuzzIFace *Self, hb_face_t * face, hb_tag_t table_tag, unsigned int script_index, unsigned int language_index, hb_tag_t feature_tag, unsigned int * feature_index) {
	return hb_ot_layout_language_find_feature(face,table_tag,script_index,language_index,feature_tag,feature_index);
}

unsigned int _impl_hb_ot_layout_feature_get_lookups(struct HarfbuzzIFace *Self, hb_face_t * face, hb_tag_t table_tag, unsigned int feature_index, unsigned int start_offset, unsigned int * lookup_count, unsigned int * lookup_indexes) {
	return hb_ot_layout_feature_get_lookups(face,table_tag,feature_index,start_offset,lookup_count,lookup_indexes);
}

unsigned int _impl_hb_ot_layout_table_get_lookup_count(struct HarfbuzzIFace *Self, hb_face_t * face, hb_tag_t table_tag) {
	return hb_ot_layout_table_get_lookup_count(face,table_tag);
}

void _impl_hb_ot_layout_collect_features(struct HarfbuzzIFace *Self, hb_face_t * face, hb_tag_t table_tag, const hb_tag_t * scripts, const hb_tag_t * languages, const hb_tag_t * features, hb_set_t * feature_indexes) {
	hb_ot_layout_collect_features(face,table_tag,scripts,languages,features,feature_indexes);
}

void _impl_hb_ot_layout_collect_features_map(struct HarfbuzzIFace *Self, hb_face_t * face, hb_tag_t table_tag, unsigned script_index, unsigned language_index, hb_map_t * feature_map) {
	hb_ot_layout_collect_features_map(face,table_tag,script_index,language_index,feature_map);
}

void _impl_hb_ot_layout_collect_lookups(struct HarfbuzzIFace *Self, hb_face_t * face, hb_tag_t table_tag, const hb_tag_t * scripts, const hb_tag_t * languages, const hb_tag_t * features, hb_set_t * lookup_indexes) {
	hb_ot_layout_collect_lookups(face,table_tag,scripts,languages,features,lookup_indexes);
}

void _impl_hb_ot_layout_lookup_collect_glyphs(struct HarfbuzzIFace *Self, hb_face_t * face, hb_tag_t table_tag, unsigned int lookup_index, hb_set_t * glyphs_before, hb_set_t * glyphs_input, hb_set_t * glyphs_after, hb_set_t * glyphs_output) {
	hb_ot_layout_lookup_collect_glyphs(face,table_tag,lookup_index,glyphs_before,glyphs_input,glyphs_after,glyphs_output);
}

hb_bool_t _impl_hb_ot_layout_table_find_feature_variations(struct HarfbuzzIFace *Self, hb_face_t * face, hb_tag_t table_tag, const int * coords, unsigned int num_coords, unsigned int * variations_index) {
	return hb_ot_layout_table_find_feature_variations(face,table_tag,coords,num_coords,variations_index);
}

unsigned int _impl_hb_ot_layout_feature_with_variations_get_lookups(struct HarfbuzzIFace *Self, hb_face_t * face, hb_tag_t table_tag, unsigned int feature_index, unsigned int variations_index, unsigned int start_offset, unsigned int * lookup_count, unsigned int * lookup_indexes) {
	return hb_ot_layout_feature_with_variations_get_lookups(face,table_tag,feature_index,variations_index,start_offset,lookup_count,lookup_indexes);
}

hb_bool_t _impl_hb_ot_layout_has_substitution(struct HarfbuzzIFace *Self, hb_face_t * face) {
	return hb_ot_layout_has_substitution(face);
}

unsigned _impl_hb_ot_layout_lookup_get_glyph_alternates(struct HarfbuzzIFace *Self, hb_face_t * face, unsigned lookup_index, hb_codepoint_t glyph, unsigned start_offset, unsigned * alternate_count, hb_codepoint_t * alternate_glyphs) {
	return hb_ot_layout_lookup_get_glyph_alternates(face,lookup_index,glyph,start_offset,alternate_count,alternate_glyphs);
}

hb_bool_t _impl_hb_ot_layout_lookup_would_substitute(struct HarfbuzzIFace *Self, hb_face_t * face, unsigned int lookup_index, const hb_codepoint_t * glyphs, unsigned int glyphs_length, hb_bool_t zero_context) {
	return hb_ot_layout_lookup_would_substitute(face,lookup_index,glyphs,glyphs_length,zero_context);
}

void _impl_hb_ot_layout_lookup_substitute_closure(struct HarfbuzzIFace *Self, hb_face_t * face, unsigned int lookup_index, hb_set_t * glyphs) {
	hb_ot_layout_lookup_substitute_closure(face,lookup_index,glyphs);
}

void _impl_hb_ot_layout_lookups_substitute_closure(struct HarfbuzzIFace *Self, hb_face_t * face, const hb_set_t * lookups, hb_set_t * glyphs) {
	hb_ot_layout_lookups_substitute_closure(face,lookups,glyphs);
}

hb_bool_t _impl_hb_ot_layout_has_positioning(struct HarfbuzzIFace *Self, hb_face_t * face) {
	return hb_ot_layout_has_positioning(face);
}

hb_bool_t _impl_hb_ot_layout_get_size_params(struct HarfbuzzIFace *Self, hb_face_t * face, unsigned int * design_size, unsigned int * subfamily_id, hb_ot_name_id_t * subfamily_name_id, unsigned int * range_start, unsigned int * range_end) {
	return hb_ot_layout_get_size_params(face,design_size,subfamily_id,subfamily_name_id,range_start,range_end);
}

hb_position_t _impl_hb_ot_layout_lookup_get_optical_bound(struct HarfbuzzIFace *Self, hb_font_t * font, unsigned lookup_index, hb_direction_t direction, hb_codepoint_t glyph) {
	return hb_ot_layout_lookup_get_optical_bound(font,lookup_index,direction,glyph);
}

hb_bool_t _impl_hb_ot_layout_feature_get_name_ids(struct HarfbuzzIFace *Self, hb_face_t * face, hb_tag_t table_tag, unsigned int feature_index, hb_ot_name_id_t * label_id, hb_ot_name_id_t * tooltip_id, hb_ot_name_id_t * sample_id, unsigned int * num_named_parameters, hb_ot_name_id_t * first_param_id) {
	return hb_ot_layout_feature_get_name_ids(face,table_tag,feature_index,label_id,tooltip_id,sample_id,num_named_parameters,first_param_id);
}

unsigned int _impl_hb_ot_layout_feature_get_characters(struct HarfbuzzIFace *Self, hb_face_t * face, hb_tag_t table_tag, unsigned int feature_index, unsigned int start_offset, unsigned int * char_count, hb_codepoint_t * characters) {
	return hb_ot_layout_feature_get_characters(face,table_tag,feature_index,start_offset,char_count,characters);
}

hb_bool_t _impl_hb_ot_layout_get_font_extents(struct HarfbuzzIFace *Self, hb_font_t * font, hb_direction_t direction, hb_tag_t script_tag, hb_tag_t language_tag, hb_font_extents_t * extents) {
	return hb_ot_layout_get_font_extents(font,direction,script_tag,language_tag,extents);
}

hb_bool_t _impl_hb_ot_layout_get_font_extents2(struct HarfbuzzIFace *Self, hb_font_t * font, hb_direction_t direction, hb_script_t script, hb_language_t language, hb_font_extents_t * extents) {
	return hb_ot_layout_get_font_extents2(font,direction,script,language,extents);
}

hb_ot_layout_baseline_tag_t _impl_hb_ot_layout_get_horizontal_baseline_tag_for_script(struct HarfbuzzIFace *Self, hb_script_t script) {
	return hb_ot_layout_get_horizontal_baseline_tag_for_script(script);
}

hb_bool_t _impl_hb_ot_layout_get_baseline(struct HarfbuzzIFace *Self, hb_font_t * font, hb_ot_layout_baseline_tag_t baseline_tag, hb_direction_t direction, hb_tag_t script_tag, hb_tag_t language_tag, hb_position_t * coord) {
	return hb_ot_layout_get_baseline(font,baseline_tag,direction,script_tag,language_tag,coord);
}

hb_bool_t _impl_hb_ot_layout_get_baseline2(struct HarfbuzzIFace *Self, hb_font_t * font, hb_ot_layout_baseline_tag_t baseline_tag, hb_direction_t direction, hb_script_t script, hb_language_t language, hb_position_t * coord) {
	return hb_ot_layout_get_baseline2(font,baseline_tag,direction,script,language,coord);
}

void _impl_hb_ot_layout_get_baseline_with_fallback(struct HarfbuzzIFace *Self, hb_font_t * font, hb_ot_layout_baseline_tag_t baseline_tag, hb_direction_t direction, hb_tag_t script_tag, hb_tag_t language_tag, hb_position_t * coord) {
	hb_ot_layout_get_baseline_with_fallback(font,baseline_tag,direction,script_tag,language_tag,coord);
}

void _impl_hb_ot_layout_get_baseline_with_fallback2(struct HarfbuzzIFace *Self, hb_font_t * font, hb_ot_layout_baseline_tag_t baseline_tag, hb_direction_t direction, hb_script_t script, hb_language_t language, hb_position_t * coord) {
	hb_ot_layout_get_baseline_with_fallback2(font,baseline_tag,direction,script,language,coord);
}

hb_bool_t _impl_hb_ot_math_has_data(struct HarfbuzzIFace *Self, hb_face_t * face) {
	return hb_ot_math_has_data(face);
}

hb_position_t _impl_hb_ot_math_get_constant(struct HarfbuzzIFace *Self, hb_font_t * font, hb_ot_math_constant_t constant) {
	return hb_ot_math_get_constant(font,constant);
}

hb_position_t _impl_hb_ot_math_get_glyph_italics_correction(struct HarfbuzzIFace *Self, hb_font_t * font, hb_codepoint_t glyph) {
	return hb_ot_math_get_glyph_italics_correction(font,glyph);
}

hb_position_t _impl_hb_ot_math_get_glyph_top_accent_attachment(struct HarfbuzzIFace *Self, hb_font_t * font, hb_codepoint_t glyph) {
	return hb_ot_math_get_glyph_top_accent_attachment(font,glyph);
}

hb_bool_t _impl_hb_ot_math_is_glyph_extended_shape(struct HarfbuzzIFace *Self, hb_face_t * face, hb_codepoint_t glyph) {
	return hb_ot_math_is_glyph_extended_shape(face,glyph);
}

hb_position_t _impl_hb_ot_math_get_glyph_kerning(struct HarfbuzzIFace *Self, hb_font_t * font, hb_codepoint_t glyph, hb_ot_math_kern_t kern, hb_position_t correction_height) {
	return hb_ot_math_get_glyph_kerning(font,glyph,kern,correction_height);
}

unsigned int _impl_hb_ot_math_get_glyph_kernings(struct HarfbuzzIFace *Self, hb_font_t * font, hb_codepoint_t glyph, hb_ot_math_kern_t kern, unsigned int start_offset, unsigned int * entries_count, hb_ot_math_kern_entry_t * kern_entries) {
	return hb_ot_math_get_glyph_kernings(font,glyph,kern,start_offset,entries_count,kern_entries);
}

unsigned int _impl_hb_ot_math_get_glyph_variants(struct HarfbuzzIFace *Self, hb_font_t * font, hb_codepoint_t glyph, hb_direction_t direction, unsigned int start_offset, unsigned int * variants_count, hb_ot_math_glyph_variant_t * variants) {
	return hb_ot_math_get_glyph_variants(font,glyph,direction,start_offset,variants_count,variants);
}

hb_position_t _impl_hb_ot_math_get_min_connector_overlap(struct HarfbuzzIFace *Self, hb_font_t * font, hb_direction_t direction) {
	return hb_ot_math_get_min_connector_overlap(font,direction);
}

unsigned int _impl_hb_ot_math_get_glyph_assembly(struct HarfbuzzIFace *Self, hb_font_t * font, hb_codepoint_t glyph, hb_direction_t direction, unsigned int start_offset, unsigned int * parts_count, hb_ot_math_glyph_part_t * parts, hb_position_t * italics_correction) {
	return hb_ot_math_get_glyph_assembly(font,glyph,direction,start_offset,parts_count,parts,italics_correction);
}

unsigned int _impl_hb_ot_meta_get_entry_tags(struct HarfbuzzIFace *Self, hb_face_t * face, unsigned int start_offset, unsigned int * entries_count, hb_ot_meta_tag_t * entries) {
	return hb_ot_meta_get_entry_tags(face,start_offset,entries_count,entries);
}

hb_blob_t * _impl_hb_ot_meta_reference_entry(struct HarfbuzzIFace *Self, hb_face_t * face, hb_ot_meta_tag_t meta_tag) {
	return hb_ot_meta_reference_entry(face,meta_tag);
}

hb_bool_t _impl_hb_ot_metrics_get_position(struct HarfbuzzIFace *Self, hb_font_t * font, hb_ot_metrics_tag_t metrics_tag, hb_position_t * position) {
	return hb_ot_metrics_get_position(font,metrics_tag,position);
}

void _impl_hb_ot_metrics_get_position_with_fallback(struct HarfbuzzIFace *Self, hb_font_t * font, hb_ot_metrics_tag_t metrics_tag, hb_position_t * position) {
	hb_ot_metrics_get_position_with_fallback(font,metrics_tag,position);
}

float _impl_hb_ot_metrics_get_variation(struct HarfbuzzIFace *Self, hb_font_t * font, hb_ot_metrics_tag_t metrics_tag) {
	return hb_ot_metrics_get_variation(font,metrics_tag);
}

hb_position_t _impl_hb_ot_metrics_get_x_variation(struct HarfbuzzIFace *Self, hb_font_t * font, hb_ot_metrics_tag_t metrics_tag) {
	return hb_ot_metrics_get_x_variation(font,metrics_tag);
}

hb_position_t _impl_hb_ot_metrics_get_y_variation(struct HarfbuzzIFace *Self, hb_font_t * font, hb_ot_metrics_tag_t metrics_tag) {
	return hb_ot_metrics_get_y_variation(font,metrics_tag);
}

const hb_ot_name_entry_t * _impl_hb_ot_name_list_names(struct HarfbuzzIFace *Self, hb_face_t * face, unsigned int * num_entries) {
	return hb_ot_name_list_names(face,num_entries);
}

unsigned int _impl_hb_ot_name_get_utf8(struct HarfbuzzIFace *Self, hb_face_t * face, hb_ot_name_id_t name_id, hb_language_t language, unsigned int * text_size, char * text) {
	return hb_ot_name_get_utf8(face,name_id,language,text_size,text);
}

unsigned int _impl_hb_ot_name_get_utf16(struct HarfbuzzIFace *Self, hb_face_t * face, hb_ot_name_id_t name_id, hb_language_t language, unsigned int * text_size, uint16_t * text) {
	return hb_ot_name_get_utf16(face,name_id,language,text_size,text);
}

unsigned int _impl_hb_ot_name_get_utf32(struct HarfbuzzIFace *Self, hb_face_t * face, hb_ot_name_id_t name_id, hb_language_t language, unsigned int * text_size, uint32_t * text) {
	return hb_ot_name_get_utf32(face,name_id,language,text_size,text);
}

void _impl_hb_ot_shape_glyphs_closure(struct HarfbuzzIFace *Self, hb_font_t * font, hb_buffer_t * buffer, const hb_feature_t * features, unsigned int num_features, hb_set_t * glyphs) {
	hb_ot_shape_glyphs_closure(font,buffer,features,num_features,glyphs);
}

void _impl_hb_ot_shape_plan_collect_lookups(struct HarfbuzzIFace *Self, hb_shape_plan_t * shape_plan, hb_tag_t table_tag, hb_set_t * lookup_indexes) {
	hb_ot_shape_plan_collect_lookups(shape_plan,table_tag,lookup_indexes);
}

hb_bool_t _impl_hb_ot_var_has_data(struct HarfbuzzIFace *Self, hb_face_t * face) {
	return hb_ot_var_has_data(face);
}

unsigned int _impl_hb_ot_var_get_axis_count(struct HarfbuzzIFace *Self, hb_face_t * face) {
	return hb_ot_var_get_axis_count(face);
}

unsigned int _impl_hb_ot_var_get_axis_infos(struct HarfbuzzIFace *Self, hb_face_t * face, unsigned int start_offset, unsigned int * axes_count, hb_ot_var_axis_info_t * axes_array) {
	return hb_ot_var_get_axis_infos(face,start_offset,axes_count,axes_array);
}

hb_bool_t _impl_hb_ot_var_find_axis_info(struct HarfbuzzIFace *Self, hb_face_t * face, hb_tag_t axis_tag, hb_ot_var_axis_info_t * axis_info) {
	return hb_ot_var_find_axis_info(face,axis_tag,axis_info);
}

unsigned int _impl_hb_ot_var_get_named_instance_count(struct HarfbuzzIFace *Self, hb_face_t * face) {
	return hb_ot_var_get_named_instance_count(face);
}

hb_ot_name_id_t _impl_hb_ot_var_named_instance_get_subfamily_name_id(struct HarfbuzzIFace *Self, hb_face_t * face, unsigned int instance_index) {
	return hb_ot_var_named_instance_get_subfamily_name_id(face,instance_index);
}

hb_ot_name_id_t _impl_hb_ot_var_named_instance_get_postscript_name_id(struct HarfbuzzIFace *Self, hb_face_t * face, unsigned int instance_index) {
	return hb_ot_var_named_instance_get_postscript_name_id(face,instance_index);
}

unsigned int _impl_hb_ot_var_named_instance_get_design_coords(struct HarfbuzzIFace *Self, hb_face_t * face, unsigned int instance_index, unsigned int * coords_length, float * coords) {
	return hb_ot_var_named_instance_get_design_coords(face,instance_index,coords_length,coords);
}

void _impl_hb_ot_var_normalize_variations(struct HarfbuzzIFace *Self, hb_face_t * face, const hb_variation_t * variations, unsigned int variations_length, int * coords, unsigned int coords_length) {
	hb_ot_var_normalize_variations(face,variations,variations_length,coords,coords_length);
}

void _impl_hb_ot_var_normalize_coords(struct HarfbuzzIFace *Self, hb_face_t * face, unsigned int coords_length, const float * design_coords, int * normalized_coords) {
	hb_ot_var_normalize_coords(face,coords_length,design_coords,normalized_coords);
}

hb_paint_funcs_t * _impl_hb_paint_funcs_create(struct HarfbuzzIFace *Self) {
	return hb_paint_funcs_create();
}

hb_paint_funcs_t * _impl_hb_paint_funcs_get_empty(struct HarfbuzzIFace *Self) {
	return hb_paint_funcs_get_empty();
}

hb_paint_funcs_t * _impl_hb_paint_funcs_reference(struct HarfbuzzIFace *Self, hb_paint_funcs_t * funcs) {
	return hb_paint_funcs_reference(funcs);
}

void _impl_hb_paint_funcs_destroy(struct HarfbuzzIFace *Self, hb_paint_funcs_t * funcs) {
	hb_paint_funcs_destroy(funcs);
}

hb_bool_t _impl_hb_paint_funcs_set_user_data(struct HarfbuzzIFace *Self, hb_paint_funcs_t * funcs, hb_user_data_key_t * key, void * data, hb_destroy_func_t destroy, hb_bool_t replace) {
	return hb_paint_funcs_set_user_data(funcs,key,data,destroy,replace);
}

void * _impl_hb_paint_funcs_get_user_data(struct HarfbuzzIFace *Self, const hb_paint_funcs_t * funcs, hb_user_data_key_t * key) {
	return hb_paint_funcs_get_user_data(funcs,key);
}

void _impl_hb_paint_funcs_make_immutable(struct HarfbuzzIFace *Self, hb_paint_funcs_t * funcs) {
	hb_paint_funcs_make_immutable(funcs);
}

hb_bool_t _impl_hb_paint_funcs_is_immutable(struct HarfbuzzIFace *Self, hb_paint_funcs_t * funcs) {
	return hb_paint_funcs_is_immutable(funcs);
}

unsigned int _impl_hb_color_line_get_color_stops(struct HarfbuzzIFace *Self, hb_color_line_t * color_line, unsigned int start, unsigned int * count, hb_color_stop_t * color_stops) {
	return hb_color_line_get_color_stops(color_line,start,count,color_stops);
}

hb_paint_extend_t _impl_hb_color_line_get_extend(struct HarfbuzzIFace *Self, hb_color_line_t * color_line) {
	return hb_color_line_get_extend(color_line);
}

void _impl_hb_paint_funcs_set_push_transform_func(struct HarfbuzzIFace *Self, hb_paint_funcs_t * funcs, hb_paint_push_transform_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_paint_funcs_set_push_transform_func(funcs,func,user_data,destroy);
}

void _impl_hb_paint_funcs_set_pop_transform_func(struct HarfbuzzIFace *Self, hb_paint_funcs_t * funcs, hb_paint_pop_transform_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_paint_funcs_set_pop_transform_func(funcs,func,user_data,destroy);
}

void _impl_hb_paint_funcs_set_color_glyph_func(struct HarfbuzzIFace *Self, hb_paint_funcs_t * funcs, hb_paint_color_glyph_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_paint_funcs_set_color_glyph_func(funcs,func,user_data,destroy);
}

void _impl_hb_paint_funcs_set_push_clip_glyph_func(struct HarfbuzzIFace *Self, hb_paint_funcs_t * funcs, hb_paint_push_clip_glyph_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_paint_funcs_set_push_clip_glyph_func(funcs,func,user_data,destroy);
}

void _impl_hb_paint_funcs_set_push_clip_rectangle_func(struct HarfbuzzIFace *Self, hb_paint_funcs_t * funcs, hb_paint_push_clip_rectangle_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_paint_funcs_set_push_clip_rectangle_func(funcs,func,user_data,destroy);
}

void _impl_hb_paint_funcs_set_pop_clip_func(struct HarfbuzzIFace *Self, hb_paint_funcs_t * funcs, hb_paint_pop_clip_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_paint_funcs_set_pop_clip_func(funcs,func,user_data,destroy);
}

void _impl_hb_paint_funcs_set_color_func(struct HarfbuzzIFace *Self, hb_paint_funcs_t * funcs, hb_paint_color_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_paint_funcs_set_color_func(funcs,func,user_data,destroy);
}

void _impl_hb_paint_funcs_set_image_func(struct HarfbuzzIFace *Self, hb_paint_funcs_t * funcs, hb_paint_image_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_paint_funcs_set_image_func(funcs,func,user_data,destroy);
}

void _impl_hb_paint_funcs_set_linear_gradient_func(struct HarfbuzzIFace *Self, hb_paint_funcs_t * funcs, hb_paint_linear_gradient_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_paint_funcs_set_linear_gradient_func(funcs,func,user_data,destroy);
}

void _impl_hb_paint_funcs_set_radial_gradient_func(struct HarfbuzzIFace *Self, hb_paint_funcs_t * funcs, hb_paint_radial_gradient_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_paint_funcs_set_radial_gradient_func(funcs,func,user_data,destroy);
}

void _impl_hb_paint_funcs_set_sweep_gradient_func(struct HarfbuzzIFace *Self, hb_paint_funcs_t * funcs, hb_paint_sweep_gradient_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_paint_funcs_set_sweep_gradient_func(funcs,func,user_data,destroy);
}

void _impl_hb_paint_funcs_set_push_group_func(struct HarfbuzzIFace *Self, hb_paint_funcs_t * funcs, hb_paint_push_group_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_paint_funcs_set_push_group_func(funcs,func,user_data,destroy);
}

void _impl_hb_paint_funcs_set_pop_group_func(struct HarfbuzzIFace *Self, hb_paint_funcs_t * funcs, hb_paint_pop_group_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_paint_funcs_set_pop_group_func(funcs,func,user_data,destroy);
}

void _impl_hb_paint_funcs_set_custom_palette_color_func(struct HarfbuzzIFace *Self, hb_paint_funcs_t * funcs, hb_paint_custom_palette_color_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_paint_funcs_set_custom_palette_color_func(funcs,func,user_data,destroy);
}

void _impl_hb_paint_push_transform(struct HarfbuzzIFace *Self, hb_paint_funcs_t * funcs, void * paint_data, float xx, float yx, float xy, float yy, float dx, float dy) {
	hb_paint_push_transform(funcs,paint_data,xx,yx,xy,yy,dx,dy);
}

void _impl_hb_paint_pop_transform(struct HarfbuzzIFace *Self, hb_paint_funcs_t * funcs, void * paint_data) {
	hb_paint_pop_transform(funcs,paint_data);
}

hb_bool_t _impl_hb_paint_color_glyph(struct HarfbuzzIFace *Self, hb_paint_funcs_t * funcs, void * paint_data, hb_codepoint_t glyph, hb_font_t * font) {
	return hb_paint_color_glyph(funcs,paint_data,glyph,font);
}

void _impl_hb_paint_push_clip_glyph(struct HarfbuzzIFace *Self, hb_paint_funcs_t * funcs, void * paint_data, hb_codepoint_t glyph, hb_font_t * font) {
	hb_paint_push_clip_glyph(funcs,paint_data,glyph,font);
}

void _impl_hb_paint_push_clip_rectangle(struct HarfbuzzIFace *Self, hb_paint_funcs_t * funcs, void * paint_data, float xmin, float ymin, float xmax, float ymax) {
	hb_paint_push_clip_rectangle(funcs,paint_data,xmin,ymin,xmax,ymax);
}

void _impl_hb_paint_pop_clip(struct HarfbuzzIFace *Self, hb_paint_funcs_t * funcs, void * paint_data) {
	hb_paint_pop_clip(funcs,paint_data);
}

void _impl_hb_paint_color(struct HarfbuzzIFace *Self, hb_paint_funcs_t * funcs, void * paint_data, hb_bool_t is_foreground, hb_color_t color) {
	hb_paint_color(funcs,paint_data,is_foreground,color);
}

void _impl_hb_paint_image(struct HarfbuzzIFace *Self, hb_paint_funcs_t * funcs, void * paint_data, hb_blob_t * image, unsigned int width, unsigned int height, hb_tag_t format, float slant, hb_glyph_extents_t * extents) {
	hb_paint_image(funcs,paint_data,image,width,height,format,slant,extents);
}

void _impl_hb_paint_linear_gradient(struct HarfbuzzIFace *Self, hb_paint_funcs_t * funcs, void * paint_data, hb_color_line_t * color_line, float x0, float y0, float x1, float y1, float x2, float y2) {
	hb_paint_linear_gradient(funcs,paint_data,color_line,x0,y0,x1,y1,x2,y2);
}

void _impl_hb_paint_radial_gradient(struct HarfbuzzIFace *Self, hb_paint_funcs_t * funcs, void * paint_data, hb_color_line_t * color_line, float x0, float y0, float r0, float x1, float y1, float r1) {
	hb_paint_radial_gradient(funcs,paint_data,color_line,x0,y0,r0,x1,y1,r1);
}

void _impl_hb_paint_sweep_gradient(struct HarfbuzzIFace *Self, hb_paint_funcs_t * funcs, void * paint_data, hb_color_line_t * color_line, float x0, float y0, float start_angle, float end_angle) {
	hb_paint_sweep_gradient(funcs,paint_data,color_line,x0,y0,start_angle,end_angle);
}

void _impl_hb_paint_push_group(struct HarfbuzzIFace *Self, hb_paint_funcs_t * funcs, void * paint_data) {
	hb_paint_push_group(funcs,paint_data);
}

void _impl_hb_paint_pop_group(struct HarfbuzzIFace *Self, hb_paint_funcs_t * funcs, void * paint_data, hb_paint_composite_mode_t mode) {
	hb_paint_pop_group(funcs,paint_data,mode);
}

hb_bool_t _impl_hb_paint_custom_palette_color(struct HarfbuzzIFace *Self, hb_paint_funcs_t * funcs, void * paint_data, unsigned int color_index, hb_color_t * color) {
	return hb_paint_custom_palette_color(funcs,paint_data,color_index,color);
}

hb_set_t * _impl_hb_set_create(struct HarfbuzzIFace *Self) {
	return hb_set_create();
}

hb_set_t * _impl_hb_set_get_empty(struct HarfbuzzIFace *Self) {
	return hb_set_get_empty();
}

hb_set_t * _impl_hb_set_reference(struct HarfbuzzIFace *Self, hb_set_t * set) {
	return hb_set_reference(set);
}

void _impl_hb_set_destroy(struct HarfbuzzIFace *Self, hb_set_t * set) {
	hb_set_destroy(set);
}

hb_bool_t _impl_hb_set_set_user_data(struct HarfbuzzIFace *Self, hb_set_t * set, hb_user_data_key_t * key, void * data, hb_destroy_func_t destroy, hb_bool_t replace) {
	return hb_set_set_user_data(set,key,data,destroy,replace);
}

void * _impl_hb_set_get_user_data(struct HarfbuzzIFace *Self, const hb_set_t * set, hb_user_data_key_t * key) {
	return hb_set_get_user_data(set,key);
}

hb_bool_t _impl_hb_set_allocation_successful(struct HarfbuzzIFace *Self, const hb_set_t * set) {
	return hb_set_allocation_successful(set);
}

hb_set_t * _impl_hb_set_copy(struct HarfbuzzIFace *Self, const hb_set_t * set) {
	return hb_set_copy(set);
}

void _impl_hb_set_clear(struct HarfbuzzIFace *Self, hb_set_t * set) {
	hb_set_clear(set);
}

hb_bool_t _impl_hb_set_is_empty(struct HarfbuzzIFace *Self, const hb_set_t * set) {
	return hb_set_is_empty(set);
}

void _impl_hb_set_invert(struct HarfbuzzIFace *Self, hb_set_t * set) {
	hb_set_invert(set);
}

hb_bool_t _impl_hb_set_is_inverted(struct HarfbuzzIFace *Self, const hb_set_t * set) {
	return hb_set_is_inverted(set);
}

hb_bool_t _impl_hb_set_has(struct HarfbuzzIFace *Self, const hb_set_t * set, hb_codepoint_t codepoint) {
	return hb_set_has(set,codepoint);
}

void _impl_hb_set_add(struct HarfbuzzIFace *Self, hb_set_t * set, hb_codepoint_t codepoint) {
	hb_set_add(set,codepoint);
}

void _impl_hb_set_add_range(struct HarfbuzzIFace *Self, hb_set_t * set, hb_codepoint_t first, hb_codepoint_t last) {
	hb_set_add_range(set,first,last);
}

void _impl_hb_set_add_sorted_array(struct HarfbuzzIFace *Self, hb_set_t * set, const hb_codepoint_t * sorted_codepoints, unsigned int num_codepoints) {
	hb_set_add_sorted_array(set,sorted_codepoints,num_codepoints);
}

void _impl_hb_set_del(struct HarfbuzzIFace *Self, hb_set_t * set, hb_codepoint_t codepoint) {
	hb_set_del(set,codepoint);
}

void _impl_hb_set_del_range(struct HarfbuzzIFace *Self, hb_set_t * set, hb_codepoint_t first, hb_codepoint_t last) {
	hb_set_del_range(set,first,last);
}

hb_bool_t _impl_hb_set_is_equal(struct HarfbuzzIFace *Self, const hb_set_t * set, const hb_set_t * other) {
	return hb_set_is_equal(set,other);
}

unsigned int _impl_hb_set_hash(struct HarfbuzzIFace *Self, const hb_set_t * set) {
	return hb_set_hash(set);
}

hb_bool_t _impl_hb_set_is_subset(struct HarfbuzzIFace *Self, const hb_set_t * set, const hb_set_t * larger_set) {
	return hb_set_is_subset(set,larger_set);
}

void _impl_hb_set_set(struct HarfbuzzIFace *Self, hb_set_t * set, const hb_set_t * other) {
	hb_set_set(set,other);
}

void _impl_hb_set_union(struct HarfbuzzIFace *Self, hb_set_t * set, const hb_set_t * other) {
	hb_set_union(set,other);
}

void _impl_hb_set_intersect(struct HarfbuzzIFace *Self, hb_set_t * set, const hb_set_t * other) {
	hb_set_intersect(set,other);
}

void _impl_hb_set_subtract(struct HarfbuzzIFace *Self, hb_set_t * set, const hb_set_t * other) {
	hb_set_subtract(set,other);
}

void _impl_hb_set_symmetric_difference(struct HarfbuzzIFace *Self, hb_set_t * set, const hb_set_t * other) {
	hb_set_symmetric_difference(set,other);
}

unsigned int _impl_hb_set_get_population(struct HarfbuzzIFace *Self, const hb_set_t * set) {
	return hb_set_get_population(set);
}

hb_codepoint_t _impl_hb_set_get_min(struct HarfbuzzIFace *Self, const hb_set_t * set) {
	return hb_set_get_min(set);
}

hb_codepoint_t _impl_hb_set_get_max(struct HarfbuzzIFace *Self, const hb_set_t * set) {
	return hb_set_get_max(set);
}

hb_bool_t _impl_hb_set_next(struct HarfbuzzIFace *Self, const hb_set_t * set, hb_codepoint_t * codepoint) {
	return hb_set_next(set,codepoint);
}

hb_bool_t _impl_hb_set_previous(struct HarfbuzzIFace *Self, const hb_set_t * set, hb_codepoint_t * codepoint) {
	return hb_set_previous(set,codepoint);
}

hb_bool_t _impl_hb_set_next_range(struct HarfbuzzIFace *Self, const hb_set_t * set, hb_codepoint_t * first, hb_codepoint_t * last) {
	return hb_set_next_range(set,first,last);
}

hb_bool_t _impl_hb_set_previous_range(struct HarfbuzzIFace *Self, const hb_set_t * set, hb_codepoint_t * first, hb_codepoint_t * last) {
	return hb_set_previous_range(set,first,last);
}

unsigned int _impl_hb_set_next_many(struct HarfbuzzIFace *Self, const hb_set_t * set, hb_codepoint_t codepoint, hb_codepoint_t * out, unsigned int size) {
	return hb_set_next_many(set,codepoint,out,size);
}

hb_shape_plan_t * _impl_hb_shape_plan_create(struct HarfbuzzIFace *Self, hb_face_t * face, const hb_segment_properties_t * props, const hb_feature_t * user_features, unsigned int num_user_features, const char * const * shaper_list) {
	return hb_shape_plan_create(face,props,user_features,num_user_features,shaper_list);
}

hb_shape_plan_t * _impl_hb_shape_plan_create_cached(struct HarfbuzzIFace *Self, hb_face_t * face, const hb_segment_properties_t * props, const hb_feature_t * user_features, unsigned int num_user_features, const char * const * shaper_list) {
	return hb_shape_plan_create_cached(face,props,user_features,num_user_features,shaper_list);
}

hb_shape_plan_t * _impl_hb_shape_plan_create2(struct HarfbuzzIFace *Self, hb_face_t * face, const hb_segment_properties_t * props, const hb_feature_t * user_features, unsigned int num_user_features, const int * coords, unsigned int num_coords, const char * const * shaper_list) {
	return hb_shape_plan_create2(face,props,user_features,num_user_features,coords,num_coords,shaper_list);
}

hb_shape_plan_t * _impl_hb_shape_plan_create_cached2(struct HarfbuzzIFace *Self, hb_face_t * face, const hb_segment_properties_t * props, const hb_feature_t * user_features, unsigned int num_user_features, const int * coords, unsigned int num_coords, const char * const * shaper_list) {
	return hb_shape_plan_create_cached2(face,props,user_features,num_user_features,coords,num_coords,shaper_list);
}

hb_shape_plan_t * _impl_hb_shape_plan_get_empty(struct HarfbuzzIFace *Self) {
	return hb_shape_plan_get_empty();
}

hb_shape_plan_t * _impl_hb_shape_plan_reference(struct HarfbuzzIFace *Self, hb_shape_plan_t * shape_plan) {
	return hb_shape_plan_reference(shape_plan);
}

void _impl_hb_shape_plan_destroy(struct HarfbuzzIFace *Self, hb_shape_plan_t * shape_plan) {
	hb_shape_plan_destroy(shape_plan);
}

hb_bool_t _impl_hb_shape_plan_set_user_data(struct HarfbuzzIFace *Self, hb_shape_plan_t * shape_plan, hb_user_data_key_t * key, void * data, hb_destroy_func_t destroy, hb_bool_t replace) {
	return hb_shape_plan_set_user_data(shape_plan,key,data,destroy,replace);
}

void * _impl_hb_shape_plan_get_user_data(struct HarfbuzzIFace *Self, const hb_shape_plan_t * shape_plan, hb_user_data_key_t * key) {
	return hb_shape_plan_get_user_data(shape_plan,key);
}

hb_bool_t _impl_hb_shape_plan_execute(struct HarfbuzzIFace *Self, hb_shape_plan_t * shape_plan, hb_font_t * font, hb_buffer_t * buffer, const hb_feature_t * features, unsigned int num_features) {
	return hb_shape_plan_execute(shape_plan,font,buffer,features,num_features);
}

const char * _impl_hb_shape_plan_get_shaper(struct HarfbuzzIFace *Self, hb_shape_plan_t * shape_plan) {
	return hb_shape_plan_get_shaper(shape_plan);
}

void _impl_hb_shape(struct HarfbuzzIFace *Self, hb_font_t * font, hb_buffer_t * buffer, const hb_feature_t * features, unsigned int num_features) {
	hb_shape(font,buffer,features,num_features);
}

hb_bool_t _impl_hb_shape_full(struct HarfbuzzIFace *Self, hb_font_t * font, hb_buffer_t * buffer, const hb_feature_t * features, unsigned int num_features, const char * const * shaper_list) {
	return hb_shape_full(font,buffer,features,num_features,shaper_list);
}

hb_bool_t _impl_hb_shape_justify(struct HarfbuzzIFace *Self, hb_font_t * font, hb_buffer_t * buffer, const hb_feature_t * features, unsigned int num_features, const char * const * shaper_list, float min_target_advance, float max_target_advance, float * advance, hb_tag_t * var_tag, float * var_value) {
	return hb_shape_justify(font,buffer,features,num_features,shaper_list,min_target_advance,max_target_advance,advance,var_tag,var_value);
}

const char ** _impl_hb_shape_list_shapers(struct HarfbuzzIFace *Self) {
	return hb_shape_list_shapers();
}

float _impl_hb_style_get_value(struct HarfbuzzIFace *Self, hb_font_t * font, hb_style_tag_t style_tag) {
	return hb_style_get_value(font,style_tag);
}

hb_blob_t* _impl_hb_subset_repack_or_fail(struct HarfbuzzIFace *Self, hb_tag_t table_tag, hb_object_t* hb_objects, unsigned num_hb_objs) {
	return hb_subset_repack_or_fail(table_tag,hb_objects,num_hb_objs);
}

hb_subset_input_t * _impl_hb_subset_input_create_or_fail(struct HarfbuzzIFace *Self) {
	return hb_subset_input_create_or_fail();
}

hb_subset_input_t * _impl_hb_subset_input_reference(struct HarfbuzzIFace *Self, hb_subset_input_t * input) {
	return hb_subset_input_reference(input);
}

void _impl_hb_subset_input_destroy(struct HarfbuzzIFace *Self, hb_subset_input_t * input) {
	hb_subset_input_destroy(input);
}

hb_bool_t _impl_hb_subset_input_set_user_data(struct HarfbuzzIFace *Self, hb_subset_input_t * input, hb_user_data_key_t * key, void * data, hb_destroy_func_t destroy, hb_bool_t replace) {
	return hb_subset_input_set_user_data(input,key,data,destroy,replace);
}

void * _impl_hb_subset_input_get_user_data(struct HarfbuzzIFace *Self, const hb_subset_input_t * input, hb_user_data_key_t * key) {
	return hb_subset_input_get_user_data(input,key);
}

void _impl_hb_subset_input_keep_everything(struct HarfbuzzIFace *Self, hb_subset_input_t * input) {
	hb_subset_input_keep_everything(input);
}

hb_set_t * _impl_hb_subset_input_unicode_set(struct HarfbuzzIFace *Self, hb_subset_input_t * input) {
	return hb_subset_input_unicode_set(input);
}

hb_set_t * _impl_hb_subset_input_glyph_set(struct HarfbuzzIFace *Self, hb_subset_input_t * input) {
	return hb_subset_input_glyph_set(input);
}

hb_set_t * _impl_hb_subset_input_set(struct HarfbuzzIFace *Self, hb_subset_input_t * input, hb_subset_sets_t set_type) {
	return hb_subset_input_set(input,set_type);
}

hb_map_t* _impl_hb_subset_input_old_to_new_glyph_mapping(struct HarfbuzzIFace *Self, hb_subset_input_t * input) {
	return hb_subset_input_old_to_new_glyph_mapping(input);
}

hb_subset_flags_t _impl_hb_subset_input_get_flags(struct HarfbuzzIFace *Self, hb_subset_input_t * input) {
	return hb_subset_input_get_flags(input);
}

void _impl_hb_subset_input_set_flags(struct HarfbuzzIFace *Self, hb_subset_input_t * input, unsigned value) {
	hb_subset_input_set_flags(input,value);
}

hb_bool_t _impl_hb_subset_input_pin_all_axes_to_default(struct HarfbuzzIFace *Self, hb_subset_input_t * input, hb_face_t * face) {
	return hb_subset_input_pin_all_axes_to_default(input,face);
}

hb_bool_t _impl_hb_subset_input_pin_axis_to_default(struct HarfbuzzIFace *Self, hb_subset_input_t * input, hb_face_t * face, hb_tag_t axis_tag) {
	return hb_subset_input_pin_axis_to_default(input,face,axis_tag);
}

hb_bool_t _impl_hb_subset_input_pin_axis_location(struct HarfbuzzIFace *Self, hb_subset_input_t * input, hb_face_t * face, hb_tag_t axis_tag, float axis_value) {
	return hb_subset_input_pin_axis_location(input,face,axis_tag,axis_value);
}

hb_bool_t _impl_hb_subset_input_get_axis_range(struct HarfbuzzIFace *Self, hb_subset_input_t * input, hb_tag_t axis_tag, float * axis_min_value, float * axis_max_value, float * axis_def_value) {
	return hb_subset_input_get_axis_range(input,axis_tag,axis_min_value,axis_max_value,axis_def_value);
}

hb_bool_t _impl_hb_subset_input_set_axis_range(struct HarfbuzzIFace *Self, hb_subset_input_t * input, hb_face_t * face, hb_tag_t axis_tag, float axis_min_value, float axis_max_value, float axis_def_value) {
	return hb_subset_input_set_axis_range(input,face,axis_tag,axis_min_value,axis_max_value,axis_def_value);
}

hb_bool_t _impl_hb_subset_input_override_name_table(struct HarfbuzzIFace *Self, hb_subset_input_t * input, hb_ot_name_id_t name_id, unsigned platform_id, unsigned encoding_id, unsigned language_id, const char * name_str, int str_len) {
	return hb_subset_input_override_name_table(input,name_id,platform_id,encoding_id,language_id,name_str,str_len);
}

hb_face_t * _impl_hb_subset_preprocess(struct HarfbuzzIFace *Self, hb_face_t * source) {
	return hb_subset_preprocess(source);
}

hb_face_t * _impl_hb_subset_or_fail(struct HarfbuzzIFace *Self, hb_face_t * source, const hb_subset_input_t * input) {
	return hb_subset_or_fail(source,input);
}

hb_face_t * _impl_hb_subset_plan_execute_or_fail(struct HarfbuzzIFace *Self, hb_subset_plan_t * plan) {
	return hb_subset_plan_execute_or_fail(plan);
}

hb_subset_plan_t * _impl_hb_subset_plan_create_or_fail(struct HarfbuzzIFace *Self, hb_face_t * face, const hb_subset_input_t * input) {
	return hb_subset_plan_create_or_fail(face,input);
}

void _impl_hb_subset_plan_destroy(struct HarfbuzzIFace *Self, hb_subset_plan_t * plan) {
	hb_subset_plan_destroy(plan);
}

hb_map_t * _impl_hb_subset_plan_old_to_new_glyph_mapping(struct HarfbuzzIFace *Self, const hb_subset_plan_t * plan) {
	return hb_subset_plan_old_to_new_glyph_mapping(plan);
}

hb_map_t * _impl_hb_subset_plan_new_to_old_glyph_mapping(struct HarfbuzzIFace *Self, const hb_subset_plan_t * plan) {
	return hb_subset_plan_new_to_old_glyph_mapping(plan);
}

hb_map_t * _impl_hb_subset_plan_unicode_to_old_glyph_mapping(struct HarfbuzzIFace *Self, const hb_subset_plan_t * plan) {
	return hb_subset_plan_unicode_to_old_glyph_mapping(plan);
}

hb_subset_plan_t * _impl_hb_subset_plan_reference(struct HarfbuzzIFace *Self, hb_subset_plan_t * plan) {
	return hb_subset_plan_reference(plan);
}

hb_bool_t _impl_hb_subset_plan_set_user_data(struct HarfbuzzIFace *Self, hb_subset_plan_t * plan, hb_user_data_key_t * key, void * data, hb_destroy_func_t destroy, hb_bool_t replace) {
	return hb_subset_plan_set_user_data(plan,key,data,destroy,replace);
}

void * _impl_hb_subset_plan_get_user_data(struct HarfbuzzIFace *Self, const hb_subset_plan_t * plan, hb_user_data_key_t * key) {
	return hb_subset_plan_get_user_data(plan,key);
}

hb_unicode_funcs_t * _impl_hb_unicode_funcs_get_default(struct HarfbuzzIFace *Self) {
	return hb_unicode_funcs_get_default();
}

hb_unicode_funcs_t * _impl_hb_unicode_funcs_create(struct HarfbuzzIFace *Self, hb_unicode_funcs_t * parent) {
	return hb_unicode_funcs_create(parent);
}

hb_unicode_funcs_t * _impl_hb_unicode_funcs_get_empty(struct HarfbuzzIFace *Self) {
	return hb_unicode_funcs_get_empty();
}

hb_unicode_funcs_t * _impl_hb_unicode_funcs_reference(struct HarfbuzzIFace *Self, hb_unicode_funcs_t * ufuncs) {
	return hb_unicode_funcs_reference(ufuncs);
}

void _impl_hb_unicode_funcs_destroy(struct HarfbuzzIFace *Self, hb_unicode_funcs_t * ufuncs) {
	hb_unicode_funcs_destroy(ufuncs);
}

hb_bool_t _impl_hb_unicode_funcs_set_user_data(struct HarfbuzzIFace *Self, hb_unicode_funcs_t * ufuncs, hb_user_data_key_t * key, void * data, hb_destroy_func_t destroy, hb_bool_t replace) {
	return hb_unicode_funcs_set_user_data(ufuncs,key,data,destroy,replace);
}

void * _impl_hb_unicode_funcs_get_user_data(struct HarfbuzzIFace *Self, const hb_unicode_funcs_t * ufuncs, hb_user_data_key_t * key) {
	return hb_unicode_funcs_get_user_data(ufuncs,key);
}

void _impl_hb_unicode_funcs_make_immutable(struct HarfbuzzIFace *Self, hb_unicode_funcs_t * ufuncs) {
	hb_unicode_funcs_make_immutable(ufuncs);
}

hb_bool_t _impl_hb_unicode_funcs_is_immutable(struct HarfbuzzIFace *Self, hb_unicode_funcs_t * ufuncs) {
	return hb_unicode_funcs_is_immutable(ufuncs);
}

hb_unicode_funcs_t * _impl_hb_unicode_funcs_get_parent(struct HarfbuzzIFace *Self, hb_unicode_funcs_t * ufuncs) {
	return hb_unicode_funcs_get_parent(ufuncs);
}

void _impl_hb_unicode_funcs_set_combining_class_func(struct HarfbuzzIFace *Self, hb_unicode_funcs_t * ufuncs, hb_unicode_combining_class_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_unicode_funcs_set_combining_class_func(ufuncs,func,user_data,destroy);
}

void _impl_hb_unicode_funcs_set_general_category_func(struct HarfbuzzIFace *Self, hb_unicode_funcs_t * ufuncs, hb_unicode_general_category_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_unicode_funcs_set_general_category_func(ufuncs,func,user_data,destroy);
}

void _impl_hb_unicode_funcs_set_mirroring_func(struct HarfbuzzIFace *Self, hb_unicode_funcs_t * ufuncs, hb_unicode_mirroring_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_unicode_funcs_set_mirroring_func(ufuncs,func,user_data,destroy);
}

void _impl_hb_unicode_funcs_set_script_func(struct HarfbuzzIFace *Self, hb_unicode_funcs_t * ufuncs, hb_unicode_script_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_unicode_funcs_set_script_func(ufuncs,func,user_data,destroy);
}

void _impl_hb_unicode_funcs_set_compose_func(struct HarfbuzzIFace *Self, hb_unicode_funcs_t * ufuncs, hb_unicode_compose_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_unicode_funcs_set_compose_func(ufuncs,func,user_data,destroy);
}

void _impl_hb_unicode_funcs_set_decompose_func(struct HarfbuzzIFace *Self, hb_unicode_funcs_t * ufuncs, hb_unicode_decompose_func_t func, void * user_data, hb_destroy_func_t destroy) {
	hb_unicode_funcs_set_decompose_func(ufuncs,func,user_data,destroy);
}

hb_unicode_combining_class_t _impl_hb_unicode_combining_class(struct HarfbuzzIFace *Self, hb_unicode_funcs_t * ufuncs, hb_codepoint_t unicode) {
	return hb_unicode_combining_class(ufuncs,unicode);
}

hb_unicode_general_category_t _impl_hb_unicode_general_category(struct HarfbuzzIFace *Self, hb_unicode_funcs_t * ufuncs, hb_codepoint_t unicode) {
	return hb_unicode_general_category(ufuncs,unicode);
}

hb_codepoint_t _impl_hb_unicode_mirroring(struct HarfbuzzIFace *Self, hb_unicode_funcs_t * ufuncs, hb_codepoint_t unicode) {
	return hb_unicode_mirroring(ufuncs,unicode);
}

hb_script_t _impl_hb_unicode_script(struct HarfbuzzIFace *Self, hb_unicode_funcs_t * ufuncs, hb_codepoint_t unicode) {
	return hb_unicode_script(ufuncs,unicode);
}

hb_bool_t _impl_hb_unicode_compose(struct HarfbuzzIFace *Self, hb_unicode_funcs_t * ufuncs, hb_codepoint_t a, hb_codepoint_t b, hb_codepoint_t * ab) {
	return hb_unicode_compose(ufuncs,a,b,ab);
}

hb_bool_t _impl_hb_unicode_decompose(struct HarfbuzzIFace *Self, hb_unicode_funcs_t * ufuncs, hb_codepoint_t ab, hb_codepoint_t * a, hb_codepoint_t * b) {
	return hb_unicode_decompose(ufuncs,ab,a,b);
}

void _impl_hb_version(struct HarfbuzzIFace *Self, unsigned int * major, unsigned int * minor, unsigned int * micro) {
	hb_version(major,minor,micro);
}

const char * _impl_hb_version_string(struct HarfbuzzIFace *Self) {
	return hb_version_string();
}

hb_bool_t _impl_hb_version_atleast(struct HarfbuzzIFace *Self, unsigned int major, unsigned int minor, unsigned int micro) {
	return hb_version_atleast(major,minor,micro);
}

