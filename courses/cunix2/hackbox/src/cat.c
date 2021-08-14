/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Defines ls, cat, cp, mkdir, help 
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
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE    256
#define STDOUT      1

void print_file_contents(const char *file_path)
{
    struct stat *stats = (struct stat *) malloc(sizeof(struct stat));
    if (stat(file_path, stats) == -1)
    {
        perror("cat: cannot concatenate");
        exit(1);
    }

    if (!(stats->st_mode & S_IFREG))
    {
        printf("cat: cannot concatenate: '%s' is not a file.\n", file_path);
    }

    size_t file_size = (size_t) stats->st_size;
    free(stats);

    int fd = open(file_path, O_RDONLY);

    char *buffer = (char *) malloc(sizeof(char) * BUF_SIZE);
    while (read(fd, buffer, BUF_SIZE) != -1 && file_size > BUF_SIZE)
    {
        write(STDOUT, buffer, BUF_SIZE);
        file_size -= BUF_SIZE;
    }
    write(STDOUT, buffer, file_size);
    close(fd);
    free(buffer);
}
