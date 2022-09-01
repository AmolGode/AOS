#include<stdio.h>
#include<unistd.h>
int main()
{
    int i = 0;
    fork();
    for(i = 0; i < 2; i++)
    {
        if(fork() == 0)
        {
            printf("I am in the child process..!\n");
        }
    }
}