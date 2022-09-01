#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
    int fd,n1,n2,n3;
    char buf1[20],buf2[1024];
    fd = open("file_type.c",O_RDONLY);
    n1 = read(fd,buf1,20);
    n2 = read(fd,buf2,1024);
    n3 = read(fd,buf1,20);
    printf("%d -- %d  -- %d ",n1,n2,n3);
    printf("\nbuf1 == > \n %s \n",buf1);
    printf("\nbuf2 == > \n %s \n",buf2);
}