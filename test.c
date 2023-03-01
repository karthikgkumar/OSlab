#include<stdio.h> #include<dirent.h>
struct dirent *dptr;
int main(int argc, char *argv[]) {
char buff[100];
DIR *dirp;
printf(“\n\n ENTER DIRECTORY NAME”); scanf(“%s”, buff); 
if((dirp=opendir(buff))==NULL)
{
  printf(“The given directory does not exist”); exit(1);
}
while(dptr=readdir(dirp))
{
  printf(“%s\n”,dptr->d_name);
}
closedir(dirp);
}



#3
#include<fcntl.h> #include<unistd.h> #include<stdio.h> main(int argc,char *argv[]) {
FILE *fp; char ch; int sc=0;
fp=fopen(argv[1],"r"); if(fp==NULL)
printf("unable to open a file",argv[1]); 
else
{ while(!feof(fp)) {
ch=fgetc(fp); if(ch==' ') sc++;
}
printf("no of spaces %d",sc); printf("\n");
fclose(fp);
} }

#4
#include<stdio.h> #include<dirent.h> main(int argc, char **argv) {
DIR *dp;
struct dirent *link;
dp=opendir(argv[1]);
printf(“\n contents of the directory %s are \n”, argv[1]); while((link=readdir(dp))!=0) printf(“%s”,link->d_name);
closedir(dp);
}

#5
#include<stdio.h> #include<string.h> #define max 1024 void usage()
{
printf(“usage:\t. /a.out filename word \n “);
}
int main(int argc, char *argv[])
{
FILE *fp;
char fline[max];
char *newline;
int count=0;
int occurrences=0;
if(argc!=3)
{
usage();
exit(1);
}
if(!(fp=fopen(argv[1],”r”)))
{
printf(“grep: couldnot open file : %s \n”,argv[1]); exit(1);
}
while(fgets(fline,max,fp)!=NULL)
{
count++;
if(newline=strchr(fline, „\n‟))
*newline=‟\0‟;
if(strstr(fline,argv[2])!=NULL)
{
printf(“%s: %d %s \n”, argv[1],count, fline);
 13 | P a g e
occurrences++; }
}
}
shell
#! /bin/bash
echo "Enter the value of n"
read n
a=0
b=1
count=2
echo "Fibonacci series:"
echo $a
echo $b
while [ $count -le $n ]
do
fib=`expr $a + $b`
a=$b
b=$fib
echo $fib
count=`expr $count + 1`
done


prime

#!/bin/bash
echo -e "Enter Number : \c"
read n
while [ $n -gt 2 ]
do
for((i=2; i<=$n/2; i++))
do
  ans=$(( n%i ))
  if [ $ans -eq 0 ]
  then
    echo "$n is not a prime number."
    exit 0
  fi
done
done
echo "$n is a prime number."