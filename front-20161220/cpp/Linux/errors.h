#ifndef _egg_errors_0xffd6007a_h
#define _egg_errors_0xffd6007a_h

#include "front/egg_msg.h"

#include "token.h"


void cpp_set_no_loc_group_mode (egg_msg_kind mode);
void cpp_set_missing_argument_mode (egg_msg_kind mode);
void cpp_set_cpp_mode (egg_msg_kind mode);
void cpp_set_garbage_after_include_mode (egg_msg_kind mode);
void cpp_set_garbage_after_line_mode (egg_msg_kind mode);
void cpp_set_garbage_after_directive_mode (egg_msg_kind mode);
void cpp_set_invalid_directive_mode (egg_msg_kind mode);
void cpp_set_too_many_arguments_mode (egg_msg_kind mode);
void cpp_set_redefinition_mode (egg_msg_kind mode);
void cpp_set_space_after_backslash_mode (egg_msg_kind mode);

int (*cpp_missing_argument_fix) (void * object);
int (*cpp_garbage_after_include_fix) (token object);
int (*cpp_garbage_after_line_fix) (token object);
int (*cpp_garbage_after_directive_fix) (token object);
int (*cpp_badly_formed_include_fix) (token object);
int (*cpp_badly_formed_define_fix) (token object);
int (*cpp_badly_formed_defined_fix) (token object);
int (*cpp_badly_formed_line_number_fix) (token object);
int (*cpp_badly_formed_file_name_fix) (token object);
int (*cpp_could_not_include_fix) (token object);
int (*cpp_invalid_argument_fix) (token object);
int (*cpp_unbalanced_if_fix) (token object);
int (*cpp_unexpected_endif_fix) (token object);
int (*cpp_invalid_expression_fix) (token object);
int (*cpp_invalid_directive_fix) (token object);
int (*cpp_unterminated_arglist_fix) (token object);
int (*cpp_too_few_arguments_fix) (token object);
int (*cpp_too_many_arguments_fix) (token object);
int (*cpp_redefinition_fix) (token object);
int (*cpp_hash_warning_fix) (token object);
int (*cpp_hash_error_fix) (token object);
int (*cpp_space_after_backslash_fix) (token object);

int cpp_missing_argument (void * loc, ...);
int cpp_garbage_after_include (token loc, ...);
int cpp_garbage_after_line (token loc, ...);
int cpp_garbage_after_directive (token loc, ...);
int cpp_badly_formed_include (token loc, ...);
int cpp_badly_formed_define (token loc, ...);
int cpp_badly_formed_defined (token loc, ...);
int cpp_badly_formed_line_number (token loc, ...);
int cpp_badly_formed_file_name (token loc, ...);
int cpp_could_not_include (token loc, ...);
int cpp_invalid_argument (token loc, ...);
int cpp_unbalanced_if (token loc, ...);
int cpp_unexpected_endif (token loc, ...);
int cpp_invalid_expression (token loc, ...);
int cpp_invalid_directive (token loc, ...);
int cpp_unterminated_arglist (token loc, ...);
int cpp_too_few_arguments (token loc, ...);
int cpp_too_many_arguments (token loc, ...);
int cpp_redefinition (token loc, ...);
int cpp_hash_warning (token loc, ...);
int cpp_hash_error (token loc, ...);
int cpp_space_after_backslash (token loc, ...);

int cpp_no_loc_group_parse_option (char *name, char *mode);
int cpp_cpp_parse_option (char *name, char *mode);
void cpp_no_loc_group_list_options (void);
void cpp_cpp_list_options (void);

#endif /* _egg_errors_0xffd6007a_h */
