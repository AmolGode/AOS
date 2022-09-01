#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

void print_files(char dir_name[100], int nByte);

int main(int argc, char *argv[])
{
    DIR *dir;
    struct stat st;
    struct dirent *dirent;
    int nByte;
    if (argc != 2)
    {
        printf("Insufficent args..\n");
        return 1;
    }

    nByte = atoi(argv[1]);

    dir = opendir(".");
    while ((dirent = readdir(dir)) != NULL)
    {
        if (dirent->d_type == DT_REG)
        {
            stat(dirent->d_name, &st);
            if (st.st_size > nByte)
            {
                printf("Current -- %s -- %ld \n", dirent->d_name, st.st_size);
            }
            
        }else
            {
                print_files(dirent->d_name, nByte);
            }
    }
}

void print_files(char dir_name[100], int nByte)
{
    DIR *dir;
    struct stat st;
    struct dirent *dirent;
    char path[100];

    if (strcmp(dir_name, ".") == 0 || strcmp(dir_name, "..") == 0) // || dir_name[0] == '.'
    {
        return;
    }

    // printf("%s \n",dir_name);

    dir = opendir(dir_name);
    while ((dirent = readdir(dir)) != NULL)
    {

        if (dirent->d_type == DT_REG)
        {
            path[0] = '\0';
            strcat(path, dir_name);
            strcat(path, "/");
            strcat(path, dirent->d_name);

            stat(path, &st);
            if (st.st_size > nByte)
            {
                printf(" -- %s -- %ld \n", path, st.st_size);
            }
        }
    }
}