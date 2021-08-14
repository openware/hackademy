/*
 * =====================================================================================
 *
 *       Filename:  mkdir.c
 *
 *    Description:  Defines mkdir 
 *
 *        Version:  1.0
 *        Created:  08/13/2021 09:04:28 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void make_dir(const char *dir_path)
{
    struct stat *stats = (struct stat *) malloc(sizeof(struct stat));
    if (stat(dir_path, stats) == -1)
    {
        if (mkdir(dir_path, 0755) == -1)
        {
            perror("mkdir: cannot create directory");
            exit(1);
        }
    }
    else
    {
        printf("mkdir: cannot create directory '%s': File exists.\n", dir_path);
        exit(1);
    }
}

