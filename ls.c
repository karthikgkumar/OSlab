#include<stdio.h>
#include<dirent.h> 
void main(int argc, char **argv) {
    DIR *dp;
    struct dirent *link;
    dp=opendir(argv[1]);
    printf("%d",argc);
    printf("\n contents of the directory %s are \n", argv[1]); 
    while((link=readdir(dp))!=0){ 
        printf("%s",link->d_name);
    }
    closedir(dp);
}