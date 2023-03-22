#include <stdio.h>
#include <dirent.h>

void main(int argc,char *arg[])
{   
    if(argc==1)
    {
        DIR *p;
        struct dirent *d;
        p = opendir("./");
        if(p==NULL)
        {
            printf("No files found");
        }
        else
        {
            while(d = readdir(p))
            {
                printf("%s",d->d_name);
            }
        }

    }
    else
    {
        FILE *f1,*f2;
        char ch;
        f1 = fopen(arg[1],"r");
        f2 = fopen(arg[2],"w");

        while((ch=fgetc(f1))!=EOF)
        {
            fputc(ch,f2);
        }

        printf("Contents copied successfully!\n");
        fclose(f1);
        fclose(f2);
    }
}