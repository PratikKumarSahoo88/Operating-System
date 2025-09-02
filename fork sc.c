#include<stdio.h>
#include<unistd.h>
void main(){
    int pid;
    pid=fork();
    if(pid==0){
        printf("\n I am the child");
        printf("\n I am the parent:%d",getpid());
               printf("\n I am the child:%d",getpid());
    }
    else{
        printf("\n I am the Parent");
        printf("\n I am the Parents parent:%d",getpid());
        printf("\n I am the parent:%d\n",getpid());
    }
}