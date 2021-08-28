/*
 * =====================================================================================
 *
 *       Filename:  buffer.h
 *
 *    Description: Buffer functions signatures 
 *
 *        Version:  1.0
 *        Created:  08/27/2021 04:28:30 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef BUFFER_H
#define BUFFER_H

unsigned int buff_len(const char *buff);
char *create_buff(const char *format);
const char *next_param(const char *format);

#endif
