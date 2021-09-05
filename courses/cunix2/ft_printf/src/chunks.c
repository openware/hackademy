#include "format_param_t.h"
#include "resolvers.h"
#include "buffer.h"

unsigned int chunk_count(const char *format)
{
  unsigned int num_of_chunks = 0;
  while (*format != '\0')
  {
    format = (*format == '%') ? format_resolver(format)->end : next_param(format);
    num_of_chunks++;
  }
  return num_of_chunks;
}
