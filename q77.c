#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#include<fcntl.h> // O_RDWR  ,  O_CREAT
#include<sys/stat.h>
#include<stdlib.h>
#include<time.h>

int main(int argc,char *argv[])
{
    DIR *dir;
    int fd;
    struct dirent *dirent;
    struct stat st;
    char file_size[100];
    char time[100];

    if(argc != 2)
    {
        printf("Invalid number of argument..!\n");
        return 0;
    }

    if((fd = open(argv[1],O_RDWR|O_CREAT,0642)) < 0)
    {
        printf("Opening file failed...!");
    }else
    {
        printf("Opening file sucessfully..!\n\n");
    }

    dir = opendir(".");
    while((dirent = readdir(dir)) != NULL)
    {
        stat(dirent->d_name,&st);
        sprintf(file_size,"%d",(int)st.st_size); // Integerr to string conversion

                
        
        write(fd,file_size,strlen(file_size));
        write(fd,"  ",2);
        write(fd,dirent->d_name,strlen(dirent->d_name));
        write(fd,"  ",2);
        write(fd,ctime(&st.st_ctime),strlen(ctime(&st.st_ctime)));

    }
    close(fd);
    closedir(dir);
}