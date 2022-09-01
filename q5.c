#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
#include<stdlib.h> //atoi() for conversion of  string to int
#include<string.h>

void print_file_names(char dir_name[100],long nByte);

int main(int argc, char *argv[])
{
    DIR *dir;
    struct dirent *dirent;
    struct stat st;
    long nByte;

    if(argc != 2)
    {
        printf("Invalid number of argument...!");
        return 0;
    }
    nByte = atoi(argv[1]);

    dir = opendir(".");
    while((dirent = readdir(dir)) != NULL)
    {
        if(dirent->d_type == DT_DIR) // folder or directory
        {  
            print_file_names(dirent->d_name,nByte);
        }else
        {
            stat(dirent->d_name,&st);
            if(st.st_size > nByte)
            {
                printf("Directory Name = Current  --  File Name = %s  --  Size = %ld\n",dirent->d_name,st.st_size);
            } 
        }
    }
    closedir(dir);
}

void print_file_names(char dir_name[100],long nByte)
{
    DIR *dir;
    struct dirent *dirent;
    struct stat st;
    int size;
    char path[100];
    
    if(strcmp(dir_name,".") == 0 || strcmp(dir_name,"..") == 0) // || dir_name[0] == '.'
    {
        return;
    }

    dir = opendir(dir_name);
    while((dirent = readdir(dir)) != NULL)
    {
        if(dirent->d_type == DT_REG) //regular file
        {
            path[0] = '\0';
            strcat(path,dir_name);
            strcat(path,"/");
            strcat(path,dirent->d_name);

            stat(path,&st);

            size = st.st_size;
            if(size > nByte)
            {
                printf("Directory Name = %s  --  File Name = %s  --  Size = %d\n",dir_name,dirent->d_name,size);
            }
        }else
        {
            if(strcmp(dirent->d_name,".") == 0 || strcmp(dirent->d_name,"..") == 0 || dirent->d_name[0] == '.')
            {
                continue;
            }
            path[0] = '\0';
            strcat(path,dir_name);
            strcat(path,"/");
            strcat(path,dirent->d_name);

            print_file_names(path,nByte);
        }
    }
    closedir(dir);
}