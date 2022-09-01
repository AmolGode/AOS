#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<sys/wait.h>
// #include<fcntl.h>
int main()
{
    pid_t pid;
    int fd[2];
    char *args[] = {"", NULL};
    int cnum,pnum;
    
    if(pipe(fd) == -1)//fd[0] for read fd[1] for write
    {
        perror("pipe");
        exit(1);
    }
    pid = fork();
    if (pid < 0)
    {
        perror("fork");
        exit(1);
    }
    
    if(pid == 0)
    {
        close(fd[0]);
        printf("\n**In the child process**\n");
        printf("Enter 1 for wc and 2 for ls : ");
        scanf("%d",&cnum);
        write(fd[1],&cnum,sizeof(int));
        close(fd[1]);

    }
    else
    {
        wait(NULL);
        close(fd[1]);
        printf("\n**In the parent precess**\n");
        read(fd[0],&pnum,sizeof(int));
        close(fd[0]);
        printf("Number recieved from child = %d\n",pnum);
        printf("In Parent process PID = %d\n", getpid());

        
        if(pnum == 1)
        {
            printf("\nCalling execv for wc.c ...\n\n\n");
            execv("./wc", args);
        }else
        {
            printf("\nCalling execv for ls.c ...\n\n\n");
            execv("./ls", args);
        }
        
        printf("Error");
    }
}