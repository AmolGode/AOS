// WRONG PROGRAM

#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<limits.h>
#include<string.h>


struct entry {
    char *name;
    long long int size;
    struct entry *next;
};

int main() {
    DIR *dir;
    struct dirent *dp;
    struct stat st;
    struct entry *head = NULL, *ep, **npp;

    dir = opendir(".");
    if (dir == NULL) {
        perror("cannot open directory");
        return 1;
    }
    while ((dp = readdir(dir)) != NULL) {
        ep = calloc(sizeof(*ep), 1);
        if (ep == NULL) {
            perror("cannot allocate memory");
            return 1;
        }
        ep->name = strdup(dp->d_name);
        if (ep->name == NULL) {
            perror("cannot allocate memory");
            return 1;
        }
        if (!stat(dp->d_name, &st)) {
            ep->size = st.st_size;
        }
        for (npp = &head; *npp && (*npp)->size <= ep->size; npp = &(*npp)->next)
            continue;
        ep->next = *npp;
        *npp = ep;
    }
    closedir(dir);
    for (ep = head; ep; ep = ep->next) {
        printf("%s -- %d\n", ep->name, ep->size);

    }
    while ((ep = head) != NULL) {
        head = ep->next;
        free(ep->name);
        free(ep);
    }
    return 0;
}

int main2()
{
    DIR *dir1,*dir2;
    int fd,prev_min = -1;
    long cur_size,min_size;
    struct dirent *dirent1, *dirent2;
    struct stat st1,st2;
    char min_file_name[1000];
    char filename[1000];

    dir1 = opendir(".");
    while((dirent1 = readdir(dir1)) != NULL)
    {
        min_size = INT_MAX;
        dir2 = opendir(".");
        while((dirent2 = readdir(dir2)) != NULL)
        {
            stat(dirent2->d_name,&st1);
            cur_size = st1.st_size;
            strcpy(filename,dirent2->d_name);
            if(cur_size < min_size && cur_size > prev_min)
            {
                min_size = cur_size;
                strcpy(min_file_name,filename);
            }
        } 
        prev_min = min_size;
        printf("File name = %s || size = %ld \n",min_file_name,min_size);
    }
}

int is_equal(char str1[], char str2[])
{
    int i ;
    int j ;
    if(strlen(str1) != strlen(str2))
    {
        return 0;
    }
    
    for(i = 0 , j = 0; i < strlen(str1), j < strlen(str2); i++, j++)
    {
        if(str1[i] != str2[j])
        {
            return 0;
        }
    }
    return 1;
}