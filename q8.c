#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<dirent.h>
#include<time.h>

int main(int argc, char *argv[])
{
    DIR *dir;
    struct dirent *dirent;
    struct stat st;
    char date_time[100];
    char *month;
    

    if(argc != 2)
    {
        printf("Invalid number of arguments...!\n");
        exit(1);
    }

    dir = opendir(".");
    while((dirent = readdir(dir)) != NULL)
    {
        if(stat(dirent->d_name,&st) == -1)
        {
            perror("stat");
            exit(1);
        }

        strcpy(date_time,ctime(&st.st_ctime));

        strtok(date_time," ");
        month = strtok(NULL," ");
        if(strcmp(month,argv[1]) == 0 && dirent->d_type == DT_REG)
        {
            printf("%s -- %s \n",dirent->d_name,ctime(&st.st_ctime));
        }
    }
}