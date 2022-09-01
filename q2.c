#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
// #include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int copy_content();
int main()
{
    int fd;
    fd = copy_content();
    printf("\nNew file file descriptior is = %d\n",fd);
}
int copy_content()
{
    DIR *dir;
    struct dirent *dirent;
    char *ext = ".txt";
    int i,j,len,fdNew,fd,flag;
    char *ch;


    fdNew = open("newFile.text",O_CREAT|O_WRONLY,0642);
    dir = opendir(".");
    while((dirent = readdir(dir)) != NULL)
    {
        len = strlen(dirent->d_name);
        flag = 1;
        for(i = len-4, j = 0;i < len , j < 4; i++, j++)
        {
            if(dirent->d_name[i] != ext[j])
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            printf("%s matched \n",dirent->d_name);
            fd = open(dirent->d_name,O_RDONLY);
            while(read(fd,&ch,1))
            {
                write(fdNew,&ch,1);
            }
        }
    }

    return fdNew;
}