/*
 * =====================================================================================
 *
 *       Filename:  hackbox.h
 *
 *    Description:  Headers for hackbox. 
 *
 *        Version:  1.0
 *        Created:  08/14/2021 08:08:52 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */

#ifndef HACKBOX_H_
#define HACKBOX_H_

void ls(char *dir_path, unsigned int all, unsigned int as_list);
void make_dir(const char *dir_path);
void cp_f_to_f(const char *src_path, const char *dest_path);
void cp_fs_to_dir(char **argv, int argc);
void print_file_contents(const char *file_path);
char *make_path(const char *path1, const char *path2);
char *get_permissions(mode_t st_mode);
char get_file_type(mode_t st_mode);

#endif
