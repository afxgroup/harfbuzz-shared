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

unsigned int hb_aat_layout_get_feature_types(hb_face_t * face, unsigned int start_offset, unsigned int * feature_count, hb_aat_layout_feature_type_t * features) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_aat_layout_get_feature_types(face,start_offset,feature_count,features);
}

hb_ot_name_id_t hb_aat_layout_feature_type_get_name_id(hb_face_t * face, hb_aat_layout_feature_type_t feature_type) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_aat_layout_feature_type_get_name_id(face,feature_type);
}

unsigned int hb_aat_layout_feature_type_get_selector_infos(hb_face_t * face, hb_aat_layout_feature_type_t feature_type, unsigned int start_offset, unsigned int * selector_count, hb_aat_layout_feature_selector_info_t * selectors, unsigned int * default_index) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_aat_layout_feature_type_get_selector_infos(face,feature_type,start_offset,selector_count,selectors,default_index);
}

hb_bool_t hb_aat_layout_has_substitution(hb_face_t * face) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_aat_layout_has_substitution(face);
}

hb_bool_t hb_aat_layout_has_positioning(hb_face_t * face) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_aat_layout_has_positioning(face);
}

hb_bool_t hb_aat_layout_has_tracking(hb_face_t * face) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_aat_layout_has_tracking(face);
}

hb_blob_t * hb_blob_create(const char * data, unsigned int length, hb_memory_mode_t mode, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_blob_create(data,length,mode,user_data,destroy);
}

hb_blob_t * hb_blob_create_or_fail(const char * data, unsigned int length, hb_memory_mode_t mode, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_blob_create_or_fail(data,length,mode,user_data,destroy);
}

hb_blob_t * hb_blob_create_from_file(const char * file_name) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_blob_create_from_file(file_name);
}

hb_blob_t * hb_blob_create_from_file_or_fail(const char * file_name) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_blob_create_from_file_or_fail(file_name);
}

hb_blob_t * hb_blob_create_sub_blob(hb_blob_t * parent, unsigned int offset, unsigned int length) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_blob_create_sub_blob(parent,offset,length);
}

hb_blob_t * hb_blob_copy_writable_or_fail(hb_blob_t * blob) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_blob_copy_writable_or_fail(blob);
}

hb_blob_t * hb_blob_get_empty() {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_blob_get_empty();
}

hb_blob_t * hb_blob_reference(hb_blob_t * blob) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_blob_reference(blob);
}

void hb_blob_destroy(hb_blob_t * blob) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_blob_destroy(blob);
}

hb_bool_t hb_blob_set_user_data(hb_blob_t * blob, hb_user_data_key_t * key, void * data, hb_destroy_func_t destroy, hb_bool_t replace) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_blob_set_user_data(blob,key,data,destroy,replace);
}

void * hb_blob_get_user_data(const hb_blob_t * blob, hb_user_data_key_t * key) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_blob_get_user_data(blob,key);
}

void hb_blob_make_immutable(hb_blob_t * blob) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_blob_make_immutable(blob);
}

hb_bool_t hb_blob_is_immutable(hb_blob_t * blob) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_blob_is_immutable(blob);
}

unsigned int hb_blob_get_length(hb_blob_t * blob) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_blob_get_length(blob);
}

const char * hb_blob_get_data(hb_blob_t * blob, unsigned int * length) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_blob_get_data(blob,length);
}

char * hb_blob_get_data_writable(hb_blob_t * blob, unsigned int * length) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_blob_get_data_writable(blob,length);
}

// TODO - CHeck this!
hb_glyph_flags_t hb_glyph_info_get_glyph_flags(const hb_glyph_info_t * info) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_glyph_info_get_glyph_flags(info);
}

hb_bool_t hb_segment_properties_equal(const hb_segment_properties_t * a, const hb_segment_properties_t * b) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_segment_properties_equal(a,b);
}

unsigned int hb_segment_properties_hash(const hb_segment_properties_t * p) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_segment_properties_hash(p);
}

void hb_segment_properties_overlay(hb_segment_properties_t * p, const hb_segment_properties_t * src) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_segment_properties_overlay(p,src);
}

hb_buffer_t * hb_buffer_create() {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_buffer_create();
}

hb_buffer_t * hb_buffer_create_similar(const hb_buffer_t * src) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_buffer_create_similar(src);
}

void hb_buffer_reset(hb_buffer_t * buffer) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_buffer_reset(buffer);
}

hb_buffer_t * hb_buffer_get_empty() {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_buffer_get_empty();
}

hb_buffer_t * hb_buffer_reference(hb_buffer_t * buffer) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_buffer_reference(buffer);
}

void hb_buffer_destroy(hb_buffer_t * buffer) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_buffer_destroy(buffer);
}

hb_bool_t hb_buffer_set_user_data(hb_buffer_t * buffer, hb_user_data_key_t * key, void * data, hb_destroy_func_t destroy, hb_bool_t replace) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_buffer_set_user_data(buffer,key,data,destroy,replace);
}

void * hb_buffer_get_user_data(const hb_buffer_t * buffer, hb_user_data_key_t * key) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_buffer_get_user_data(buffer,key);
}

void hb_buffer_set_content_type(hb_buffer_t * buffer, hb_buffer_content_type_t content_type) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_buffer_set_content_type(buffer,content_type);
}

hb_buffer_content_type_t hb_buffer_get_content_type(const hb_buffer_t * buffer) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_buffer_get_content_type(buffer);
}

void hb_buffer_set_unicode_funcs(hb_buffer_t * buffer, hb_unicode_funcs_t * unicode_funcs) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_buffer_set_unicode_funcs(buffer,unicode_funcs);
}

hb_unicode_funcs_t * hb_buffer_get_unicode_funcs(const hb_buffer_t * buffer) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_buffer_get_unicode_funcs(buffer);
}

void hb_buffer_set_direction(hb_buffer_t * buffer, hb_direction_t direction) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_buffer_set_direction(buffer,direction);
}

hb_direction_t hb_buffer_get_direction(const hb_buffer_t * buffer) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_buffer_get_direction(buffer);
}

void hb_buffer_set_script(hb_buffer_t * buffer, hb_script_t script) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_buffer_set_script(buffer,script);
}

hb_script_t hb_buffer_get_script(const hb_buffer_t * buffer) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_buffer_get_script(buffer);
}

void hb_buffer_set_language(hb_buffer_t * buffer, hb_language_t language) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_buffer_set_language(buffer,language);
}

hb_language_t hb_buffer_get_language(const hb_buffer_t * buffer) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_buffer_get_language(buffer);
}

void hb_buffer_set_segment_properties(hb_buffer_t * buffer, const hb_segment_properties_t * props) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_buffer_set_segment_properties(buffer,props);
}

void hb_buffer_get_segment_properties(const hb_buffer_t * buffer, hb_segment_properties_t * props) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_buffer_get_segment_properties(buffer,props);
}

void hb_buffer_guess_segment_properties(hb_buffer_t * buffer) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_buffer_guess_segment_properties(buffer);
}

void hb_buffer_set_flags(hb_buffer_t * buffer, hb_buffer_flags_t flags) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_buffer_set_flags(buffer,flags);
}

hb_buffer_flags_t hb_buffer_get_flags(const hb_buffer_t * buffer) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_buffer_get_flags(buffer);
}

void hb_buffer_set_cluster_level(hb_buffer_t * buffer, hb_buffer_cluster_level_t cluster_level) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_buffer_set_cluster_level(buffer,cluster_level);
}

hb_buffer_cluster_level_t hb_buffer_get_cluster_level(const hb_buffer_t * buffer) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_buffer_get_cluster_level(buffer);
}

void hb_buffer_set_replacement_codepoint(hb_buffer_t * buffer, hb_codepoint_t replacement) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_buffer_set_replacement_codepoint(buffer,replacement);
}

hb_codepoint_t hb_buffer_get_replacement_codepoint(const hb_buffer_t * buffer) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_buffer_get_replacement_codepoint(buffer);
}

void hb_buffer_set_invisible_glyph(hb_buffer_t * buffer, hb_codepoint_t invisible) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_buffer_set_invisible_glyph(buffer,invisible);
}

hb_codepoint_t hb_buffer_get_invisible_glyph(const hb_buffer_t * buffer) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_buffer_get_invisible_glyph(buffer);
}

void hb_buffer_set_not_found_glyph(hb_buffer_t * buffer, hb_codepoint_t not_found) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_buffer_set_not_found_glyph(buffer,not_found);
}

hb_codepoint_t hb_buffer_get_not_found_glyph(const hb_buffer_t * buffer) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_buffer_get_not_found_glyph(buffer);
}

void hb_buffer_set_random_state(hb_buffer_t * buffer, unsigned state) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_buffer_set_random_state(buffer,state);
}

unsigned hb_buffer_get_random_state(const hb_buffer_t * buffer) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_buffer_get_random_state(buffer);
}

void hb_buffer_clear_contents(hb_buffer_t * buffer) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_buffer_clear_contents(buffer);
}

hb_bool_t hb_buffer_pre_allocate(hb_buffer_t * buffer, unsigned int size) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_buffer_pre_allocate(buffer,size);
}

hb_bool_t hb_buffer_allocation_successful(hb_buffer_t * buffer) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_buffer_allocation_successful(buffer);
}

void hb_buffer_reverse(hb_buffer_t * buffer) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_buffer_reverse(buffer);
}

void hb_buffer_reverse_range(hb_buffer_t * buffer, unsigned int start, unsigned int end) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_buffer_reverse_range(buffer,start,end);
}

void hb_buffer_reverse_clusters(hb_buffer_t * buffer) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_buffer_reverse_clusters(buffer);
}

void hb_buffer_add(hb_buffer_t * buffer, hb_codepoint_t codepoint, unsigned int cluster) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_buffer_add(buffer,codepoint,cluster);
}

void hb_buffer_add_utf8(hb_buffer_t * buffer, const char * text, int text_length, unsigned int item_offset, int item_length) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_buffer_add_utf8(buffer,text,text_length,item_offset,item_length);
}

void hb_buffer_add_utf16(hb_buffer_t * buffer, const uint16_t * text, int text_length, unsigned int item_offset, int item_length) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_buffer_add_utf16(buffer,text,text_length,item_offset,item_length);
}

void hb_buffer_add_utf32(hb_buffer_t * buffer, const uint32_t * text, int text_length, unsigned int item_offset, int item_length) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_buffer_add_utf32(buffer,text,text_length,item_offset,item_length);
}

void hb_buffer_add_latin1(hb_buffer_t * buffer, const uint8_t * text, int text_length, unsigned int item_offset, int item_length) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_buffer_add_latin1(buffer,text,text_length,item_offset,item_length);
}

void hb_buffer_add_codepoints(hb_buffer_t * buffer, const hb_codepoint_t * text, int text_length, unsigned int item_offset, int item_length) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_buffer_add_codepoints(buffer,text,text_length,item_offset,item_length);
}

void hb_buffer_append(hb_buffer_t * buffer, const hb_buffer_t * source, unsigned int start, unsigned int end) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_buffer_append(buffer,source,start,end);
}

hb_bool_t hb_buffer_set_length(hb_buffer_t * buffer, unsigned int length) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_buffer_set_length(buffer,length);
}

unsigned int hb_buffer_get_length(const hb_buffer_t * buffer) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_buffer_get_length(buffer);
}

hb_glyph_info_t * hb_buffer_get_glyph_infos(hb_buffer_t * buffer, unsigned int * length) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_buffer_get_glyph_infos(buffer,length);
}

hb_glyph_position_t * hb_buffer_get_glyph_positions(hb_buffer_t * buffer, unsigned int * length) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_buffer_get_glyph_positions(buffer,length);
}

hb_bool_t hb_buffer_has_positions(hb_buffer_t * buffer) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_buffer_has_positions(buffer);
}

void hb_buffer_normalize_glyphs(hb_buffer_t * buffer) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_buffer_normalize_glyphs(buffer);
}

hb_buffer_serialize_format_t hb_buffer_serialize_format_from_string(const char * str, int len) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_buffer_serialize_format_from_string(str,len);
}

const char * hb_buffer_serialize_format_to_string(hb_buffer_serialize_format_t format) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_buffer_serialize_format_to_string(format);
}

const char ** hb_buffer_serialize_list_formats() {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_buffer_serialize_list_formats();
}

unsigned int hb_buffer_serialize_glyphs(hb_buffer_t * buffer, unsigned int start, unsigned int end, char * buf, unsigned int buf_size, unsigned int * buf_consumed, hb_font_t * font, hb_buffer_serialize_format_t format, hb_buffer_serialize_flags_t flags) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_buffer_serialize_glyphs(buffer,start,end,buf,buf_size,buf_consumed,font,format,flags);
}

unsigned int hb_buffer_serialize_unicode(hb_buffer_t * buffer, unsigned int start, unsigned int end, char * buf, unsigned int buf_size, unsigned int * buf_consumed, hb_buffer_serialize_format_t format, hb_buffer_serialize_flags_t flags) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_buffer_serialize_unicode(buffer,start,end,buf,buf_size,buf_consumed,format,flags);
}

unsigned int hb_buffer_serialize(hb_buffer_t * buffer, unsigned int start, unsigned int end, char * buf, unsigned int buf_size, unsigned int * buf_consumed, hb_font_t * font, hb_buffer_serialize_format_t format, hb_buffer_serialize_flags_t flags) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_buffer_serialize(buffer,start,end,buf,buf_size,buf_consumed,font,format,flags);
}

hb_bool_t hb_buffer_deserialize_glyphs(hb_buffer_t * buffer, const char * buf, int buf_len, const char * *end_ptr, hb_font_t * font, hb_buffer_serialize_format_t format) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_buffer_deserialize_glyphs(buffer,buf,buf_len,end_ptr,font,format);
}

hb_bool_t hb_buffer_deserialize_unicode(hb_buffer_t * buffer, const char * buf, int buf_len, const char * *end_ptr, hb_buffer_serialize_format_t format) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_buffer_deserialize_unicode(buffer,buf,buf_len,end_ptr,format);
}

hb_buffer_diff_flags_t hb_buffer_diff(hb_buffer_t * buffer, hb_buffer_t * reference, hb_codepoint_t dottedcircle_glyph, unsigned int position_fuzz) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_buffer_diff(buffer,reference,dottedcircle_glyph,position_fuzz);
}

void hb_buffer_set_message_func(hb_buffer_t * buffer, hb_buffer_message_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_buffer_set_message_func(buffer,func,user_data,destroy);
}

cairo_font_face_t * hb_cairo_font_face_create_for_font(hb_font_t * font) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_cairo_font_face_create_for_font(font);
}

hb_font_t * hb_cairo_font_face_get_font(cairo_font_face_t * font_face) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_cairo_font_face_get_font(font_face);
}

cairo_font_face_t * hb_cairo_font_face_create_for_face(hb_face_t * face) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_cairo_font_face_create_for_face(face);
}

hb_face_t * hb_cairo_font_face_get_face(cairo_font_face_t * font_face) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_cairo_font_face_get_face(font_face);
}

void hb_cairo_font_face_set_font_init_func(cairo_font_face_t * font_face, hb_cairo_font_init_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_cairo_font_face_set_font_init_func(font_face,func,user_data,destroy);
}

hb_font_t * hb_cairo_scaled_font_get_font(cairo_scaled_font_t * scaled_font) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_cairo_scaled_font_get_font(scaled_font);
}

void hb_cairo_font_face_set_scale_factor(cairo_font_face_t * font_face, unsigned int scale_factor) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_cairo_font_face_set_scale_factor(font_face,scale_factor);
}

unsigned int hb_cairo_font_face_get_scale_factor(cairo_font_face_t * font_face) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_cairo_font_face_get_scale_factor(font_face);
}

void hb_cairo_glyphs_from_buffer(hb_buffer_t * buffer, hb_bool_t utf8_clusters, double x_scale_factor, double y_scale_factor, double x, double y, const char * utf8, int utf8_len, cairo_glyph_t * *glyphs, unsigned int * num_glyphs, cairo_text_cluster_t * *clusters, unsigned int * num_clusters, cairo_text_cluster_flags_t * cluster_flags) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_cairo_glyphs_from_buffer(buffer,utf8_clusters,x_scale_factor,y_scale_factor,x,y,utf8,utf8_len,glyphs,num_glyphs,clusters,num_clusters,cluster_flags);
}

hb_tag_t hb_tag_from_string(const char * str, int len) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_tag_from_string(str,len);
}

void hb_tag_to_string(hb_tag_t tag, char * buf) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_tag_to_string(tag,buf);
}

hb_direction_t hb_direction_from_string(const char * str, int len) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_direction_from_string(str,len);
}

const char * hb_direction_to_string(hb_direction_t direction) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_direction_to_string(direction);
}

hb_language_t hb_language_from_string(const char * str, int len) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_language_from_string(str,len);
}

const char * hb_language_to_string(hb_language_t language) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_language_to_string(language);
}

hb_language_t hb_language_get_default() {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_language_get_default();
}

hb_bool_t hb_language_matches(hb_language_t language, hb_language_t specific) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_language_matches(language,specific);
}

hb_script_t hb_script_from_iso15924_tag(hb_tag_t tag) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_script_from_iso15924_tag(tag);
}

hb_script_t hb_script_from_string(const char * str, int len) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_script_from_string(str,len);
}

hb_tag_t hb_script_to_iso15924_tag(hb_script_t script) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_script_to_iso15924_tag(script);
}

hb_direction_t hb_script_get_horizontal_direction(hb_script_t script) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_script_get_horizontal_direction(script);
}

hb_bool_t hb_feature_from_string(const char * str, int len, hb_feature_t * feature) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_feature_from_string(str,len,feature);
}

void hb_feature_to_string(hb_feature_t * feature, char * buf, unsigned int size) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_feature_to_string(feature,buf,size);
}

hb_bool_t hb_variation_from_string(const char * str, int len, hb_variation_t * variation) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_variation_from_string(str,len,variation);
}

void hb_variation_to_string(hb_variation_t * variation, char * buf, unsigned int size) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_variation_to_string(variation,buf,size);
}

#undef hb_color_get_alpha
uint8_t hb_color_get_alpha(hb_color_t color) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_color_get_alpha(color);
}

#undef hb_color_get_red
uint8_t hb_color_get_red(hb_color_t color) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_color_get_red(color);
}

#undef hb_color_get_green
uint8_t hb_color_get_green(hb_color_t color) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_color_get_green(color);
}

#undef hb_color_get_blue
uint8_t hb_color_get_blue(hb_color_t color) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_color_get_blue(color);
}

void hb_font_funcs_set_glyph_func(hb_font_funcs_t * ffuncs, hb_font_get_glyph_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_funcs_set_glyph_func(ffuncs,func,user_data,destroy);
}

HB_DEPRECATED void hb_unicode_funcs_set_eastasian_width_func(hb_unicode_funcs_t * ufuncs, hb_unicode_eastasian_width_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_unicode_funcs_set_eastasian_width_func(ufuncs,func,user_data,destroy);
}

HB_DEPRECATED unsigned int hb_unicode_eastasian_width(hb_unicode_funcs_t * ufuncs, hb_codepoint_t unicode) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_unicode_eastasian_width(ufuncs,unicode);
}

HB_DEPRECATED void hb_unicode_funcs_set_decompose_compatibility_func(hb_unicode_funcs_t * ufuncs, hb_unicode_decompose_compatibility_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_unicode_funcs_set_decompose_compatibility_func(ufuncs,func,user_data,destroy);
}

HB_DEPRECATED unsigned int hb_unicode_decompose_compatibility(hb_unicode_funcs_t * ufuncs, hb_codepoint_t u, hb_codepoint_t * decomposed) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_unicode_decompose_compatibility(ufuncs,u,decomposed);
}

void hb_font_funcs_set_glyph_v_kerning_func(hb_font_funcs_t * ffuncs, hb_font_get_glyph_v_kerning_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_funcs_set_glyph_v_kerning_func(ffuncs,func,user_data,destroy);
}

hb_position_t hb_font_get_glyph_v_kerning(hb_font_t * font, hb_codepoint_t top_glyph, hb_codepoint_t bottom_glyph) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_get_glyph_v_kerning(font,top_glyph,bottom_glyph);
}

void hb_font_funcs_set_glyph_shape_func(hb_font_funcs_t * ffuncs, hb_font_get_glyph_shape_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_funcs_set_glyph_shape_func(ffuncs,func,user_data,destroy);
}

void hb_font_get_glyph_shape(hb_font_t * font, hb_codepoint_t glyph, hb_draw_funcs_t * dfuncs, void * draw_data) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_get_glyph_shape(font,glyph,dfuncs,draw_data);
}

void hb_draw_funcs_set_move_to_func(hb_draw_funcs_t * dfuncs, hb_draw_move_to_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_draw_funcs_set_move_to_func(dfuncs,func,user_data,destroy);
}

void hb_draw_funcs_set_line_to_func(hb_draw_funcs_t * dfuncs, hb_draw_line_to_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_draw_funcs_set_line_to_func(dfuncs,func,user_data,destroy);
}

void hb_draw_funcs_set_quadratic_to_func(hb_draw_funcs_t * dfuncs, hb_draw_quadratic_to_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_draw_funcs_set_quadratic_to_func(dfuncs,func,user_data,destroy);
}

void hb_draw_funcs_set_cubic_to_func(hb_draw_funcs_t * dfuncs, hb_draw_cubic_to_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_draw_funcs_set_cubic_to_func(dfuncs,func,user_data,destroy);
}

void hb_draw_funcs_set_close_path_func(hb_draw_funcs_t * dfuncs, hb_draw_close_path_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_draw_funcs_set_close_path_func(dfuncs,func,user_data,destroy);
}

hb_draw_funcs_t * hb_draw_funcs_create() {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_draw_funcs_create();
}

hb_draw_funcs_t * hb_draw_funcs_get_empty() {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_draw_funcs_get_empty();
}

hb_draw_funcs_t * hb_draw_funcs_reference(hb_draw_funcs_t * dfuncs) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_draw_funcs_reference(dfuncs);
}

void hb_draw_funcs_destroy(hb_draw_funcs_t * dfuncs) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_draw_funcs_destroy(dfuncs);
}

hb_bool_t hb_draw_funcs_set_user_data(hb_draw_funcs_t * dfuncs, hb_user_data_key_t * key, void * data, hb_destroy_func_t destroy, hb_bool_t replace) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_draw_funcs_set_user_data(dfuncs,key,data,destroy,replace);
}

void * hb_draw_funcs_get_user_data(const hb_draw_funcs_t * dfuncs, hb_user_data_key_t * key) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_draw_funcs_get_user_data(dfuncs,key);
}

void hb_draw_funcs_make_immutable(hb_draw_funcs_t * dfuncs) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_draw_funcs_make_immutable(dfuncs);
}

hb_bool_t hb_draw_funcs_is_immutable(hb_draw_funcs_t * dfuncs) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_draw_funcs_is_immutable(dfuncs);
}

void hb_draw_move_to(hb_draw_funcs_t * dfuncs, void * draw_data, hb_draw_state_t * st, float to_x, float to_y) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_draw_move_to(dfuncs,draw_data,st,to_x,to_y);
}

void hb_draw_line_to(hb_draw_funcs_t * dfuncs, void * draw_data, hb_draw_state_t * st, float to_x, float to_y) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_draw_line_to(dfuncs,draw_data,st,to_x,to_y);
}

void hb_draw_quadratic_to(hb_draw_funcs_t * dfuncs, void * draw_data, hb_draw_state_t * st, float control_x, float control_y, float to_x, float to_y) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_draw_quadratic_to(dfuncs,draw_data,st,control_x,control_y,to_x,to_y);
}

void hb_draw_cubic_to(hb_draw_funcs_t * dfuncs, void * draw_data, hb_draw_state_t * st, float control1_x, float control1_y, float control2_x, float control2_y, float to_x, float to_y) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_draw_cubic_to(dfuncs,draw_data,st,control1_x,control1_y,control2_x,control2_y,to_x,to_y);
}

void hb_draw_close_path(hb_draw_funcs_t * dfuncs, void * draw_data, hb_draw_state_t * st) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_draw_close_path(dfuncs,draw_data,st);
}

unsigned int hb_face_count(hb_blob_t * blob) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_face_count(blob);
}

hb_face_t * hb_face_create(hb_blob_t * blob, unsigned int index) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_face_create(blob,index);
}

hb_face_t * hb_face_create_for_tables(hb_reference_table_func_t reference_table_func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_face_create_for_tables(reference_table_func,user_data,destroy);
}

hb_face_t * hb_face_get_empty() {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_face_get_empty();
}

hb_face_t * hb_face_reference(hb_face_t * face) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_face_reference(face);
}

void hb_face_destroy(hb_face_t * face) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_face_destroy(face);
}

hb_bool_t hb_face_set_user_data(hb_face_t * face, hb_user_data_key_t * key, void * data, hb_destroy_func_t destroy, hb_bool_t replace) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_face_set_user_data(face,key,data,destroy,replace);
}

void * hb_face_get_user_data(const hb_face_t * face, hb_user_data_key_t * key) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_face_get_user_data(face,key);
}

void hb_face_make_immutable(hb_face_t * face) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_face_make_immutable(face);
}

hb_bool_t hb_face_is_immutable(const hb_face_t * face) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_face_is_immutable(face);
}

hb_blob_t * hb_face_reference_table(const hb_face_t * face, hb_tag_t tag) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_face_reference_table(face,tag);
}

hb_blob_t * hb_face_reference_blob(hb_face_t * face) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_face_reference_blob(face);
}

void hb_face_set_index(hb_face_t * face, unsigned int index) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_face_set_index(face,index);
}

unsigned int hb_face_get_index(const hb_face_t * face) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_face_get_index(face);
}

void hb_face_set_upem(hb_face_t * face, unsigned int upem) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_face_set_upem(face,upem);
}

unsigned int hb_face_get_upem(const hb_face_t * face) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_face_get_upem(face);
}

void hb_face_set_glyph_count(hb_face_t * face, unsigned int glyph_count) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_face_set_glyph_count(face,glyph_count);
}

unsigned int hb_face_get_glyph_count(const hb_face_t * face) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_face_get_glyph_count(face);
}

unsigned int hb_face_get_table_tags(const hb_face_t * face, unsigned int start_offset, unsigned int * table_count, hb_tag_t * table_tags) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_face_get_table_tags(face,start_offset,table_count,table_tags);
}

void hb_face_collect_unicodes(hb_face_t * face, hb_set_t * out) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_face_collect_unicodes(face,out);
}

void hb_face_collect_nominal_glyph_mapping(hb_face_t * face, hb_map_t * mapping, hb_set_t * unicodes) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_face_collect_nominal_glyph_mapping(face,mapping,unicodes);
}

void hb_face_collect_variation_selectors(hb_face_t * face, hb_set_t * out) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_face_collect_variation_selectors(face,out);
}

void hb_face_collect_variation_unicodes(hb_face_t * face, hb_codepoint_t variation_selector, hb_set_t * out) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_face_collect_variation_unicodes(face,variation_selector,out);
}

hb_face_t * hb_face_builder_create() {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_face_builder_create();
}

hb_bool_t hb_face_builder_add_table(hb_face_t * face, hb_tag_t tag, hb_blob_t * blob) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_face_builder_add_table(face,tag,blob);
}

void hb_face_builder_sort_tables(hb_face_t * face, const hb_tag_t * tags) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_face_builder_sort_tables(face,tags);
}

hb_font_funcs_t * hb_font_funcs_create() {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_funcs_create();
}

hb_font_funcs_t * hb_font_funcs_get_empty() {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_funcs_get_empty();
}

hb_font_funcs_t * hb_font_funcs_reference(hb_font_funcs_t * ffuncs) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_funcs_reference(ffuncs);
}

void hb_font_funcs_destroy(hb_font_funcs_t * ffuncs) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_funcs_destroy(ffuncs);
}

hb_bool_t hb_font_funcs_set_user_data(hb_font_funcs_t * ffuncs, hb_user_data_key_t * key, void * data, hb_destroy_func_t destroy, hb_bool_t replace) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_funcs_set_user_data(ffuncs,key,data,destroy,replace);
}

void * hb_font_funcs_get_user_data(const hb_font_funcs_t * ffuncs, hb_user_data_key_t * key) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_funcs_get_user_data(ffuncs,key);
}

void hb_font_funcs_make_immutable(hb_font_funcs_t * ffuncs) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_funcs_make_immutable(ffuncs);
}

hb_bool_t hb_font_funcs_is_immutable(hb_font_funcs_t * ffuncs) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_funcs_is_immutable(ffuncs);
}

void hb_font_funcs_set_font_h_extents_func(hb_font_funcs_t * ffuncs, hb_font_get_font_h_extents_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_funcs_set_font_h_extents_func(ffuncs,func,user_data,destroy);
}

void hb_font_funcs_set_font_v_extents_func(hb_font_funcs_t * ffuncs, hb_font_get_font_v_extents_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_funcs_set_font_v_extents_func(ffuncs,func,user_data,destroy);
}

void hb_font_funcs_set_nominal_glyph_func(hb_font_funcs_t * ffuncs, hb_font_get_nominal_glyph_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_funcs_set_nominal_glyph_func(ffuncs,func,user_data,destroy);
}

void hb_font_funcs_set_nominal_glyphs_func(hb_font_funcs_t * ffuncs, hb_font_get_nominal_glyphs_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_funcs_set_nominal_glyphs_func(ffuncs,func,user_data,destroy);
}

void hb_font_funcs_set_variation_glyph_func(hb_font_funcs_t * ffuncs, hb_font_get_variation_glyph_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_funcs_set_variation_glyph_func(ffuncs,func,user_data,destroy);
}

void hb_font_funcs_set_glyph_h_advance_func(hb_font_funcs_t * ffuncs, hb_font_get_glyph_h_advance_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_funcs_set_glyph_h_advance_func(ffuncs,func,user_data,destroy);
}

void hb_font_funcs_set_glyph_v_advance_func(hb_font_funcs_t * ffuncs, hb_font_get_glyph_v_advance_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_funcs_set_glyph_v_advance_func(ffuncs,func,user_data,destroy);
}

void hb_font_funcs_set_glyph_h_advances_func(hb_font_funcs_t * ffuncs, hb_font_get_glyph_h_advances_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_funcs_set_glyph_h_advances_func(ffuncs,func,user_data,destroy);
}

void hb_font_funcs_set_glyph_v_advances_func(hb_font_funcs_t * ffuncs, hb_font_get_glyph_v_advances_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_funcs_set_glyph_v_advances_func(ffuncs,func,user_data,destroy);
}

void hb_font_funcs_set_glyph_h_origin_func(hb_font_funcs_t * ffuncs, hb_font_get_glyph_h_origin_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_funcs_set_glyph_h_origin_func(ffuncs,func,user_data,destroy);
}

void hb_font_funcs_set_glyph_v_origin_func(hb_font_funcs_t * ffuncs, hb_font_get_glyph_v_origin_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_funcs_set_glyph_v_origin_func(ffuncs,func,user_data,destroy);
}

void hb_font_funcs_set_glyph_h_kerning_func(hb_font_funcs_t * ffuncs, hb_font_get_glyph_h_kerning_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_funcs_set_glyph_h_kerning_func(ffuncs,func,user_data,destroy);
}

void hb_font_funcs_set_glyph_extents_func(hb_font_funcs_t * ffuncs, hb_font_get_glyph_extents_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_funcs_set_glyph_extents_func(ffuncs,func,user_data,destroy);
}

void hb_font_funcs_set_glyph_contour_point_func(hb_font_funcs_t * ffuncs, hb_font_get_glyph_contour_point_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_funcs_set_glyph_contour_point_func(ffuncs,func,user_data,destroy);
}

void hb_font_funcs_set_glyph_name_func(hb_font_funcs_t * ffuncs, hb_font_get_glyph_name_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_funcs_set_glyph_name_func(ffuncs,func,user_data,destroy);
}

void hb_font_funcs_set_glyph_from_name_func(hb_font_funcs_t * ffuncs, hb_font_get_glyph_from_name_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_funcs_set_glyph_from_name_func(ffuncs,func,user_data,destroy);
}

void hb_font_funcs_set_draw_glyph_func(hb_font_funcs_t * ffuncs, hb_font_draw_glyph_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_funcs_set_draw_glyph_func(ffuncs,func,user_data,destroy);
}

void hb_font_funcs_set_paint_glyph_func(hb_font_funcs_t * ffuncs, hb_font_paint_glyph_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_funcs_set_paint_glyph_func(ffuncs,func,user_data,destroy);
}

hb_bool_t hb_font_get_h_extents(hb_font_t * font, hb_font_extents_t * extents) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_get_h_extents(font,extents);
}

hb_bool_t hb_font_get_v_extents(hb_font_t * font, hb_font_extents_t * extents) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_get_v_extents(font,extents);
}

hb_bool_t hb_font_get_nominal_glyph(hb_font_t * font, hb_codepoint_t unicode, hb_codepoint_t * glyph) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_get_nominal_glyph(font,unicode,glyph);
}

hb_bool_t hb_font_get_variation_glyph(hb_font_t * font, hb_codepoint_t unicode, hb_codepoint_t variation_selector, hb_codepoint_t * glyph) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_get_variation_glyph(font,unicode,variation_selector,glyph);
}

unsigned int hb_font_get_nominal_glyphs(hb_font_t * font, unsigned int count, const hb_codepoint_t * first_unicode, unsigned int unicode_stride, hb_codepoint_t * first_glyph, unsigned int glyph_stride) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_get_nominal_glyphs(font,count,first_unicode,unicode_stride,first_glyph,glyph_stride);
}

hb_position_t hb_font_get_glyph_h_advance(hb_font_t * font, hb_codepoint_t glyph) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_get_glyph_h_advance(font,glyph);
}

hb_position_t hb_font_get_glyph_v_advance(hb_font_t * font, hb_codepoint_t glyph) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_get_glyph_v_advance(font,glyph);
}

void hb_font_get_glyph_h_advances(hb_font_t* font, unsigned int count, const hb_codepoint_t * first_glyph, unsigned glyph_stride, hb_position_t * first_advance, unsigned advance_stride) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_get_glyph_h_advances(font,count,first_glyph,glyph_stride,first_advance,advance_stride);
}

void hb_font_get_glyph_v_advances(hb_font_t* font, unsigned int count, const hb_codepoint_t * first_glyph, unsigned glyph_stride, hb_position_t * first_advance, unsigned advance_stride) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_get_glyph_v_advances(font,count,first_glyph,glyph_stride,first_advance,advance_stride);
}

hb_bool_t hb_font_get_glyph_h_origin(hb_font_t * font, hb_codepoint_t glyph, hb_position_t * x, hb_position_t * y) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_get_glyph_h_origin(font,glyph,x,y);
}

hb_bool_t hb_font_get_glyph_v_origin(hb_font_t * font, hb_codepoint_t glyph, hb_position_t * x, hb_position_t * y) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_get_glyph_v_origin(font,glyph,x,y);
}

hb_position_t hb_font_get_glyph_h_kerning(hb_font_t * font, hb_codepoint_t left_glyph, hb_codepoint_t right_glyph) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_get_glyph_h_kerning(font,left_glyph,right_glyph);
}

hb_bool_t hb_font_get_glyph_extents(hb_font_t * font, hb_codepoint_t glyph, hb_glyph_extents_t * extents) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_get_glyph_extents(font,glyph,extents);
}

hb_bool_t hb_font_get_glyph_contour_point(hb_font_t * font, hb_codepoint_t glyph, unsigned int point_index, hb_position_t * x, hb_position_t * y) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_get_glyph_contour_point(font,glyph,point_index,x,y);
}

hb_bool_t hb_font_get_glyph_name(hb_font_t * font, hb_codepoint_t glyph, char * name, unsigned int size) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_get_glyph_name(font,glyph,name,size);
}

hb_bool_t hb_font_get_glyph_from_name(hb_font_t * font, const char * name, int len, hb_codepoint_t * glyph) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_get_glyph_from_name(font,name,len,glyph);
}

void hb_font_draw_glyph(hb_font_t * font, hb_codepoint_t glyph, hb_draw_funcs_t * dfuncs, void * draw_data) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_draw_glyph(font,glyph,dfuncs,draw_data);
}

void hb_font_paint_glyph(hb_font_t * font, hb_codepoint_t glyph, hb_paint_funcs_t * pfuncs, void * paint_data, unsigned int palette_index, hb_color_t foreground) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_paint_glyph(font,glyph,pfuncs,paint_data,palette_index,foreground);
}

hb_bool_t hb_font_get_glyph(hb_font_t * font, hb_codepoint_t unicode, hb_codepoint_t variation_selector, hb_codepoint_t * glyph) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_get_glyph(font,unicode,variation_selector,glyph);
}

void hb_font_get_extents_for_direction(hb_font_t * font, hb_direction_t direction, hb_font_extents_t * extents) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_get_extents_for_direction(font,direction,extents);
}

void hb_font_get_glyph_advance_for_direction(hb_font_t * font, hb_codepoint_t glyph, hb_direction_t direction, hb_position_t * x, hb_position_t * y) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_get_glyph_advance_for_direction(font,glyph,direction,x,y);
}

void hb_font_get_glyph_advances_for_direction(hb_font_t* font, hb_direction_t direction, unsigned int count, const hb_codepoint_t * first_glyph, unsigned glyph_stride, hb_position_t * first_advance, unsigned advance_stride) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_get_glyph_advances_for_direction(font,direction,count,first_glyph,glyph_stride,first_advance,advance_stride);
}

void hb_font_get_glyph_origin_for_direction(hb_font_t * font, hb_codepoint_t glyph, hb_direction_t direction, hb_position_t * x, hb_position_t * y) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_get_glyph_origin_for_direction(font,glyph,direction,x,y);
}

void hb_font_add_glyph_origin_for_direction(hb_font_t * font, hb_codepoint_t glyph, hb_direction_t direction, hb_position_t * x, hb_position_t * y) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_add_glyph_origin_for_direction(font,glyph,direction,x,y);
}

void hb_font_subtract_glyph_origin_for_direction(hb_font_t * font, hb_codepoint_t glyph, hb_direction_t direction, hb_position_t * x, hb_position_t * y) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_subtract_glyph_origin_for_direction(font,glyph,direction,x,y);
}

void hb_font_get_glyph_kerning_for_direction(hb_font_t * font, hb_codepoint_t first_glyph, hb_codepoint_t second_glyph, hb_direction_t direction, hb_position_t * x, hb_position_t * y) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_get_glyph_kerning_for_direction(font,first_glyph,second_glyph,direction,x,y);
}

hb_bool_t hb_font_get_glyph_extents_for_origin(hb_font_t * font, hb_codepoint_t glyph, hb_direction_t direction, hb_glyph_extents_t * extents) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_get_glyph_extents_for_origin(font,glyph,direction,extents);
}

hb_bool_t hb_font_get_glyph_contour_point_for_origin(hb_font_t * font, hb_codepoint_t glyph, unsigned int point_index, hb_direction_t direction, hb_position_t * x, hb_position_t * y) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_get_glyph_contour_point_for_origin(font,glyph,point_index,direction,x,y);
}

void hb_font_glyph_to_string(hb_font_t * font, hb_codepoint_t glyph, char * s, unsigned int size) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_glyph_to_string(font,glyph,s,size);
}

hb_bool_t hb_font_glyph_from_string(hb_font_t * font, const char * s, int len, hb_codepoint_t * glyph) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_glyph_from_string(font,s,len,glyph);
}

hb_font_t * hb_font_create(hb_face_t * face) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_create(face);
}

hb_font_t * hb_font_create_sub_font(hb_font_t * parent) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_create_sub_font(parent);
}

hb_font_t * hb_font_get_empty() {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_get_empty();
}

hb_font_t * hb_font_reference(hb_font_t * font) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_reference(font);
}

void hb_font_destroy(hb_font_t * font) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_destroy(font);
}

hb_bool_t hb_font_set_user_data(hb_font_t * font, hb_user_data_key_t * key, void * data, hb_destroy_func_t destroy, hb_bool_t replace) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_set_user_data(font,key,data,destroy,replace);
}

void * hb_font_get_user_data(const hb_font_t * font, hb_user_data_key_t * key) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_get_user_data(font,key);
}

void hb_font_make_immutable(hb_font_t * font) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_make_immutable(font);
}

hb_bool_t hb_font_is_immutable(hb_font_t * font) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_is_immutable(font);
}

unsigned int hb_font_get_serial(hb_font_t * font) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_get_serial(font);
}

void hb_font_changed(hb_font_t * font) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_changed(font);
}

void hb_font_set_parent(hb_font_t * font, hb_font_t * parent) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_set_parent(font,parent);
}

hb_font_t * hb_font_get_parent(hb_font_t * font) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_get_parent(font);
}

void hb_font_set_face(hb_font_t * font, hb_face_t * face) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_set_face(font,face);
}

hb_face_t * hb_font_get_face(hb_font_t * font) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_get_face(font);
}

void hb_font_set_funcs(hb_font_t * font, hb_font_funcs_t * klass, void * font_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_set_funcs(font,klass,font_data,destroy);
}

void hb_font_set_funcs_data(hb_font_t * font, void * font_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_set_funcs_data(font,font_data,destroy);
}

void hb_font_set_scale(hb_font_t * font, int x_scale, int y_scale) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_set_scale(font,x_scale,y_scale);
}

void hb_font_get_scale(hb_font_t * font, int * x_scale, int * y_scale) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_get_scale(font,x_scale,y_scale);
}

void hb_font_set_ppem(hb_font_t * font, unsigned int x_ppem, unsigned int y_ppem) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_set_ppem(font,x_ppem,y_ppem);
}

void hb_font_get_ppem(hb_font_t * font, unsigned int * x_ppem, unsigned int * y_ppem) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_get_ppem(font,x_ppem,y_ppem);
}

void hb_font_set_ptem(hb_font_t * font, float ptem) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_set_ptem(font,ptem);
}

float hb_font_get_ptem(hb_font_t * font) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_get_ptem(font);
}

void hb_font_set_synthetic_bold(hb_font_t * font, float x_embolden, float y_embolden, hb_bool_t in_place) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_set_synthetic_bold(font,x_embolden,y_embolden,in_place);
}

void hb_font_get_synthetic_bold(hb_font_t * font, float * x_embolden, float * y_embolden, hb_bool_t * in_place) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_get_synthetic_bold(font,x_embolden,y_embolden,in_place);
}

void hb_font_set_synthetic_slant(hb_font_t * font, float slant) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_set_synthetic_slant(font,slant);
}

float hb_font_get_synthetic_slant(hb_font_t * font) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_get_synthetic_slant(font);
}

void hb_font_set_variations(hb_font_t * font, const hb_variation_t * variations, unsigned int variations_length) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_set_variations(font,variations,variations_length);
}

void hb_font_set_variation(hb_font_t * font, hb_tag_t tag, float value) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_set_variation(font,tag,value);
}

void hb_font_set_var_coords_design(hb_font_t * font, const float * coords, unsigned int coords_length) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_set_var_coords_design(font,coords,coords_length);
}

const float * hb_font_get_var_coords_design(hb_font_t * font, unsigned int * length) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_get_var_coords_design(font,length);
}

void hb_font_set_var_coords_normalized(hb_font_t * font, const int * coords, unsigned int coords_length) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_set_var_coords_normalized(font,coords,coords_length);
}

const int * hb_font_get_var_coords_normalized(hb_font_t * font, unsigned int * length) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_get_var_coords_normalized(font,length);
}

void hb_font_set_var_named_instance(hb_font_t * font, unsigned int instance_index) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_font_set_var_named_instance(font,instance_index);
}

unsigned int hb_font_get_var_named_instance(hb_font_t * font) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_font_get_var_named_instance(font);
}

hb_face_t * hb_ft_face_create(FT_Face ft_face, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ft_face_create(ft_face,destroy);
}

hb_face_t * hb_ft_face_create_cached(FT_Face ft_face) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ft_face_create_cached(ft_face);
}

hb_face_t * hb_ft_face_create_referenced(FT_Face ft_face) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ft_face_create_referenced(ft_face);
}

hb_font_t * hb_ft_font_create(FT_Face ft_face, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ft_font_create(ft_face,destroy);
}

hb_font_t * hb_ft_font_create_referenced(FT_Face ft_face) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ft_font_create_referenced(ft_face);
}

FT_Face hb_ft_font_get_face(hb_font_t * font) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ft_font_get_face(font);
}

FT_Face hb_ft_font_lock_face(hb_font_t * font) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ft_font_lock_face(font);
}

void hb_ft_font_unlock_face(hb_font_t * font) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_ft_font_unlock_face(font);
}

void hb_ft_font_set_load_flags(hb_font_t * font, int load_flags) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_ft_font_set_load_flags(font,load_flags);
}

int hb_ft_font_get_load_flags(hb_font_t * font) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ft_font_get_load_flags(font);
}

void hb_ft_font_changed(hb_font_t * font) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_ft_font_changed(font);
}

hb_bool_t hb_ft_hb_font_changed(hb_font_t * font) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ft_hb_font_changed(font);
}

void hb_ft_font_set_funcs(hb_font_t * font) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_ft_font_set_funcs(font);
}

hb_map_t * hb_map_create() {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_map_create();
}

hb_map_t * hb_map_get_empty() {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_map_get_empty();
}

hb_map_t * hb_map_reference(hb_map_t * map) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_map_reference(map);
}

void hb_map_destroy(hb_map_t * map) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_map_destroy(map);
}

hb_bool_t hb_map_set_user_data(hb_map_t * map, hb_user_data_key_t * key, void * data, hb_destroy_func_t destroy, hb_bool_t replace) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_map_set_user_data(map,key,data,destroy,replace);
}

void * hb_map_get_user_data(const hb_map_t * map, hb_user_data_key_t * key) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_map_get_user_data(map,key);
}

hb_bool_t hb_map_allocation_successful(const hb_map_t * map) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_map_allocation_successful(map);
}

hb_map_t * hb_map_copy(const hb_map_t * map) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_map_copy(map);
}

void hb_map_clear(hb_map_t * map) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_map_clear(map);
}

hb_bool_t hb_map_is_empty(const hb_map_t * map) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_map_is_empty(map);
}

unsigned int hb_map_get_population(const hb_map_t * map) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_map_get_population(map);
}

hb_bool_t hb_map_is_equal(const hb_map_t * map, const hb_map_t * other) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_map_is_equal(map,other);
}

unsigned int hb_map_hash(const hb_map_t * map) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_map_hash(map);
}

void hb_map_set(hb_map_t * map, hb_codepoint_t key, hb_codepoint_t value) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_map_set(map,key,value);
}

hb_codepoint_t hb_map_get(const hb_map_t * map, hb_codepoint_t key) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_map_get(map,key);
}

void hb_map_del(hb_map_t * map, hb_codepoint_t key) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_map_del(map,key);
}

hb_bool_t hb_map_has(const hb_map_t * map, hb_codepoint_t key) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_map_has(map,key);
}

void hb_map_update(hb_map_t * map, const hb_map_t * other) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_map_update(map,other);
}

hb_bool_t hb_map_next(const hb_map_t * map, int * idx, hb_codepoint_t * key, hb_codepoint_t * value) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_map_next(map,idx,key,value);
}

void hb_map_keys(const hb_map_t * map, hb_set_t * keys) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_map_keys(map,keys);
}

void hb_map_values(const hb_map_t * map, hb_set_t * values) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_map_values(map,values);
}

hb_bool_t hb_ot_color_has_palettes(hb_face_t * face) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_color_has_palettes(face);
}

unsigned int hb_ot_color_palette_get_count(hb_face_t * face) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_color_palette_get_count(face);
}

hb_ot_name_id_t hb_ot_color_palette_get_name_id(hb_face_t * face, unsigned int palette_index) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_color_palette_get_name_id(face,palette_index);
}

hb_ot_name_id_t hb_ot_color_palette_color_get_name_id(hb_face_t * face, unsigned int color_index) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_color_palette_color_get_name_id(face,color_index);
}

hb_ot_color_palette_flags_t hb_ot_color_palette_get_flags(hb_face_t * face, unsigned int palette_index) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_color_palette_get_flags(face,palette_index);
}

unsigned int hb_ot_color_palette_get_colors(hb_face_t * face, unsigned int palette_index, unsigned int start_offset, unsigned int * color_count, hb_color_t * colors) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_color_palette_get_colors(face,palette_index,start_offset,color_count,colors);
}

hb_bool_t hb_ot_color_has_layers(hb_face_t * face) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_color_has_layers(face);
}

unsigned int hb_ot_color_glyph_get_layers(hb_face_t * face, hb_codepoint_t glyph, unsigned int start_offset, unsigned int * layer_count, hb_ot_color_layer_t * layers) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_color_glyph_get_layers(face,glyph,start_offset,layer_count,layers);
}

hb_bool_t hb_ot_color_has_paint(hb_face_t * face) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_color_has_paint(face);
}

hb_bool_t hb_ot_color_glyph_has_paint(hb_face_t * face, hb_codepoint_t glyph) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_color_glyph_has_paint(face,glyph);
}

hb_bool_t hb_ot_color_has_svg(hb_face_t * face) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_color_has_svg(face);
}

hb_blob_t * hb_ot_color_glyph_reference_svg(hb_face_t * face, hb_codepoint_t glyph) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_color_glyph_reference_svg(face,glyph);
}

hb_bool_t hb_ot_color_has_png(hb_face_t * face) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_color_has_png(face);
}

hb_blob_t * hb_ot_color_glyph_reference_png(hb_font_t * font, hb_codepoint_t glyph) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_color_glyph_reference_png(font,glyph);
}

hb_bool_t hb_ot_layout_table_choose_script(hb_face_t * face, hb_tag_t table_tag, const hb_tag_t * script_tags, unsigned int * script_index, hb_tag_t * chosen_script) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_table_choose_script(face,table_tag,script_tags,script_index,chosen_script);
}

hb_bool_t hb_ot_layout_script_find_language(hb_face_t * face, hb_tag_t table_tag, unsigned int script_index, hb_tag_t language_tag, unsigned int * language_index) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_script_find_language(face,table_tag,script_index,language_tag,language_index);
}

void hb_ot_tags_from_script(hb_script_t script, hb_tag_t * script_tag_1, hb_tag_t * script_tag_2) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_ot_tags_from_script(script,script_tag_1,script_tag_2);
}

hb_tag_t hb_ot_tag_from_language(hb_language_t language) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_tag_from_language(language);
}

unsigned int hb_ot_var_get_axes(hb_face_t * face, unsigned int start_offset, unsigned int * axes_count, hb_ot_var_axis_t * axes_array) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_var_get_axes(face,start_offset,axes_count,axes_array);
}

hb_bool_t hb_ot_var_find_axis(hb_face_t * face, hb_tag_t axis_tag, unsigned int * axis_index, hb_ot_var_axis_t * axis_info) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_var_find_axis(face,axis_tag,axis_index,axis_info);
}

void hb_ot_font_set_funcs(hb_font_t * font) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_ot_font_set_funcs(font);
}

void hb_ot_tags_from_script_and_language(hb_script_t script, hb_language_t language, unsigned int * script_count, hb_tag_t * script_tags, unsigned int * language_count, hb_tag_t * language_tags) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_ot_tags_from_script_and_language(script,language,script_count,script_tags,language_count,language_tags);
}

hb_script_t hb_ot_tag_to_script(hb_tag_t tag) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_tag_to_script(tag);
}

hb_language_t hb_ot_tag_to_language(hb_tag_t tag) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_tag_to_language(tag);
}

void hb_ot_tags_to_script_and_language(hb_tag_t script_tag, hb_tag_t language_tag, hb_script_t * script, hb_language_t * language) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_ot_tags_to_script_and_language(script_tag,language_tag,script,language);
}

hb_bool_t hb_ot_layout_has_glyph_classes(hb_face_t * face) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_has_glyph_classes(face);
}

hb_ot_layout_glyph_class_t hb_ot_layout_get_glyph_class(hb_face_t * face, hb_codepoint_t glyph) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_get_glyph_class(face,glyph);
}

void hb_ot_layout_get_glyphs_in_class(hb_face_t * face, hb_ot_layout_glyph_class_t klass, hb_set_t * glyphs) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_ot_layout_get_glyphs_in_class(face,klass,glyphs);
}

unsigned int hb_ot_layout_get_attach_points(hb_face_t * face, hb_codepoint_t glyph, unsigned int start_offset, unsigned int * point_count, unsigned int * point_array) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_get_attach_points(face,glyph,start_offset,point_count,point_array);
}

unsigned int hb_ot_layout_get_ligature_carets(hb_font_t * font, hb_direction_t direction, hb_codepoint_t glyph, unsigned int start_offset, unsigned int * caret_count, hb_position_t * caret_array) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_get_ligature_carets(font,direction,glyph,start_offset,caret_count,caret_array);
}

unsigned int hb_ot_layout_table_get_script_tags(hb_face_t * face, hb_tag_t table_tag, unsigned int start_offset, unsigned int * script_count, hb_tag_t * script_tags) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_table_get_script_tags(face,table_tag,start_offset,script_count,script_tags);
}

hb_bool_t hb_ot_layout_table_find_script(hb_face_t * face, hb_tag_t table_tag, hb_tag_t script_tag, unsigned int * script_index) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_table_find_script(face,table_tag,script_tag,script_index);
}

hb_bool_t hb_ot_layout_table_select_script(hb_face_t * face, hb_tag_t table_tag, unsigned int script_count, const hb_tag_t * script_tags, unsigned int * script_index, hb_tag_t * chosen_script) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_table_select_script(face,table_tag,script_count,script_tags,script_index,chosen_script);
}

unsigned int hb_ot_layout_table_get_feature_tags(hb_face_t * face, hb_tag_t table_tag, unsigned int start_offset, unsigned int * feature_count, hb_tag_t * feature_tags) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_table_get_feature_tags(face,table_tag,start_offset,feature_count,feature_tags);
}

unsigned int hb_ot_layout_script_get_language_tags(hb_face_t * face, hb_tag_t table_tag, unsigned int script_index, unsigned int start_offset, unsigned int * language_count, hb_tag_t * language_tags) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_script_get_language_tags(face,table_tag,script_index,start_offset,language_count,language_tags);
}

hb_bool_t hb_ot_layout_script_select_language(hb_face_t * face, hb_tag_t table_tag, unsigned int script_index, unsigned int language_count, const hb_tag_t * language_tags, unsigned int * language_index) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_script_select_language(face,table_tag,script_index,language_count,language_tags,language_index);
}

hb_bool_t hb_ot_layout_script_select_language2(hb_face_t * face, hb_tag_t table_tag, unsigned int script_index, unsigned int language_count, const hb_tag_t * language_tags, unsigned int * language_index, hb_tag_t * chosen_language) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_script_select_language2(face,table_tag,script_index,language_count,language_tags,language_index,chosen_language);
}

hb_bool_t hb_ot_layout_language_get_required_feature_index(hb_face_t * face, hb_tag_t table_tag, unsigned int script_index, unsigned int language_index, unsigned int * feature_index) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_language_get_required_feature_index(face,table_tag,script_index,language_index,feature_index);
}

hb_bool_t hb_ot_layout_language_get_required_feature(hb_face_t * face, hb_tag_t table_tag, unsigned int script_index, unsigned int language_index, unsigned int * feature_index, hb_tag_t * feature_tag) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_language_get_required_feature(face,table_tag,script_index,language_index,feature_index,feature_tag);
}

unsigned int hb_ot_layout_language_get_feature_indexes(hb_face_t * face, hb_tag_t table_tag, unsigned int script_index, unsigned int language_index, unsigned int start_offset, unsigned int * feature_count, unsigned int * feature_indexes) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_language_get_feature_indexes(face,table_tag,script_index,language_index,start_offset,feature_count,feature_indexes);
}

unsigned int hb_ot_layout_language_get_feature_tags(hb_face_t * face, hb_tag_t table_tag, unsigned int script_index, unsigned int language_index, unsigned int start_offset, unsigned int * feature_count, hb_tag_t * feature_tags) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_language_get_feature_tags(face,table_tag,script_index,language_index,start_offset,feature_count,feature_tags);
}

hb_bool_t hb_ot_layout_language_find_feature(hb_face_t * face, hb_tag_t table_tag, unsigned int script_index, unsigned int language_index, hb_tag_t feature_tag, unsigned int * feature_index) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_language_find_feature(face,table_tag,script_index,language_index,feature_tag,feature_index);
}

unsigned int hb_ot_layout_feature_get_lookups(hb_face_t * face, hb_tag_t table_tag, unsigned int feature_index, unsigned int start_offset, unsigned int * lookup_count, unsigned int * lookup_indexes) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_feature_get_lookups(face,table_tag,feature_index,start_offset,lookup_count,lookup_indexes);
}

unsigned int hb_ot_layout_table_get_lookup_count(hb_face_t * face, hb_tag_t table_tag) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_table_get_lookup_count(face,table_tag);
}

void hb_ot_layout_collect_features(hb_face_t * face, hb_tag_t table_tag, const hb_tag_t * scripts, const hb_tag_t * languages, const hb_tag_t * features, hb_set_t * feature_indexes) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_ot_layout_collect_features(face,table_tag,scripts,languages,features,feature_indexes);
}

void hb_ot_layout_collect_features_map(hb_face_t * face, hb_tag_t table_tag, unsigned script_index, unsigned language_index, hb_map_t * feature_map) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_ot_layout_collect_features_map(face,table_tag,script_index,language_index,feature_map);
}

void hb_ot_layout_collect_lookups(hb_face_t * face, hb_tag_t table_tag, const hb_tag_t * scripts, const hb_tag_t * languages, const hb_tag_t * features, hb_set_t * lookup_indexes) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_ot_layout_collect_lookups(face,table_tag,scripts,languages,features,lookup_indexes);
}

void hb_ot_layout_lookup_collect_glyphs(hb_face_t * face, hb_tag_t table_tag, unsigned int lookup_index, hb_set_t * glyphs_before, hb_set_t * glyphs_input, hb_set_t * glyphs_after, hb_set_t * glyphs_output) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_ot_layout_lookup_collect_glyphs(face,table_tag,lookup_index,glyphs_before,glyphs_input,glyphs_after,glyphs_output);
}

hb_bool_t hb_ot_layout_table_find_feature_variations(hb_face_t * face, hb_tag_t table_tag, const int * coords, unsigned int num_coords, unsigned int * variations_index) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_table_find_feature_variations(face,table_tag,coords,num_coords,variations_index);
}

unsigned int hb_ot_layout_feature_with_variations_get_lookups(hb_face_t * face, hb_tag_t table_tag, unsigned int feature_index, unsigned int variations_index, unsigned int start_offset, unsigned int * lookup_count, unsigned int * lookup_indexes) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_feature_with_variations_get_lookups(face,table_tag,feature_index,variations_index,start_offset,lookup_count,lookup_indexes);
}

hb_bool_t hb_ot_layout_has_substitution(hb_face_t * face) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_has_substitution(face);
}

unsigned hb_ot_layout_lookup_get_glyph_alternates(hb_face_t * face, unsigned lookup_index, hb_codepoint_t glyph, unsigned start_offset, unsigned * alternate_count, hb_codepoint_t * alternate_glyphs) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_lookup_get_glyph_alternates(face,lookup_index,glyph,start_offset,alternate_count,alternate_glyphs);
}

hb_bool_t hb_ot_layout_lookup_would_substitute(hb_face_t * face, unsigned int lookup_index, const hb_codepoint_t * glyphs, unsigned int glyphs_length, hb_bool_t zero_context) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_lookup_would_substitute(face,lookup_index,glyphs,glyphs_length,zero_context);
}

void hb_ot_layout_lookup_substitute_closure(hb_face_t * face, unsigned int lookup_index, hb_set_t * glyphs) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_ot_layout_lookup_substitute_closure(face,lookup_index,glyphs);
}

void hb_ot_layout_lookups_substitute_closure(hb_face_t * face, const hb_set_t * lookups, hb_set_t * glyphs) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_ot_layout_lookups_substitute_closure(face,lookups,glyphs);
}

hb_bool_t hb_ot_layout_has_positioning(hb_face_t * face) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_has_positioning(face);
}

hb_bool_t hb_ot_layout_get_size_params(hb_face_t * face, unsigned int * design_size, unsigned int * subfamily_id, hb_ot_name_id_t * subfamily_name_id, unsigned int * range_start, unsigned int * range_end) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_get_size_params(face,design_size,subfamily_id,subfamily_name_id,range_start,range_end);
}

hb_position_t hb_ot_layout_lookup_get_optical_bound(hb_font_t * font, unsigned lookup_index, hb_direction_t direction, hb_codepoint_t glyph) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_lookup_get_optical_bound(font,lookup_index,direction,glyph);
}

hb_bool_t hb_ot_layout_feature_get_name_ids(hb_face_t * face, hb_tag_t table_tag, unsigned int feature_index, hb_ot_name_id_t * label_id, hb_ot_name_id_t * tooltip_id, hb_ot_name_id_t * sample_id, unsigned int * num_named_parameters, hb_ot_name_id_t * first_param_id) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_feature_get_name_ids(face,table_tag,feature_index,label_id,tooltip_id,sample_id,num_named_parameters,first_param_id);
}

unsigned int hb_ot_layout_feature_get_characters(hb_face_t * face, hb_tag_t table_tag, unsigned int feature_index, unsigned int start_offset, unsigned int * char_count, hb_codepoint_t * characters) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_feature_get_characters(face,table_tag,feature_index,start_offset,char_count,characters);
}

hb_bool_t hb_ot_layout_get_font_extents(hb_font_t * font, hb_direction_t direction, hb_tag_t script_tag, hb_tag_t language_tag, hb_font_extents_t * extents) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_get_font_extents(font,direction,script_tag,language_tag,extents);
}

hb_bool_t hb_ot_layout_get_font_extents2(hb_font_t * font, hb_direction_t direction, hb_script_t script, hb_language_t language, hb_font_extents_t * extents) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_get_font_extents2(font,direction,script,language,extents);
}

hb_ot_layout_baseline_tag_t hb_ot_layout_get_horizontal_baseline_tag_for_script(hb_script_t script) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_get_horizontal_baseline_tag_for_script(script);
}

hb_bool_t hb_ot_layout_get_baseline(hb_font_t * font, hb_ot_layout_baseline_tag_t baseline_tag, hb_direction_t direction, hb_tag_t script_tag, hb_tag_t language_tag, hb_position_t * coord) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_get_baseline(font,baseline_tag,direction,script_tag,language_tag,coord);
}

hb_bool_t hb_ot_layout_get_baseline2(hb_font_t * font, hb_ot_layout_baseline_tag_t baseline_tag, hb_direction_t direction, hb_script_t script, hb_language_t language, hb_position_t * coord) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_layout_get_baseline2(font,baseline_tag,direction,script,language,coord);
}

void hb_ot_layout_get_baseline_with_fallback(hb_font_t * font, hb_ot_layout_baseline_tag_t baseline_tag, hb_direction_t direction, hb_tag_t script_tag, hb_tag_t language_tag, hb_position_t * coord) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_ot_layout_get_baseline_with_fallback(font,baseline_tag,direction,script_tag,language_tag,coord);
}

void hb_ot_layout_get_baseline_with_fallback2(hb_font_t * font, hb_ot_layout_baseline_tag_t baseline_tag, hb_direction_t direction, hb_script_t script, hb_language_t language, hb_position_t * coord) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_ot_layout_get_baseline_with_fallback2(font,baseline_tag,direction,script,language,coord);
}

hb_bool_t hb_ot_math_has_data(hb_face_t * face) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_math_has_data(face);
}

hb_position_t hb_ot_math_get_constant(hb_font_t * font, hb_ot_math_constant_t constant) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_math_get_constant(font,constant);
}

hb_position_t hb_ot_math_get_glyph_italics_correction(hb_font_t * font, hb_codepoint_t glyph) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_math_get_glyph_italics_correction(font,glyph);
}

hb_position_t hb_ot_math_get_glyph_top_accent_attachment(hb_font_t * font, hb_codepoint_t glyph) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_math_get_glyph_top_accent_attachment(font,glyph);
}

hb_bool_t hb_ot_math_is_glyph_extended_shape(hb_face_t * face, hb_codepoint_t glyph) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_math_is_glyph_extended_shape(face,glyph);
}

hb_position_t hb_ot_math_get_glyph_kerning(hb_font_t * font, hb_codepoint_t glyph, hb_ot_math_kern_t kern, hb_position_t correction_height) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_math_get_glyph_kerning(font,glyph,kern,correction_height);
}

unsigned int hb_ot_math_get_glyph_kernings(hb_font_t * font, hb_codepoint_t glyph, hb_ot_math_kern_t kern, unsigned int start_offset, unsigned int * entries_count, hb_ot_math_kern_entry_t * kern_entries) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_math_get_glyph_kernings(font,glyph,kern,start_offset,entries_count,kern_entries);
}

unsigned int hb_ot_math_get_glyph_variants(hb_font_t * font, hb_codepoint_t glyph, hb_direction_t direction, unsigned int start_offset, unsigned int * variants_count, hb_ot_math_glyph_variant_t * variants) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_math_get_glyph_variants(font,glyph,direction,start_offset,variants_count,variants);
}

hb_position_t hb_ot_math_get_min_connector_overlap(hb_font_t * font, hb_direction_t direction) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_math_get_min_connector_overlap(font,direction);
}

unsigned int hb_ot_math_get_glyph_assembly(hb_font_t * font, hb_codepoint_t glyph, hb_direction_t direction, unsigned int start_offset, unsigned int * parts_count, hb_ot_math_glyph_part_t * parts, hb_position_t * italics_correction) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_math_get_glyph_assembly(font,glyph,direction,start_offset,parts_count,parts,italics_correction);
}

unsigned int hb_ot_meta_get_entry_tags(hb_face_t * face, unsigned int start_offset, unsigned int * entries_count, hb_ot_meta_tag_t * entries) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_meta_get_entry_tags(face,start_offset,entries_count,entries);
}

hb_blob_t * hb_ot_meta_reference_entry(hb_face_t * face, hb_ot_meta_tag_t meta_tag) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_meta_reference_entry(face,meta_tag);
}

hb_bool_t hb_ot_metrics_get_position(hb_font_t * font, hb_ot_metrics_tag_t metrics_tag, hb_position_t * position) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_metrics_get_position(font,metrics_tag,position);
}

void hb_ot_metrics_get_position_with_fallback(hb_font_t * font, hb_ot_metrics_tag_t metrics_tag, hb_position_t * position) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_ot_metrics_get_position_with_fallback(font,metrics_tag,position);
}

float hb_ot_metrics_get_variation(hb_font_t * font, hb_ot_metrics_tag_t metrics_tag) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_metrics_get_variation(font,metrics_tag);
}

hb_position_t hb_ot_metrics_get_x_variation(hb_font_t * font, hb_ot_metrics_tag_t metrics_tag) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_metrics_get_x_variation(font,metrics_tag);
}

hb_position_t hb_ot_metrics_get_y_variation(hb_font_t * font, hb_ot_metrics_tag_t metrics_tag) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_metrics_get_y_variation(font,metrics_tag);
}

const hb_ot_name_entry_t * hb_ot_name_list_names(hb_face_t * face, unsigned int * num_entries) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_name_list_names(face,num_entries);
}

unsigned int hb_ot_name_get_utf8(hb_face_t * face, hb_ot_name_id_t name_id, hb_language_t language, unsigned int * text_size, char * text) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_name_get_utf8(face,name_id,language,text_size,text);
}

unsigned int hb_ot_name_get_utf16(hb_face_t * face, hb_ot_name_id_t name_id, hb_language_t language, unsigned int * text_size, uint16_t * text) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_name_get_utf16(face,name_id,language,text_size,text);
}

unsigned int hb_ot_name_get_utf32(hb_face_t * face, hb_ot_name_id_t name_id, hb_language_t language, unsigned int * text_size, uint32_t * text) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_name_get_utf32(face,name_id,language,text_size,text);
}

void hb_ot_shape_glyphs_closure(hb_font_t * font, hb_buffer_t * buffer, const hb_feature_t * features, unsigned int num_features, hb_set_t * glyphs) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_ot_shape_glyphs_closure(font,buffer,features,num_features,glyphs);
}

void hb_ot_shape_plan_collect_lookups(hb_shape_plan_t * shape_plan, hb_tag_t table_tag, hb_set_t * lookup_indexes) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_ot_shape_plan_collect_lookups(shape_plan,table_tag,lookup_indexes);
}

hb_bool_t hb_ot_var_has_data(hb_face_t * face) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_var_has_data(face);
}

unsigned int hb_ot_var_get_axis_count(hb_face_t * face) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_var_get_axis_count(face);
}

unsigned int hb_ot_var_get_axis_infos(hb_face_t * face, unsigned int start_offset, unsigned int * axes_count, hb_ot_var_axis_info_t * axes_array) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_var_get_axis_infos(face,start_offset,axes_count,axes_array);
}

hb_bool_t hb_ot_var_find_axis_info(hb_face_t * face, hb_tag_t axis_tag, hb_ot_var_axis_info_t * axis_info) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_var_find_axis_info(face,axis_tag,axis_info);
}

unsigned int hb_ot_var_get_named_instance_count(hb_face_t * face) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_var_get_named_instance_count(face);
}

hb_ot_name_id_t hb_ot_var_named_instance_get_subfamily_name_id(hb_face_t * face, unsigned int instance_index) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_var_named_instance_get_subfamily_name_id(face,instance_index);
}

hb_ot_name_id_t hb_ot_var_named_instance_get_postscript_name_id(hb_face_t * face, unsigned int instance_index) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_var_named_instance_get_postscript_name_id(face,instance_index);
}

unsigned int hb_ot_var_named_instance_get_design_coords(hb_face_t * face, unsigned int instance_index, unsigned int * coords_length, float * coords) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_ot_var_named_instance_get_design_coords(face,instance_index,coords_length,coords);
}

void hb_ot_var_normalize_variations(hb_face_t * face, const hb_variation_t * variations, unsigned int variations_length, int * coords, unsigned int coords_length) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_ot_var_normalize_variations(face,variations,variations_length,coords,coords_length);
}

void hb_ot_var_normalize_coords(hb_face_t * face, unsigned int coords_length, const float * design_coords, int * normalized_coords) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_ot_var_normalize_coords(face,coords_length,design_coords,normalized_coords);
}

hb_paint_funcs_t * hb_paint_funcs_create() {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_paint_funcs_create();
}

hb_paint_funcs_t * hb_paint_funcs_get_empty() {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_paint_funcs_get_empty();
}

hb_paint_funcs_t * hb_paint_funcs_reference(hb_paint_funcs_t * funcs) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_paint_funcs_reference(funcs);
}

void hb_paint_funcs_destroy(hb_paint_funcs_t * funcs) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_paint_funcs_destroy(funcs);
}

hb_bool_t hb_paint_funcs_set_user_data(hb_paint_funcs_t * funcs, hb_user_data_key_t * key, void * data, hb_destroy_func_t destroy, hb_bool_t replace) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_paint_funcs_set_user_data(funcs,key,data,destroy,replace);
}

void * hb_paint_funcs_get_user_data(const hb_paint_funcs_t * funcs, hb_user_data_key_t * key) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_paint_funcs_get_user_data(funcs,key);
}

void hb_paint_funcs_make_immutable(hb_paint_funcs_t * funcs) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_paint_funcs_make_immutable(funcs);
}

hb_bool_t hb_paint_funcs_is_immutable(hb_paint_funcs_t * funcs) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_paint_funcs_is_immutable(funcs);
}

unsigned int hb_color_line_get_color_stops(hb_color_line_t * color_line, unsigned int start, unsigned int * count, hb_color_stop_t * color_stops) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_color_line_get_color_stops(color_line,start,count,color_stops);
}

hb_paint_extend_t hb_color_line_get_extend(hb_color_line_t * color_line) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_color_line_get_extend(color_line);
}

void hb_paint_funcs_set_push_transform_func(hb_paint_funcs_t * funcs, hb_paint_push_transform_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_paint_funcs_set_push_transform_func(funcs,func,user_data,destroy);
}

void hb_paint_funcs_set_pop_transform_func(hb_paint_funcs_t * funcs, hb_paint_pop_transform_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_paint_funcs_set_pop_transform_func(funcs,func,user_data,destroy);
}

void hb_paint_funcs_set_color_glyph_func(hb_paint_funcs_t * funcs, hb_paint_color_glyph_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_paint_funcs_set_color_glyph_func(funcs,func,user_data,destroy);
}

void hb_paint_funcs_set_push_clip_glyph_func(hb_paint_funcs_t * funcs, hb_paint_push_clip_glyph_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_paint_funcs_set_push_clip_glyph_func(funcs,func,user_data,destroy);
}

void hb_paint_funcs_set_push_clip_rectangle_func(hb_paint_funcs_t * funcs, hb_paint_push_clip_rectangle_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_paint_funcs_set_push_clip_rectangle_func(funcs,func,user_data,destroy);
}

void hb_paint_funcs_set_pop_clip_func(hb_paint_funcs_t * funcs, hb_paint_pop_clip_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_paint_funcs_set_pop_clip_func(funcs,func,user_data,destroy);
}

void hb_paint_funcs_set_color_func(hb_paint_funcs_t * funcs, hb_paint_color_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_paint_funcs_set_color_func(funcs,func,user_data,destroy);
}

void hb_paint_funcs_set_image_func(hb_paint_funcs_t * funcs, hb_paint_image_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_paint_funcs_set_image_func(funcs,func,user_data,destroy);
}

void hb_paint_funcs_set_linear_gradient_func(hb_paint_funcs_t * funcs, hb_paint_linear_gradient_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_paint_funcs_set_linear_gradient_func(funcs,func,user_data,destroy);
}

void hb_paint_funcs_set_radial_gradient_func(hb_paint_funcs_t * funcs, hb_paint_radial_gradient_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_paint_funcs_set_radial_gradient_func(funcs,func,user_data,destroy);
}

void hb_paint_funcs_set_sweep_gradient_func(hb_paint_funcs_t * funcs, hb_paint_sweep_gradient_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_paint_funcs_set_sweep_gradient_func(funcs,func,user_data,destroy);
}

void hb_paint_funcs_set_push_group_func(hb_paint_funcs_t * funcs, hb_paint_push_group_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_paint_funcs_set_push_group_func(funcs,func,user_data,destroy);
}

void hb_paint_funcs_set_pop_group_func(hb_paint_funcs_t * funcs, hb_paint_pop_group_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_paint_funcs_set_pop_group_func(funcs,func,user_data,destroy);
}

void hb_paint_funcs_set_custom_palette_color_func(hb_paint_funcs_t * funcs, hb_paint_custom_palette_color_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_paint_funcs_set_custom_palette_color_func(funcs,func,user_data,destroy);
}

void hb_paint_push_transform(hb_paint_funcs_t * funcs, void * paint_data, float xx, float yx, float xy, float yy, float dx, float dy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_paint_push_transform(funcs,paint_data,xx,yx,xy,yy,dx,dy);
}

void hb_paint_pop_transform(hb_paint_funcs_t * funcs, void * paint_data) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_paint_pop_transform(funcs,paint_data);
}

hb_bool_t hb_paint_color_glyph(hb_paint_funcs_t * funcs, void * paint_data, hb_codepoint_t glyph, hb_font_t * font) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_paint_color_glyph(funcs,paint_data,glyph,font);
}

void hb_paint_push_clip_glyph(hb_paint_funcs_t * funcs, void * paint_data, hb_codepoint_t glyph, hb_font_t * font) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_paint_push_clip_glyph(funcs,paint_data,glyph,font);
}

void hb_paint_push_clip_rectangle(hb_paint_funcs_t * funcs, void * paint_data, float xmin, float ymin, float xmax, float ymax) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_paint_push_clip_rectangle(funcs,paint_data,xmin,ymin,xmax,ymax);
}

void hb_paint_pop_clip(hb_paint_funcs_t * funcs, void * paint_data) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_paint_pop_clip(funcs,paint_data);
}

void hb_paint_color(hb_paint_funcs_t * funcs, void * paint_data, hb_bool_t is_foreground, hb_color_t color) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_paint_color(funcs,paint_data,is_foreground,color);
}

void hb_paint_image(hb_paint_funcs_t * funcs, void * paint_data, hb_blob_t * image, unsigned int width, unsigned int height, hb_tag_t format, float slant, hb_glyph_extents_t * extents) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_paint_image(funcs,paint_data,image,width,height,format,slant,extents);
}

void hb_paint_linear_gradient(hb_paint_funcs_t * funcs, void * paint_data, hb_color_line_t * color_line, float x0, float y0, float x1, float y1, float x2, float y2) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_paint_linear_gradient(funcs,paint_data,color_line,x0,y0,x1,y1,x2,y2);
}

void hb_paint_radial_gradient(hb_paint_funcs_t * funcs, void * paint_data, hb_color_line_t * color_line, float x0, float y0, float r0, float x1, float y1, float r1) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_paint_radial_gradient(funcs,paint_data,color_line,x0,y0,r0,x1,y1,r1);
}

void hb_paint_sweep_gradient(hb_paint_funcs_t * funcs, void * paint_data, hb_color_line_t * color_line, float x0, float y0, float start_angle, float end_angle) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_paint_sweep_gradient(funcs,paint_data,color_line,x0,y0,start_angle,end_angle);
}

void hb_paint_push_group(hb_paint_funcs_t * funcs, void * paint_data) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_paint_push_group(funcs,paint_data);
}

void hb_paint_pop_group(hb_paint_funcs_t * funcs, void * paint_data, hb_paint_composite_mode_t mode) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_paint_pop_group(funcs,paint_data,mode);
}

hb_bool_t hb_paint_custom_palette_color(hb_paint_funcs_t * funcs, void * paint_data, unsigned int color_index, hb_color_t * color) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_paint_custom_palette_color(funcs,paint_data,color_index,color);
}

hb_set_t * hb_set_create() {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_set_create();
}

hb_set_t * hb_set_get_empty() {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_set_get_empty();
}

hb_set_t * hb_set_reference(hb_set_t * set) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_set_reference(set);
}

void hb_set_destroy(hb_set_t * set) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_set_destroy(set);
}

hb_bool_t hb_set_set_user_data(hb_set_t * set, hb_user_data_key_t * key, void * data, hb_destroy_func_t destroy, hb_bool_t replace) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_set_set_user_data(set,key,data,destroy,replace);
}

void * hb_set_get_user_data(const hb_set_t * set, hb_user_data_key_t * key) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_set_get_user_data(set,key);
}

hb_bool_t hb_set_allocation_successful(const hb_set_t * set) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_set_allocation_successful(set);
}

hb_set_t * hb_set_copy(const hb_set_t * set) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_set_copy(set);
}

void hb_set_clear(hb_set_t * set) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_set_clear(set);
}

hb_bool_t hb_set_is_empty(const hb_set_t * set) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_set_is_empty(set);
}

void hb_set_invert(hb_set_t * set) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_set_invert(set);
}

hb_bool_t hb_set_is_inverted(const hb_set_t * set) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_set_is_inverted(set);
}

hb_bool_t hb_set_has(const hb_set_t * set, hb_codepoint_t codepoint) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_set_has(set,codepoint);
}

void hb_set_add(hb_set_t * set, hb_codepoint_t codepoint) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_set_add(set,codepoint);
}

void hb_set_add_range(hb_set_t * set, hb_codepoint_t first, hb_codepoint_t last) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_set_add_range(set,first,last);
}

void hb_set_add_sorted_array(hb_set_t * set, const hb_codepoint_t * sorted_codepoints, unsigned int num_codepoints) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_set_add_sorted_array(set,sorted_codepoints,num_codepoints);
}

void hb_set_del(hb_set_t * set, hb_codepoint_t codepoint) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_set_del(set,codepoint);
}

void hb_set_del_range(hb_set_t * set, hb_codepoint_t first, hb_codepoint_t last) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_set_del_range(set,first,last);
}

hb_bool_t hb_set_is_equal(const hb_set_t * set, const hb_set_t * other) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_set_is_equal(set,other);
}

unsigned int hb_set_hash(const hb_set_t * set) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_set_hash(set);
}

hb_bool_t hb_set_is_subset(const hb_set_t * set, const hb_set_t * larger_set) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_set_is_subset(set,larger_set);
}

void hb_set_set(hb_set_t * set, const hb_set_t * other) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_set_set(set,other);
}

void hb_set_union(hb_set_t * set, const hb_set_t * other) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_set_union(set,other);
}

void hb_set_intersect(hb_set_t * set, const hb_set_t * other) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_set_intersect(set,other);
}

void hb_set_subtract(hb_set_t * set, const hb_set_t * other) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_set_subtract(set,other);
}

void hb_set_symmetric_difference(hb_set_t * set, const hb_set_t * other) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_set_symmetric_difference(set,other);
}

unsigned int hb_set_get_population(const hb_set_t * set) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_set_get_population(set);
}

hb_codepoint_t hb_set_get_min(const hb_set_t * set) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_set_get_min(set);
}

hb_codepoint_t hb_set_get_max(const hb_set_t * set) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_set_get_max(set);
}

hb_bool_t hb_set_next(const hb_set_t * set, hb_codepoint_t * codepoint) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_set_next(set,codepoint);
}

hb_bool_t hb_set_previous(const hb_set_t * set, hb_codepoint_t * codepoint) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_set_previous(set,codepoint);
}

hb_bool_t hb_set_next_range(const hb_set_t * set, hb_codepoint_t * first, hb_codepoint_t * last) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_set_next_range(set,first,last);
}

hb_bool_t hb_set_previous_range(const hb_set_t * set, hb_codepoint_t * first, hb_codepoint_t * last) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_set_previous_range(set,first,last);
}

unsigned int hb_set_next_many(const hb_set_t * set, hb_codepoint_t codepoint, hb_codepoint_t * out, unsigned int size) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_set_next_many(set,codepoint,out,size);
}

hb_shape_plan_t * hb_shape_plan_create(hb_face_t * face, const hb_segment_properties_t * props, const hb_feature_t * user_features, unsigned int num_user_features, const char * const * shaper_list) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_shape_plan_create(face,props,user_features,num_user_features,shaper_list);
}

hb_shape_plan_t * hb_shape_plan_create_cached(hb_face_t * face, const hb_segment_properties_t * props, const hb_feature_t * user_features, unsigned int num_user_features, const char * const * shaper_list) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_shape_plan_create_cached(face,props,user_features,num_user_features,shaper_list);
}

hb_shape_plan_t * hb_shape_plan_create2(hb_face_t * face, const hb_segment_properties_t * props, const hb_feature_t * user_features, unsigned int num_user_features, const int * coords, unsigned int num_coords, const char * const * shaper_list) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_shape_plan_create2(face,props,user_features,num_user_features,coords,num_coords,shaper_list);
}

hb_shape_plan_t * hb_shape_plan_create_cached2(hb_face_t * face, const hb_segment_properties_t * props, const hb_feature_t * user_features, unsigned int num_user_features, const int * coords, unsigned int num_coords, const char * const * shaper_list) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_shape_plan_create_cached2(face,props,user_features,num_user_features,coords,num_coords,shaper_list);
}

hb_shape_plan_t * hb_shape_plan_get_empty() {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_shape_plan_get_empty();
}

hb_shape_plan_t * hb_shape_plan_reference(hb_shape_plan_t * shape_plan) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_shape_plan_reference(shape_plan);
}

void hb_shape_plan_destroy(hb_shape_plan_t * shape_plan) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_shape_plan_destroy(shape_plan);
}

hb_bool_t hb_shape_plan_set_user_data(hb_shape_plan_t * shape_plan, hb_user_data_key_t * key, void * data, hb_destroy_func_t destroy, hb_bool_t replace) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_shape_plan_set_user_data(shape_plan,key,data,destroy,replace);
}

void * hb_shape_plan_get_user_data(const hb_shape_plan_t * shape_plan, hb_user_data_key_t * key) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_shape_plan_get_user_data(shape_plan,key);
}

hb_bool_t hb_shape_plan_execute(hb_shape_plan_t * shape_plan, hb_font_t * font, hb_buffer_t * buffer, const hb_feature_t * features, unsigned int num_features) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_shape_plan_execute(shape_plan,font,buffer,features,num_features);
}

const char * hb_shape_plan_get_shaper(hb_shape_plan_t * shape_plan) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_shape_plan_get_shaper(shape_plan);
}

void hb_shape(hb_font_t * font, hb_buffer_t * buffer, const hb_feature_t * features, unsigned int num_features) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_shape(font,buffer,features,num_features);
}

hb_bool_t hb_shape_full(hb_font_t * font, hb_buffer_t * buffer, const hb_feature_t * features, unsigned int num_features, const char * const * shaper_list) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_shape_full(font,buffer,features,num_features,shaper_list);
}

hb_bool_t hb_shape_justify(hb_font_t * font, hb_buffer_t * buffer, const hb_feature_t * features, unsigned int num_features, const char * const * shaper_list, float min_target_advance, float max_target_advance, float * advance, hb_tag_t * var_tag, float * var_value) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_shape_justify(font,buffer,features,num_features,shaper_list,min_target_advance,max_target_advance,advance,var_tag,var_value);
}

const char ** hb_shape_list_shapers() {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_shape_list_shapers();
}

float hb_style_get_value(hb_font_t * font, hb_style_tag_t style_tag) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_style_get_value(font,style_tag);
}

hb_blob_t* hb_subset_repack_or_fail(hb_tag_t table_tag, hb_object_t* hb_objects, unsigned num_hb_objs) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_subset_repack_or_fail(table_tag,hb_objects,num_hb_objs);
}

hb_subset_input_t * hb_subset_input_create_or_fail() {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_subset_input_create_or_fail();
}

hb_subset_input_t * hb_subset_input_reference(hb_subset_input_t * input) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_subset_input_reference(input);
}

void hb_subset_input_destroy(hb_subset_input_t * input) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_subset_input_destroy(input);
}

hb_bool_t hb_subset_input_set_user_data(hb_subset_input_t * input, hb_user_data_key_t * key, void * data, hb_destroy_func_t destroy, hb_bool_t replace) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_subset_input_set_user_data(input,key,data,destroy,replace);
}

void * hb_subset_input_get_user_data(const hb_subset_input_t * input, hb_user_data_key_t * key) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_subset_input_get_user_data(input,key);
}

void hb_subset_input_keep_everything(hb_subset_input_t * input) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_subset_input_keep_everything(input);
}

hb_set_t * hb_subset_input_unicode_set(hb_subset_input_t * input) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_subset_input_unicode_set(input);
}

hb_set_t * hb_subset_input_glyph_set(hb_subset_input_t * input) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_subset_input_glyph_set(input);
}

hb_set_t * hb_subset_input_set(hb_subset_input_t * input, hb_subset_sets_t set_type) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_subset_input_set(input,set_type);
}

hb_map_t* hb_subset_input_old_to_new_glyph_mapping(hb_subset_input_t * input) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_subset_input_old_to_new_glyph_mapping(input);
}

hb_subset_flags_t hb_subset_input_get_flags(hb_subset_input_t * input) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_subset_input_get_flags(input);
}

void hb_subset_input_set_flags(hb_subset_input_t * input, unsigned value) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_subset_input_set_flags(input,value);
}

hb_bool_t hb_subset_input_pin_all_axes_to_default(hb_subset_input_t * input, hb_face_t * face) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_subset_input_pin_all_axes_to_default(input,face);
}

hb_bool_t hb_subset_input_pin_axis_to_default(hb_subset_input_t * input, hb_face_t * face, hb_tag_t axis_tag) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_subset_input_pin_axis_to_default(input,face,axis_tag);
}

hb_bool_t hb_subset_input_pin_axis_location(hb_subset_input_t * input, hb_face_t * face, hb_tag_t axis_tag, float axis_value) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_subset_input_pin_axis_location(input,face,axis_tag,axis_value);
}

hb_bool_t hb_subset_input_get_axis_range(hb_subset_input_t * input, hb_tag_t axis_tag, float * axis_min_value, float * axis_max_value, float * axis_def_value) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_subset_input_get_axis_range(input,axis_tag,axis_min_value,axis_max_value,axis_def_value);
}

hb_bool_t hb_subset_input_set_axis_range(hb_subset_input_t * input, hb_face_t * face, hb_tag_t axis_tag, float axis_min_value, float axis_max_value, float axis_def_value) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_subset_input_set_axis_range(input,face,axis_tag,axis_min_value,axis_max_value,axis_def_value);
}

hb_bool_t hb_subset_input_override_name_table(hb_subset_input_t * input, hb_ot_name_id_t name_id, unsigned platform_id, unsigned encoding_id, unsigned language_id, const char * name_str, int str_len) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_subset_input_override_name_table(input,name_id,platform_id,encoding_id,language_id,name_str,str_len);
}

hb_face_t * hb_subset_preprocess(hb_face_t * source) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_subset_preprocess(source);
}

hb_face_t * hb_subset_or_fail(hb_face_t * source, const hb_subset_input_t * input) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_subset_or_fail(source,input);
}

hb_face_t * hb_subset_plan_execute_or_fail(hb_subset_plan_t * plan) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_subset_plan_execute_or_fail(plan);
}

hb_subset_plan_t * hb_subset_plan_create_or_fail(hb_face_t * face, const hb_subset_input_t * input) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_subset_plan_create_or_fail(face,input);
}

void hb_subset_plan_destroy(hb_subset_plan_t * plan) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_subset_plan_destroy(plan);
}

hb_map_t * hb_subset_plan_old_to_new_glyph_mapping(const hb_subset_plan_t * plan) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_subset_plan_old_to_new_glyph_mapping(plan);
}

hb_map_t * hb_subset_plan_new_to_old_glyph_mapping(const hb_subset_plan_t * plan) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_subset_plan_new_to_old_glyph_mapping(plan);
}

hb_map_t * hb_subset_plan_unicode_to_old_glyph_mapping(const hb_subset_plan_t * plan) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_subset_plan_unicode_to_old_glyph_mapping(plan);
}

hb_subset_plan_t * hb_subset_plan_reference(hb_subset_plan_t * plan) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_subset_plan_reference(plan);
}

hb_bool_t hb_subset_plan_set_user_data(hb_subset_plan_t * plan, hb_user_data_key_t * key, void * data, hb_destroy_func_t destroy, hb_bool_t replace) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_subset_plan_set_user_data(plan,key,data,destroy,replace);
}

void * hb_subset_plan_get_user_data(const hb_subset_plan_t * plan, hb_user_data_key_t * key) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_subset_plan_get_user_data(plan,key);
}

hb_unicode_funcs_t * hb_unicode_funcs_get_default() {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_unicode_funcs_get_default();
}

hb_unicode_funcs_t * hb_unicode_funcs_create(hb_unicode_funcs_t * parent) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_unicode_funcs_create(parent);
}

hb_unicode_funcs_t * hb_unicode_funcs_get_empty() {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_unicode_funcs_get_empty();
}

hb_unicode_funcs_t * hb_unicode_funcs_reference(hb_unicode_funcs_t * ufuncs) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_unicode_funcs_reference(ufuncs);
}

void hb_unicode_funcs_destroy(hb_unicode_funcs_t * ufuncs) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_unicode_funcs_destroy(ufuncs);
}

hb_bool_t hb_unicode_funcs_set_user_data(hb_unicode_funcs_t * ufuncs, hb_user_data_key_t * key, void * data, hb_destroy_func_t destroy, hb_bool_t replace) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_unicode_funcs_set_user_data(ufuncs,key,data,destroy,replace);
}

void * hb_unicode_funcs_get_user_data(const hb_unicode_funcs_t * ufuncs, hb_user_data_key_t * key) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_unicode_funcs_get_user_data(ufuncs,key);
}

void hb_unicode_funcs_make_immutable(hb_unicode_funcs_t * ufuncs) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_unicode_funcs_make_immutable(ufuncs);
}

hb_bool_t hb_unicode_funcs_is_immutable(hb_unicode_funcs_t * ufuncs) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_unicode_funcs_is_immutable(ufuncs);
}

hb_unicode_funcs_t * hb_unicode_funcs_get_parent(hb_unicode_funcs_t * ufuncs) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_unicode_funcs_get_parent(ufuncs);
}

void hb_unicode_funcs_set_combining_class_func(hb_unicode_funcs_t * ufuncs, hb_unicode_combining_class_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_unicode_funcs_set_combining_class_func(ufuncs,func,user_data,destroy);
}

void hb_unicode_funcs_set_general_category_func(hb_unicode_funcs_t * ufuncs, hb_unicode_general_category_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_unicode_funcs_set_general_category_func(ufuncs,func,user_data,destroy);
}

void hb_unicode_funcs_set_mirroring_func(hb_unicode_funcs_t * ufuncs, hb_unicode_mirroring_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_unicode_funcs_set_mirroring_func(ufuncs,func,user_data,destroy);
}

void hb_unicode_funcs_set_script_func(hb_unicode_funcs_t * ufuncs, hb_unicode_script_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_unicode_funcs_set_script_func(ufuncs,func,user_data,destroy);
}

void hb_unicode_funcs_set_compose_func(hb_unicode_funcs_t * ufuncs, hb_unicode_compose_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_unicode_funcs_set_compose_func(ufuncs,func,user_data,destroy);
}

void hb_unicode_funcs_set_decompose_func(hb_unicode_funcs_t * ufuncs, hb_unicode_decompose_func_t func, void * user_data, hb_destroy_func_t destroy) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_unicode_funcs_set_decompose_func(ufuncs,func,user_data,destroy);
}

hb_unicode_combining_class_t hb_unicode_combining_class(hb_unicode_funcs_t * ufuncs, hb_codepoint_t unicode) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_unicode_combining_class(ufuncs,unicode);
}

hb_unicode_general_category_t hb_unicode_general_category(hb_unicode_funcs_t * ufuncs, hb_codepoint_t unicode) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_unicode_general_category(ufuncs,unicode);
}

hb_codepoint_t hb_unicode_mirroring(hb_unicode_funcs_t * ufuncs, hb_codepoint_t unicode) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_unicode_mirroring(ufuncs,unicode);
}

hb_script_t hb_unicode_script(hb_unicode_funcs_t * ufuncs, hb_codepoint_t unicode) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_unicode_script(ufuncs,unicode);
}

hb_bool_t hb_unicode_compose(hb_unicode_funcs_t * ufuncs, hb_codepoint_t a, hb_codepoint_t b, hb_codepoint_t * ab) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_unicode_compose(ufuncs,a,b,ab);
}

hb_bool_t hb_unicode_decompose(hb_unicode_funcs_t * ufuncs, hb_codepoint_t ab, hb_codepoint_t * a, hb_codepoint_t * b) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_unicode_decompose(ufuncs,ab,a,b);
}

void hb_version(unsigned int * major, unsigned int * minor, unsigned int * micro) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	IHarfbuzz->hb_version(major,minor,micro);
}

const char * hb_version_string() {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_version_string();
}

hb_bool_t hb_version_atleast(unsigned int major, unsigned int minor, unsigned int micro) {
	extern struct HarfbuzzIFace *IHarfbuzz;

	return IHarfbuzz->hb_version_atleast(major,minor,micro);
}
