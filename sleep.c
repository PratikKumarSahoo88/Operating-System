#include<unistd.h>
#include<stdio.h>
main(){
    int i=0,pid;
    printf("\n ready for fork\n");
    pid=fork();
    if(pid==0){
        printf("\n child rocess started");
        sleep(4);
        for(i=0;i<10;i++)
            printf("\n%d",i);
            printf("\n child process ends");
        }
        else{
            printf("\n I am the parent");
            printf("\n parent process ends");
    }

}