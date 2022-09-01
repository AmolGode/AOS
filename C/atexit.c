#include<stdio.h>
#include<stdlib.h>
void cleanup();
int main()
{
    atexit(cleanup);
    printf("Doing some work...!\n");
    return 0;
}
void cleanup()
{
    printf("Doing cleaning..!\n");
}
