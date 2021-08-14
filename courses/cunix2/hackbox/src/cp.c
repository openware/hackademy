/*
 * =====================================================================================
 *
 *       Filename:  cp.c
 *
 *    Description:  Defines cp 
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
#include <fcntl.h>

#define BUF_SIZE    256

char *make_path(const char *path1, const char *path2);

void cp_f_to_f(const char *src_path, const char *dest_path)
{
    struct stat *stats = (struct stat *) malloc(sizeof(struct stat));
    if (stat(src_path, stats) == -1)
    {
        perror("cp: cannot make copy");
        exit(1);
    }

    if (!(stats->st_mode & S_IFREG))
    {
        printf("cp: cannot make copy: '%s' is a directory\n", src_path);
    }

    size_t src_size = (size_t) stats->st_size;
    free(stats);

    int src_fd = open(src_path, O_RDONLY);
    int dest_fd = creat(dest_path, 0644);

    char *buffer = (char *) malloc(sizeof(char) * BUF_SIZE);
    while (read(src_fd, buffer, BUF_SIZE) != -1 && src_size > BUF_SIZE)
    {
        write(dest_fd, buffer, BUF_SIZE);
        src_size -= BUF_SIZE;
    }
    write(dest_fd, buffer, src_size);
    close(src_fd);
    close(dest_fd);
    free(buffer);
}

void cp_fs_to_dir(char **argv, int argc)
{
    char *dir_path = *(argv + argc - 1);
    struct stat *stats = (struct stat *) malloc(sizeof(struct stat));
    if (stat(dir_path, stats) == -1)
    {
        perror("cp: cannot make copy");
        exit(1);
    }

    if (!(stats->st_mode & S_IFDIR))
    {
        printf("cp: cannot make copy: '%s' is not a directory\n", dir_path);
    }
    free(stats);

    char *file_path;
    while (*argv != dir_path)
    {
        file_path = *argv;
        while (*file_path != '\0')
        {
            file_path++;
        }
        while (file_path != *argv - 1 && *file_path != '/')
        {
            file_path--;
        }
        file_path = make_path(dir_path, file_path);
        cp_f_to_f(*argv, file_path);
        argv++;
    }
}

char *make_path(const char *path1, const char *path2)
{
    unsigned int path1_len = 0;
    while (*path1 != '\0')
    {
        path1_len++;
        path1++;
    }
    path1 -= path1_len;

    unsigned int path2_len = 0;
    while (*path2 != '\0')
    {
        path2_len++;
        path2++;
    }
    path2 -= path2_len;

    char *full_path = malloc(sizeof(char) * (path1_len + path2_len + 1));
    while (*path1 != '\0')
    {
        *full_path++ = *path1++;
    }
    if (*full_path != '/')
    {
        *full_path++ = '/';
    }
    while (*path2 != '\0')
    {
        *full_path++ = *path2++;
    }
    *full_path = '\0';
    
    return (full_path - path1_len - path2_len - 1);
}

