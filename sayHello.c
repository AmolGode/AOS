#include<stdio.h>
#include<unistd.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
    printf("In the sayHello.c \n Hello bro...\n");
    printf("\nPID after calling execv = %d\n",getpid());
    execlp("wc","wc","-l",NULL);
}