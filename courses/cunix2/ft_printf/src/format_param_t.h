#ifndef FORMAT_PARAM_T_H
#define FORMAT_PARAM_T_H

typedef struct
{
  char type;
  char flags;
  unsigned int min_field_width;
  const char *start;
  const char *end;
}
format_param_t;

#endif
