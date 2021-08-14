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
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

char *get_params(char **argv);
int count_param_args(char **argv);
void ls(char *dir_path, unsigned int all, unsigned int as_list);
void make_dir(const char *dir_path);
void cp_f_to_f(const char *src_path, const char *dest_path);
void cp_fs_to_dir(char **argv, int argc);
void print_file_contents(const char *file_path);

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        printf("You must provide an argument.\nWrite \"./hackbox help\" for details.\n");
        return 0;
    }
    argv++;

    if (!strcmp(*argv, "ls"))
    {
        char *params = get_params(++argv);
        unsigned int num_of_params = 0;
        unsigned int all = 0;
        unsigned int as_list = 0;
        while (*params != '\0')
        {
            switch (*params++)
            {
                case 'a':
                    all = 1;
                    break;
                case 'l':
                    as_list = 1;
                    break;
                default:
                    break;
            }
            num_of_params++;
        }
        free(params - num_of_params);

        argc -= count_param_args(argv);
        switch (argc)
        {
            case 2:
                ls(".", all, as_list);
                break;
            case 3:
                while (**argv == '-')
                {
                    argv++;
                }
                ls(*argv, all, as_list);
                break;
            default:
                while (*argv != NULL)
                {
                    if (**argv == '-')
                    {
                        argv++;
                        continue;
                    }
                    printf("%s:\n", *argv);
                    ls(*argv, all, as_list);
                    argv++;
                }
                break;
        }
    }
    else if (!strcmp(*argv, "mkdir"))
    {
        if (argc == 2)
        {
            printf("No arguments provided!\n");
            exit(1);
        }

        while (*++argv != NULL)
        {
            make_dir(*argv);
        }
    }
    else if (!strcmp(*argv, "cp"))
    {
        switch (argc)
        {
            case 2:
            case 3:
                printf("You should provide at least 2 arguments!\n");
                exit(1);
            case 4:
                cp_f_to_f(*(argv + 1), *(argv + 2));
                break;
            default:
                cp_fs_to_dir(++argv, argc - 2);
                break;
        }
    }
    else if (!strcmp(*argv, "cat"))
    {
        switch (argc)
        {
            case 2:
                printf("You should provide at least one argument!\n");
                exit(1);
            default:
                while (*++argv != NULL)
                {
                    print_file_contents(*argv);
                }
                break;
        }
    }
    else
    {
        printf("ls\ncat\ncp\nmkdir\nhelp\n");
    }
    

    return 0;
}

char *get_params(char **argv)
{
    unsigned int num_of_params = 0;
    char **argv_s = argv;
    char *arg;
    while (*argv != NULL)
    {
        arg = *argv;
        if (*arg == '-')
        {
            while (*++arg != '\0')
            {
                num_of_params++;
            }
        }
        argv++;
    }
    argv = argv_s;

    char *params = malloc(sizeof(char) * (num_of_params + 1));
    while (*argv != NULL)
    {
        arg = *argv;
        if (*arg == '-')
        {
            while (*++arg != '\0')
            {
                *params++ = *arg;
            }
        }
        argv++;
    }
    *params = '\0';
    return params - num_of_params;
}

int count_param_args(char **argv)
{
    int num_of_param_args = 0;
    while (*argv != NULL)
    {
        if (**argv == '-')
        {
            num_of_param_args++;
        }
        argv++;
    }
    return num_of_param_args;
}

