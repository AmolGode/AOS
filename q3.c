#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>


int main(int argc, char *argv[])
{
    int i,j;
    long size1,size2;
    struct stat st1,st2;
    char temp_filename[100];
    int size = argc-1;
    char files[size][100];

    if(argc < 1)
    {
        printf("Insufficient number of argumanet..!");
    }

    for(i = 0 ; i < size ; i++)
    {
        strcpy(files[i],argv[i+1]);
    }
    for(i = 0 ; i < argc-1; i++)
    {
        stat(files[i],&st1);
        printf("File name = %s  ||  Size = %ld \n",files[i],st1.st_size);
    }

    printf("\n******In sordet order****** \n\n");

    for(i = 0 ; i < size -1; i++)
    {
        for(j = 0; j < size - i - 1; j++)
        {
            stat(files[j],&st1);
            stat(files[j+1],&st2);

            size1 = st1.st_size;
            size2 = st2.st_size;
            if(size1 > size2)
            {
                strcpy(temp_filename,files[j]);
                strcpy(files[j],files[j+1]);
                strcpy(files[j+1],temp_filename);
            }
        }
    }

    for(i = 0 ; i < size; i++)
    {
        stat(files[i],&st1);
        printf("File name = %s  ||  Size = %ld \n",files[i],st1.st_size);
    }
}

























// for(i = 1 ; i < argc; i++)
//     {
//         min_size = INT_MAX;
//         for(j = 1 ; j < argc; j++)
//         {
//             stat(argv[j],&st);
//             cur_size  = st.st_size;
//             if(cur_size <= min_size && cur_size > prev_min)
//             {
//                 min_size = cur_size;
//                 strcpy(min_file_name,argv[j]);
//             }
//         }
//         prev_min = min_size;
//         printf("File name = %s  ||  Size = %ld \n",min_file_name,min_size);
//     }