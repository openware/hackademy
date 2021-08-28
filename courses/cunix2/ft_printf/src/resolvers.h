/*
 * =====================================================================================
 *
 *       Filename:  resolvers.h
 *
 *    Description:  printf format resolvers 
 *
 *        Version:  1.0
 *        Created:  08/28/2021 01:39:46 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef RESOLVERS_H
#define RESOLVERS_H

#include "format_param_t.h"

format_param_t *format_resolver(const char *format);
char *num_resolver(format_param_t *format_param, int num);
char *char_resolver(format_param_t *format_param, char ch);
char *str_resolver(format_param_t *format_param, const char *str);
char *escseq_resolver(format_param_t *format_param);

#endif
