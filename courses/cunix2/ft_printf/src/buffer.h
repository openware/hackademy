#ifndef BUFFER_H
#define BUFFER_H

unsigned int buff_len(const char *buff);
char *create_buff(const char *format);
const char *next_param(const char *format);

#endif
