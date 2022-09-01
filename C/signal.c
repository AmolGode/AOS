#include<stdio.h>
#include<signal.h>
int main(int argc, char *argv[])
{
    char buf[256];
    if(argc != 1)
        signal(SIGCHLD,SIG_IGN);
    while(read(0,buf,256))
    if(fork() == 0)
    exit(0);
}