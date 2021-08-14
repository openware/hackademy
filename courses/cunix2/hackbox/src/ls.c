/*
 * =====================================================================================
 *
 *       Filename:  ls.c
 *
 *    Description:  Defines ls 
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

char *make_path(const char *path1, const char *path2);
char *get_permissions(mode_t st_mode);
char get_file_type(mode_t st_mode);

void ls(char *dir_path, unsigned int all, unsigned int as_list)
{
    DIR *dir = opendir(dir_path);
    if (!dir)
    {
        perror(dir_path);
        exit(1);
    }

    struct dirent *entry;
    struct stat *stats = (struct stat *) malloc(sizeof(struct stat));
    while ((entry = readdir(dir)) != NULL)
    {
        if (!all && *(entry->d_name) == '.')
        {
            continue;
        }

        if (!as_list)
        {
            printf("%s  ", entry->d_name);
        }
        else
        {
            char *full_path = make_path(dir_path, entry->d_name);
            stat(full_path, stats);

            char *permissions = get_permissions(stats->st_mode);
            char file_type = get_file_type(stats->st_mode);
            printf("%c%s ", file_type, permissions);
            free(permissions);

            printf("%3ld ", stats->st_nlink);

            struct passwd *pwd = getpwuid(stats->st_uid);
            printf("%7s ", pwd->pw_name);

            struct group *grp = getgrgid(stats->st_gid);
            printf("%7s ", grp->gr_name);

            printf("%ld\t", stats->st_size);

            char *c_time = ctime(&(stats->st_mtime));
            char *date_time = malloc(sizeof(char) * 13);
            for (int i = 4; i < 16; i++, date_time++)
            {
                *date_time = *(c_time + i);
            }
            *date_time = '\0';
            date_time -= 12;
            printf("%s ", date_time);
            free(date_time);

            printf("%s\n", entry->d_name);
        }
    }
    free(stats);

    closedir(dir);
    printf("\n");
}

char *get_permissions(mode_t st_mode)
{
    char *permissions = malloc(sizeof(char) * 10);

    *permissions++ = (st_mode & S_IRUSR) ? 'r' : '-';
    *permissions++ = (st_mode & S_IWUSR) ? 'w' : '-';
    *permissions++ = (st_mode & S_IXUSR) ? 'x' : '-';

    *permissions++ = (st_mode & S_IRGRP) ? 'r' : '-';
    *permissions++ = (st_mode & S_IWGRP) ? 'w' : '-';
    *permissions++ = (st_mode & S_IXGRP) ? 'x' : '-';

    *permissions++ = (st_mode & S_IRGRP) ? 'r' : '-';
    *permissions++ = (st_mode & S_IWGRP) ? 'w' : '-';
    *permissions++ = (st_mode & S_IXGRP) ? 'x' : '-';

    *permissions = '\0';
    return permissions - 9;
}

char get_file_type(mode_t st_mode)
{
    int file_type = st_mode & S_IFMT;

    switch (file_type)
    {
        case S_IFSOCK:
            return 's';
        case S_IFLNK:
            return 'l';
        case S_IFREG:
            return '-';
        case S_IFBLK:
            return 'b';
        case S_IFDIR:
            return 'd';
        case S_IFCHR:
            return 'c';
        case S_IFIFO:
            return 'f';
        default:
            return 'n';
    }
}
