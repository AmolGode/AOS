#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *args[])
{
    int i;
    struct stat st;
    if (argc < 2)
    {
        printf("Insufficent Arguments..!");
        return 0;
    }
    for (i = 1; i < argc; i++)
    {
        stat(args[i], &st);
        if (S_ISREG(st.st_mode))
        {
            printf("%s is regular file \n", args[i]);
        }
        else if (S_ISDIR(st.st_mode) != 0)
        {
            printf("%s is directory \n", args[i]);
        }
        else if (S_ISCHR(st.st_mode))
        {
            printf("%s is Character special  file..\n", args[i]);
        }
        else if (S_ISFIFO(st.st_mode))
        {
            printf("%s is FIFO file..\n", args[i]);
        }else if(S_ISBLK(st.st_mode))
        {
            printf("%s is block file..\n",args[i]);
        }else if(S_ISLNK(st.st_mode))
        {
            printf("%s is symbolic link.. \n",args[i]);
        }else if(S_ISSOCK(st.st_mode))
        {
            printf("%s is socket..!\n",args[i]);
        }
    }
    printf("\n");
    return 0;
}