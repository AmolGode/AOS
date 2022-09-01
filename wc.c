#include<stdio.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
    execlp("wc","wc","q11.c",NULL);
}