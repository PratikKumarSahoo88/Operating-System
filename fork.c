#include<stdio.h>
#include<unistd.h>
int main(){
    printf("Before fork()\n");
    pid_t pid=fork();
    if(pid<0){
        perror("fork failed");
        return 1;

    }else if(pid==0){
        printf("This is the child process.PID=%d\n",getpid());

    }else{
        printf("This is the parent process.PID=%d\n",getpid());
    }
    return 0;
}
