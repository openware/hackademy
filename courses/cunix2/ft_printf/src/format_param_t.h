/*
 * =====================================================================================
 *
 *       Filename:  format_param_t.h
 *
 *    Description:  Describes format parameter structure 
 *
 *        Version:  1.0
 *        Created:  08/27/2021 04:25:44 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
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
