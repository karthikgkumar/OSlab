
#include<stdio.h> 
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h> 
int  main(int argc, char* argv[] )
{
    FILE *fp1,*fp2;
    DIR *dp;
    struct dirent *link;
    if(argc==2){
        dp=opendir(argv[1]);
    printf("\n contents of the directory %s are \n", argv[1]); 
    while((link=readdir(dp))!=0) 
    printf("%s",link->d_name);
    closedir(dp);

    }
    else
    {
    char c;
    fp1=fopen(argv[2],"r");
    fp2=fopen(argv[3],"w");
    if(!fp1 || !fp2 || argc!=3)
    {
    printf("ERROR \n"); 
    exit(1);
    }
    while((c=fgetc(fp1))!=EOF){
        fputc(c,fp2);

    }
    fclose(fp1);
    fclose(fp2);
    
    
    }
    
    
    
    
    
    
} 

