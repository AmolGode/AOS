#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
void signint(int sig);
void sighup(int sig);
void sigquit(int sig);

int gotsig;

int main()
{
    int i;
    pid_t pid = fork();
    if(pid < 0)
    {
        perror("fork");
        exit(0);
    }

    if(pid == 0)
    {
        signal(SIGHUP,sighup);
        signal(SIGINT,signint);
        signal(SIGQUIT,sigquit);

        
        while(1)
        {
            pause();
            if(gotsig == SIGINT)
            {
                printf("Child : Child process recieved SIGINT signal\n");
                // gotsig = -1;
            }else if(gotsig == SIGHUP)
            {
                printf("Child : Child process recieved SIGHUP signal\n"); 
                // gotsig = -1;
            }else if(gotsig == SIGQUIT)
            {
                printf("Dady killed me....!\n");
                exit(0);
            }
        }
    }else
    {
        sleep(1);
        for(i = 1; i <=5 ; i++)
        {
            if(i % 2 == 0)
            {
                printf("Parent : sending SIGINT signal\n");
                kill(pid,SIGINT);
                sleep(3);
            }else
            {
                printf("Parent : sending SIGHUP signal\n");
                kill(pid,SIGHUP);
                sleep(3);
            }
        }
        printf("Parent : sending SIGQUIT signal\n");
        kill(pid,SIGQUIT);
    }
}

void signint(int sig)
{
    gotsig = sig;
}

void sighup(int sig)
{
    gotsig = sig;
}

void sigquit(int sig)
{
    gotsig = sig;
}