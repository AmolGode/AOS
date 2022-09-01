// Write a C program to display all the files from current directory and its subdirectory whose size is greater //than n Bytes Where n is accepted from user through command line

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
int n;
void list_dir(char *path)
{
    DIR *dp;
    struct dirent *dirp;
    struct stat buf;

    char newpath[100];
    dp = opendir(path);
    if (dp == NULL)
    {
        printf("FAILED to open directory");
        return;
    }
    while ((dirp = readdir(dp)))
    {
        if (dirp->d_type == DT_DIR)
        {
            if ((strcmp(dirp->d_name, ".") != 0) &&
                (strcmp(dirp->d_name, "..") != 0))
            {

                sprintf(newpath, "%s / %s", path, dirp->d_name);
                list_dir(newpath);
            }
        }
        stat(dirp->d_name, &buf);
        if (buf.st_size > n)
            printf("file: %s\t size : %ld \n", dirp->d_name, buf.st_size);
    }
    closedir(dp);
}

int main(int argc, char *argv[])
{
    n = atoi(argv[1]);
    if (argc != 2)
    {
        printf("Invalid number of argument\n");
        exit(0);
    }
    list_dir(".");
    return (0);
}