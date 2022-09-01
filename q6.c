#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

void sighup(int sig);
void sigint(int sig);
void sigquit(int sig);
int main()
{
    int i, j, k;
    pid_t pid;
    if ((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }
    if(pid == 0)
    {

        signal(SIGHUP, sighup);
        signal(SIGINT, sigint);
        signal(SIGQUIT, sigquit);

        while(1)
        {
            pause();
        }
    }
    else
    {
        sleep(1);
        j = 0;
        for (i = 1; i <= 5; i++)
        {
            j++;
            if (i % 2 == 0)
            {
                printf("PARENT: sending SIGHUP Signal : %d\n", j);
                kill(pid, SIGHUP);
                sleep(3);
            }
            else
            {
                printf("PARENT: sending SIGINT signal : %d\n", j);
                kill(pid, SIGINT);
                sleep(3);
            }
        }
        printf("Parent sending SIGQUIT\n");
        kill(pid, SIGQUIT);

    }
}
void sighup(int sig)
{
    // signal(SIGHUP, sighup);
    printf("Child: I have received sighup\n");
}
void sigint(int sig)
{
    // signal(SIGINT, sigint);
    printf("Child: I have received sighINT\n");
}
void sigquit(int sig)
{
    printf("My daddy has killed me\n");
    exit(0);
}