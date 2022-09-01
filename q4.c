#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<stdlib.h>
int main()
{
    struct dirent **dirent_list;
    int num_of_dir,i=0;

    num_of_dir = scandir(".",&dirent_list,0,alphasort);
    if(num_of_dir < 0)
    {
        perror("scandir");
    }else
    {
        while(i < num_of_dir)
        {
            if(dirent_list[i]->d_type == DT_DIR)
            {
                printf("Directory Name = %s\n",dirent_list[i]->d_name);
            }
            i++;
        }
    }
    free(dirent_list);
}
