/*
 * =====================================================================================
 *
 *       Filename:  chunks.c
 *
 *    Description:  chunks helper functions of resolvers 
 *
 *        Version:  1.0
 *        Created:  08/28/2021 05:37:41 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

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
