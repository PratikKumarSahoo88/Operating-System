#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/types.h>
#define msgsize 12
void main()
{
    char*msg="hello world";
    char inbuff[msgsize];
    int p[2],pid,j;
    pipe(p);
    pid=fork();
    if(pid>0){
        close(p[0]);
        write(p[1],msg,msgsize);
    }
    if(pid==0){
        close(p[1]);
        read(p[0],inbuff,msgsize);
        printf("%s \n",inbuff);
    }
}