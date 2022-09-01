#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>
#include<fcntl.h>
#include<time.h>

int openf(char *fname)
{
    int fd;
    fd = open(fname, O_RDWR | O_CREAT, 0666);
    if (fd < 1)
        perror("open error");
    else
        printf("input file open\n");
    return fd;
}
int main(int argc, char *argv[])
{
    DIR *dp;
    int fd;
    struct dirent *dirp;
    struct stat buf;
    if (argc != 3)
    {
        printf("\nInvalid No. of inputs\n");
        exit(0);
    }
    else
    {
        fd = openf(argv[2]);
        dp = opendir(".");
        while ((dirp = readdir(dp)) != NULL)
        {
            write(fd, dirp->d_name, strlen(dirp->d_name));
            write(fd, "\n", 1);
        }
        printf("%s Output File Created\n", argv[2]);       
    }
    close(fd);
    closedir(dp);
}