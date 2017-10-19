#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include "errors.h"
#include "front/error.h"
#include "front/egg_msg.h"
egg_msg_kind cpp_missing_argument_mode = egg_error_kind;
egg_msg_kind cpp_garbage_after_include_mode = egg_warning_kind;
egg_msg_kind cpp_garbage_after_line_mode = egg_warning_kind;
egg_msg_kind cpp_garbage_after_directive_mode = egg_warning_kind;
egg_msg_kind cpp_badly_formed_include_mode = egg_error_kind;
egg_msg_kind cpp_badly_formed_define_mode = egg_error_kind;
egg_msg_kind cpp_badly_formed_defined_mode = egg_error_kind;
egg_msg_kind cpp_badly_formed_line_number_mode = egg_error_kind;
egg_msg_kind cpp_badly_formed_file_name_mode = egg_error_kind;
egg_msg_kind cpp_could_not_include_mode = egg_error_kind;
egg_msg_kind cpp_invalid_argument_mode = egg_error_kind;
egg_msg_kind cpp_unbalanced_if_mode = egg_error_kind;
egg_msg_kind cpp_unexpected_endif_mode = egg_error_kind;
egg_msg_kind cpp_invalid_expression_mode = egg_error_kind;
egg_msg_kind cpp_invalid_directive_mode = egg_error_kind;
egg_msg_kind cpp_unterminated_arglist_mode = egg_error_kind;
egg_msg_kind cpp_too_few_arguments_mode = egg_error_kind;
egg_msg_kind cpp_too_many_arguments_mode = egg_error_kind;
egg_msg_kind cpp_redefinition_mode = egg_warning_kind;
egg_msg_kind cpp_hash_warning_mode = egg_warning_kind;
egg_msg_kind cpp_hash_error_mode = egg_error_kind;
egg_msg_kind cpp_space_after_backslash_mode = egg_warning_kind;

static void
make_no_loc_group_error(egg_msg *msg, void *loc, char *fmt, va_list args, int secondary)
{
  if(!secondary) egg_sort_key (msg, loc);
  egg_add_string (msg, "error: ");
  egg_vadd_format (msg, fmt, args);
  egg_add_string (msg, "\n");
  egg_set_kind (msg, egg_error_kind);
}

static void
make_no_loc_group_warning(egg_msg *msg, void *loc, char *fmt, va_list args, int secondary)
{
  if(!secondary) egg_sort_key (msg, loc);
  egg_add_string (msg, "warning: ");
  egg_vadd_format (msg, fmt, args);
  egg_add_string (msg, "\n");
  egg_set_kind (msg, egg_warning_kind);
}

static void
make_cpp_error(egg_msg *msg, void *loc, char *fmt, va_list args, int secondary)
{
  if(!secondary) egg_sort_key (msg, token_loc(loc));
  egg_add_string (msg, token_file(loc));
  egg_add_string (msg, ":");
  egg_add_string (msg, token_line(loc));
  egg_add_string (msg, ":");
  egg_add_string (msg, token_col(loc));
  egg_add_string (msg, ": error: ");
  egg_vadd_format (msg, fmt, args);
  egg_add_string (msg, "\n");
  egg_set_kind (msg, egg_error_kind);
}

static void
make_cpp_warning(egg_msg *msg, void *loc, char *fmt, va_list args, int secondary)
{
  if(!secondary) egg_sort_key (msg, token_loc(loc));
  egg_add_string (msg, token_file(loc));
  egg_add_string (msg, ":");
  egg_add_string (msg, token_line(loc));
  egg_add_string (msg, ":");
  egg_add_string (msg, token_col(loc));
  egg_add_string (msg, ": warning: ");
  egg_vadd_format (msg, fmt, args);
  egg_add_string (msg, "\n");
  egg_set_kind (msg, egg_warning_kind);
}

void
cpp_set_no_loc_group_mode (egg_msg_kind mode)
{
  cpp_set_missing_argument_mode (mode);
}

void
cpp_set_missing_argument_mode (egg_msg_kind mode)
{
  cpp_missing_argument_mode = mode;
}

void
cpp_set_cpp_mode (egg_msg_kind mode)
{
  cpp_set_garbage_after_include_mode (mode);
  cpp_set_garbage_after_line_mode (mode);
  cpp_set_garbage_after_directive_mode (mode);
  cpp_set_invalid_directive_mode (mode);
  cpp_set_too_many_arguments_mode (mode);
  cpp_set_redefinition_mode (mode);
  cpp_set_space_after_backslash_mode (mode);
}

void
cpp_set_garbage_after_include_mode (egg_msg_kind mode)
{
  cpp_garbage_after_include_mode = mode;
}

void
cpp_set_garbage_after_line_mode (egg_msg_kind mode)
{
  cpp_garbage_after_line_mode = mode;
}

void
cpp_set_garbage_after_directive_mode (egg_msg_kind mode)
{
  cpp_garbage_after_directive_mode = mode;
}

void
cpp_set_invalid_directive_mode (egg_msg_kind mode)
{
  cpp_invalid_directive_mode = mode;
}

void
cpp_set_too_many_arguments_mode (egg_msg_kind mode)
{
  cpp_too_many_arguments_mode = mode;
}

void
cpp_set_redefinition_mode (egg_msg_kind mode)
{
  cpp_redefinition_mode = mode;
}

void
cpp_set_space_after_backslash_mode (egg_msg_kind mode)
{
  cpp_space_after_backslash_mode = mode;
}

int
cpp_missing_argument (void * loc, ...)
{
  va_list args;
  egg_msg msg = NULL;

  va_start (args, loc);
  switch (cpp_missing_argument_mode) {
  case egg_error_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_missing_argument_fix, loc);
    make_no_loc_group_error(&msg, loc, "Missing argument for option %s", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_warning_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_missing_argument_fix, loc);
    make_no_loc_group_warning(&msg, loc, "Missing argument for option %s", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_disabled_kind:
    if (cpp_missing_argument_fix) {
      egg_set_fix (&msg, (int(*)(void*))cpp_missing_argument_fix, loc);
      msg = egg_submit (msg);
    }
    break;
  default: 
    fe_abort ("unexpected egg error mode");
  }
  va_end (args);
  return cpp_missing_argument_mode==egg_error_kind;
}

int
cpp_garbage_after_include (token loc, ...)
{
  va_list args;
  egg_msg msg = NULL;

  va_start (args, loc);
  switch (cpp_garbage_after_include_mode) {
  case egg_error_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_garbage_after_include_fix, loc);
    make_cpp_error(&msg, loc, "garbage at end of #include directive", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_warning_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_garbage_after_include_fix, loc);
    make_cpp_warning(&msg, loc, "garbage at end of #include directive", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_disabled_kind:
    if (cpp_garbage_after_include_fix) {
      egg_set_fix (&msg, (int(*)(void*))cpp_garbage_after_include_fix, loc);
      msg = egg_submit (msg);
    }
    break;
  default: 
    fe_abort ("unexpected egg error mode");
  }
  va_end (args);
  return cpp_garbage_after_include_mode==egg_error_kind;
}

int
cpp_garbage_after_line (token loc, ...)
{
  va_list args;
  egg_msg msg = NULL;

  va_start (args, loc);
  switch (cpp_garbage_after_line_mode) {
  case egg_error_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_garbage_after_line_fix, loc);
    make_cpp_error(&msg, loc, "garbage at end of #line", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_warning_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_garbage_after_line_fix, loc);
    make_cpp_warning(&msg, loc, "garbage at end of #line", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_disabled_kind:
    if (cpp_garbage_after_line_fix) {
      egg_set_fix (&msg, (int(*)(void*))cpp_garbage_after_line_fix, loc);
      msg = egg_submit (msg);
    }
    break;
  default: 
    fe_abort ("unexpected egg error mode");
  }
  va_end (args);
  return cpp_garbage_after_line_mode==egg_error_kind;
}

int
cpp_garbage_after_directive (token loc, ...)
{
  va_list args;
  egg_msg msg = NULL;

  va_start (args, loc);
  switch (cpp_garbage_after_directive_mode) {
  case egg_error_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_garbage_after_directive_fix, loc);
    make_cpp_error(&msg, loc, "garbage at end of preprocessing directive", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_warning_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_garbage_after_directive_fix, loc);
    make_cpp_warning(&msg, loc, "garbage at end of preprocessing directive", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_disabled_kind:
    if (cpp_garbage_after_directive_fix) {
      egg_set_fix (&msg, (int(*)(void*))cpp_garbage_after_directive_fix, loc);
      msg = egg_submit (msg);
    }
    break;
  default: 
    fe_abort ("unexpected egg error mode");
  }
  va_end (args);
  return cpp_garbage_after_directive_mode==egg_error_kind;
}

int
cpp_badly_formed_include (token loc, ...)
{
  va_list args;
  egg_msg msg = NULL;

  va_start (args, loc);
  switch (cpp_badly_formed_include_mode) {
  case egg_error_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_badly_formed_include_fix, loc);
    make_cpp_error(&msg, loc, "badly formed #include directive", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_warning_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_badly_formed_include_fix, loc);
    make_cpp_warning(&msg, loc, "badly formed #include directive", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_disabled_kind:
    if (cpp_badly_formed_include_fix) {
      egg_set_fix (&msg, (int(*)(void*))cpp_badly_formed_include_fix, loc);
      msg = egg_submit (msg);
    }
    break;
  default: 
    fe_abort ("unexpected egg error mode");
  }
  va_end (args);
  return cpp_badly_formed_include_mode==egg_error_kind;
}

int
cpp_badly_formed_define (token loc, ...)
{
  va_list args;
  egg_msg msg = NULL;

  va_start (args, loc);
  switch (cpp_badly_formed_define_mode) {
  case egg_error_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_badly_formed_define_fix, loc);
    make_cpp_error(&msg, loc, "badly formed argument list", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_warning_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_badly_formed_define_fix, loc);
    make_cpp_warning(&msg, loc, "badly formed argument list", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_disabled_kind:
    if (cpp_badly_formed_define_fix) {
      egg_set_fix (&msg, (int(*)(void*))cpp_badly_formed_define_fix, loc);
      msg = egg_submit (msg);
    }
    break;
  default: 
    fe_abort ("unexpected egg error mode");
  }
  va_end (args);
  return cpp_badly_formed_define_mode==egg_error_kind;
}

int
cpp_badly_formed_defined (token loc, ...)
{
  va_list args;
  egg_msg msg = NULL;

  va_start (args, loc);
  switch (cpp_badly_formed_defined_mode) {
  case egg_error_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_badly_formed_defined_fix, loc);
    make_cpp_error(&msg, loc, "badly formed defined() expression", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_warning_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_badly_formed_defined_fix, loc);
    make_cpp_warning(&msg, loc, "badly formed defined() expression", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_disabled_kind:
    if (cpp_badly_formed_defined_fix) {
      egg_set_fix (&msg, (int(*)(void*))cpp_badly_formed_defined_fix, loc);
      msg = egg_submit (msg);
    }
    break;
  default: 
    fe_abort ("unexpected egg error mode");
  }
  va_end (args);
  return cpp_badly_formed_defined_mode==egg_error_kind;
}

int
cpp_badly_formed_line_number (token loc, ...)
{
  va_list args;
  egg_msg msg = NULL;

  va_start (args, loc);
  switch (cpp_badly_formed_line_number_mode) {
  case egg_error_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_badly_formed_line_number_fix, loc);
    make_cpp_error(&msg, loc, "badly formed line number", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_warning_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_badly_formed_line_number_fix, loc);
    make_cpp_warning(&msg, loc, "badly formed line number", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_disabled_kind:
    if (cpp_badly_formed_line_number_fix) {
      egg_set_fix (&msg, (int(*)(void*))cpp_badly_formed_line_number_fix, loc);
      msg = egg_submit (msg);
    }
    break;
  default: 
    fe_abort ("unexpected egg error mode");
  }
  va_end (args);
  return cpp_badly_formed_line_number_mode==egg_error_kind;
}

int
cpp_badly_formed_file_name (token loc, ...)
{
  va_list args;
  egg_msg msg = NULL;

  va_start (args, loc);
  switch (cpp_badly_formed_file_name_mode) {
  case egg_error_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_badly_formed_file_name_fix, loc);
    make_cpp_error(&msg, loc, "badly formed file name", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_warning_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_badly_formed_file_name_fix, loc);
    make_cpp_warning(&msg, loc, "badly formed file name", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_disabled_kind:
    if (cpp_badly_formed_file_name_fix) {
      egg_set_fix (&msg, (int(*)(void*))cpp_badly_formed_file_name_fix, loc);
      msg = egg_submit (msg);
    }
    break;
  default: 
    fe_abort ("unexpected egg error mode");
  }
  va_end (args);
  return cpp_badly_formed_file_name_mode==egg_error_kind;
}

int
cpp_could_not_include (token loc, ...)
{
  va_list args;
  egg_msg msg = NULL;

  va_start (args, loc);
  switch (cpp_could_not_include_mode) {
  case egg_error_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_could_not_include_fix, loc);
    make_cpp_error(&msg, loc, "could not find include %s", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_warning_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_could_not_include_fix, loc);
    make_cpp_warning(&msg, loc, "could not find include %s", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_disabled_kind:
    if (cpp_could_not_include_fix) {
      egg_set_fix (&msg, (int(*)(void*))cpp_could_not_include_fix, loc);
      msg = egg_submit (msg);
    }
    break;
  default: 
    fe_abort ("unexpected egg error mode");
  }
  va_end (args);
  return cpp_could_not_include_mode==egg_error_kind;
}

int
cpp_invalid_argument (token loc, ...)
{
  va_list args;
  egg_msg msg = NULL;

  va_start (args, loc);
  switch (cpp_invalid_argument_mode) {
  case egg_error_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_invalid_argument_fix, loc);
    make_cpp_error(&msg, loc, "macro argument must be an identifier", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_warning_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_invalid_argument_fix, loc);
    make_cpp_warning(&msg, loc, "macro argument must be an identifier", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_disabled_kind:
    if (cpp_invalid_argument_fix) {
      egg_set_fix (&msg, (int(*)(void*))cpp_invalid_argument_fix, loc);
      msg = egg_submit (msg);
    }
    break;
  default: 
    fe_abort ("unexpected egg error mode");
  }
  va_end (args);
  return cpp_invalid_argument_mode==egg_error_kind;
}

int
cpp_unbalanced_if (token loc, ...)
{
  va_list args;
  egg_msg msg = NULL;

  va_start (args, loc);
  switch (cpp_unbalanced_if_mode) {
  case egg_error_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_unbalanced_if_fix, loc);
    make_cpp_error(&msg, loc, "unbalanced #if statement", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_warning_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_unbalanced_if_fix, loc);
    make_cpp_warning(&msg, loc, "unbalanced #if statement", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_disabled_kind:
    if (cpp_unbalanced_if_fix) {
      egg_set_fix (&msg, (int(*)(void*))cpp_unbalanced_if_fix, loc);
      msg = egg_submit (msg);
    }
    break;
  default: 
    fe_abort ("unexpected egg error mode");
  }
  va_end (args);
  return cpp_unbalanced_if_mode==egg_error_kind;
}

int
cpp_unexpected_endif (token loc, ...)
{
  va_list args;
  egg_msg msg = NULL;

  va_start (args, loc);
  switch (cpp_unexpected_endif_mode) {
  case egg_error_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_unexpected_endif_fix, loc);
    make_cpp_error(&msg, loc, "unexpected #endif statement", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_warning_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_unexpected_endif_fix, loc);
    make_cpp_warning(&msg, loc, "unexpected #endif statement", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_disabled_kind:
    if (cpp_unexpected_endif_fix) {
      egg_set_fix (&msg, (int(*)(void*))cpp_unexpected_endif_fix, loc);
      msg = egg_submit (msg);
    }
    break;
  default: 
    fe_abort ("unexpected egg error mode");
  }
  va_end (args);
  return cpp_unexpected_endif_mode==egg_error_kind;
}

int
cpp_invalid_expression (token loc, ...)
{
  va_list args;
  egg_msg msg = NULL;

  va_start (args, loc);
  switch (cpp_invalid_expression_mode) {
  case egg_error_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_invalid_expression_fix, loc);
    make_cpp_error(&msg, loc, "could not evaluate expression", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_warning_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_invalid_expression_fix, loc);
    make_cpp_warning(&msg, loc, "could not evaluate expression", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_disabled_kind:
    if (cpp_invalid_expression_fix) {
      egg_set_fix (&msg, (int(*)(void*))cpp_invalid_expression_fix, loc);
      msg = egg_submit (msg);
    }
    break;
  default: 
    fe_abort ("unexpected egg error mode");
  }
  va_end (args);
  return cpp_invalid_expression_mode==egg_error_kind;
}

int
cpp_invalid_directive (token loc, ...)
{
  va_list args;
  egg_msg msg = NULL;

  va_start (args, loc);
  switch (cpp_invalid_directive_mode) {
  case egg_error_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_invalid_directive_fix, loc);
    make_cpp_error(&msg, loc, "invalid preprocessing directive #%s", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_warning_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_invalid_directive_fix, loc);
    make_cpp_warning(&msg, loc, "invalid preprocessing directive #%s", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_disabled_kind:
    if (cpp_invalid_directive_fix) {
      egg_set_fix (&msg, (int(*)(void*))cpp_invalid_directive_fix, loc);
      msg = egg_submit (msg);
    }
    break;
  default: 
    fe_abort ("unexpected egg error mode");
  }
  va_end (args);
  return cpp_invalid_directive_mode==egg_error_kind;
}

int
cpp_unterminated_arglist (token loc, ...)
{
  va_list args;
  egg_msg msg = NULL;

  va_start (args, loc);
  switch (cpp_unterminated_arglist_mode) {
  case egg_error_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_unterminated_arglist_fix, loc);
    make_cpp_error(&msg, loc, "unterminated argument list", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_warning_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_unterminated_arglist_fix, loc);
    make_cpp_warning(&msg, loc, "unterminated argument list", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_disabled_kind:
    if (cpp_unterminated_arglist_fix) {
      egg_set_fix (&msg, (int(*)(void*))cpp_unterminated_arglist_fix, loc);
      msg = egg_submit (msg);
    }
    break;
  default: 
    fe_abort ("unexpected egg error mode");
  }
  va_end (args);
  return cpp_unterminated_arglist_mode==egg_error_kind;
}

int
cpp_too_few_arguments (token loc, ...)
{
  va_list args;
  egg_msg msg = NULL;

  va_start (args, loc);
  switch (cpp_too_few_arguments_mode) {
  case egg_error_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_too_few_arguments_fix, loc);
    make_cpp_error(&msg, loc, "too few arguments in call to macro \"%s\"", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_warning_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_too_few_arguments_fix, loc);
    make_cpp_warning(&msg, loc, "too few arguments in call to macro \"%s\"", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_disabled_kind:
    if (cpp_too_few_arguments_fix) {
      egg_set_fix (&msg, (int(*)(void*))cpp_too_few_arguments_fix, loc);
      msg = egg_submit (msg);
    }
    break;
  default: 
    fe_abort ("unexpected egg error mode");
  }
  va_end (args);
  return cpp_too_few_arguments_mode==egg_error_kind;
}

int
cpp_too_many_arguments (token loc, ...)
{
  va_list args;
  egg_msg msg = NULL;

  va_start (args, loc);
  switch (cpp_too_many_arguments_mode) {
  case egg_error_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_too_many_arguments_fix, loc);
    make_cpp_error(&msg, loc, "too many arguments in call to macro \"%s\"", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_warning_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_too_many_arguments_fix, loc);
    make_cpp_warning(&msg, loc, "too many arguments in call to macro \"%s\"", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_disabled_kind:
    if (cpp_too_many_arguments_fix) {
      egg_set_fix (&msg, (int(*)(void*))cpp_too_many_arguments_fix, loc);
      msg = egg_submit (msg);
    }
    break;
  default: 
    fe_abort ("unexpected egg error mode");
  }
  va_end (args);
  return cpp_too_many_arguments_mode==egg_error_kind;
}

int
cpp_redefinition (token loc, ...)
{
  va_list args;
  egg_msg msg = NULL;

  va_start (args, loc);
  switch (cpp_redefinition_mode) {
  case egg_error_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_redefinition_fix, loc);
    make_cpp_error(&msg, loc, "redefinition of \"%s\"", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_warning_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_redefinition_fix, loc);
    make_cpp_warning(&msg, loc, "redefinition of \"%s\"", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_disabled_kind:
    if (cpp_redefinition_fix) {
      egg_set_fix (&msg, (int(*)(void*))cpp_redefinition_fix, loc);
      msg = egg_submit (msg);
    }
    break;
  default: 
    fe_abort ("unexpected egg error mode");
  }
  va_end (args);
  return cpp_redefinition_mode==egg_error_kind;
}

int
cpp_hash_warning (token loc, ...)
{
  va_list args;
  egg_msg msg = NULL;

  va_start (args, loc);
  switch (cpp_hash_warning_mode) {
  case egg_error_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_hash_warning_fix, loc);
    make_cpp_error(&msg, loc, "%s", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_warning_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_hash_warning_fix, loc);
    make_cpp_warning(&msg, loc, "%s", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_disabled_kind:
    if (cpp_hash_warning_fix) {
      egg_set_fix (&msg, (int(*)(void*))cpp_hash_warning_fix, loc);
      msg = egg_submit (msg);
    }
    break;
  default: 
    fe_abort ("unexpected egg error mode");
  }
  va_end (args);
  return cpp_hash_warning_mode==egg_error_kind;
}

int
cpp_hash_error (token loc, ...)
{
  va_list args;
  egg_msg msg = NULL;

  va_start (args, loc);
  switch (cpp_hash_error_mode) {
  case egg_error_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_hash_error_fix, loc);
    make_cpp_error(&msg, loc, "%s", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_warning_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_hash_error_fix, loc);
    make_cpp_warning(&msg, loc, "%s", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_disabled_kind:
    if (cpp_hash_error_fix) {
      egg_set_fix (&msg, (int(*)(void*))cpp_hash_error_fix, loc);
      msg = egg_submit (msg);
    }
    break;
  default: 
    fe_abort ("unexpected egg error mode");
  }
  va_end (args);
  return cpp_hash_error_mode==egg_error_kind;
}

int
cpp_space_after_backslash (token loc, ...)
{
  va_list args;
  egg_msg msg = NULL;

  va_start (args, loc);
  switch (cpp_space_after_backslash_mode) {
  case egg_error_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_space_after_backslash_fix, loc);
    make_cpp_error(&msg, loc, "white space between backslash and newline", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_warning_kind:
    egg_set_fix (&msg, (int(*)(void*))cpp_space_after_backslash_fix, loc);
    make_cpp_warning(&msg, loc, "white space between backslash and newline", args, 0);
    msg = egg_submit (msg);
    break;
  case egg_disabled_kind:
    if (cpp_space_after_backslash_fix) {
      egg_set_fix (&msg, (int(*)(void*))cpp_space_after_backslash_fix, loc);
      msg = egg_submit (msg);
    }
    break;
  default: 
    fe_abort ("unexpected egg error mode");
  }
  va_end (args);
  return cpp_space_after_backslash_mode==egg_error_kind;
}

int
cpp_no_loc_group_parse_option (char *name, char *mode)
{
  egg_msg_kind m;
  if (strcmp (mode, "error")==0) m = egg_error_kind;
  else if (strcmp (mode, "warning")==0) m = egg_warning_kind;
  else if (strcmp (mode, "disabled")==0) m = egg_disabled_kind;
  
  if (strcmp (name, "missing_argument")==0) {
    cpp_set_missing_argument_mode (m);
    return 1;
  }
    return 0;
}

int
cpp_cpp_parse_option (char *name, char *mode)
{
  egg_msg_kind m;
  if (strcmp (mode, "error")==0) m = egg_error_kind;
  else if (strcmp (mode, "warning")==0) m = egg_warning_kind;
  else if (strcmp (mode, "disabled")==0) m = egg_disabled_kind;
  
  {
    if (strcmp (name, "garbage_after_include")==0) {
      cpp_set_garbage_after_include_mode (m);
      return 1;
    }
    if (strcmp (name, "garbage_after_line")==0) {
      cpp_set_garbage_after_line_mode (m);
      return 1;
    }
    if (strcmp (name, "garbage_after_directive")==0) {
      cpp_set_garbage_after_directive_mode (m);
      return 1;
    }
    if (strcmp (name, "invalid_directive")==0) {
      cpp_set_invalid_directive_mode (m);
      return 1;
    }
    if (strcmp (name, "too_many_arguments")==0) {
      cpp_set_too_many_arguments_mode (m);
      return 1;
    }
    if (strcmp (name, "redefinition")==0) {
      cpp_set_redefinition_mode (m);
      return 1;
    }
    if (strcmp (name, "space_after_backslash")==0) {
      cpp_set_space_after_backslash_mode (m);
      return 1;
    }
    if (strcmp (name, "cpp")==0) {
      cpp_set_cpp_mode (m);
      return 1;
    }
  }
    return 0;
}

void
cpp_no_loc_group_list_options (void)
{
  printf (" missing_argument                          %s\n", egg_msg_name(cpp_missing_argument_mode));
}

void
cpp_cpp_list_options (void)
{
  printf ("cpp                                     \n");
  printf ("  garbage_after_include                   %s\n", egg_msg_name(cpp_garbage_after_include_mode));
  printf ("  garbage_after_line                      %s\n", egg_msg_name(cpp_garbage_after_line_mode));
  printf ("  garbage_after_directive                 %s\n", egg_msg_name(cpp_garbage_after_directive_mode));
  printf ("  invalid_directive                       %s\n", egg_msg_name(cpp_invalid_directive_mode));
  printf ("  too_many_arguments                      %s\n", egg_msg_name(cpp_too_many_arguments_mode));
  printf ("  redefinition                            %s\n", egg_msg_name(cpp_redefinition_mode));
  printf ("  space_after_backslash                   %s\n", egg_msg_name(cpp_space_after_backslash_mode));
}

