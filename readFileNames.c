#include<stdio.h>
#include<unistd.h>
#include<dirent.h>

int main()
{
    struct dirent *dirent;
    DIR *dir;
    char *ext = ".txt";
    
    dir = opendir(".");
    // printf("dir = %d",dir);
    while(dirent = readdir(dir))
    {
        printf("File name = %s\n",dirent->d_name);
    }
}