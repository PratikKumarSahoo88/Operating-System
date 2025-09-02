#include<stdio.h>
#include<unistd.h>
int main(){
    int fd[2];
    char buffer[20];
    if(pipe(fd)==-1){
        perror("pipe failed");
        return 1;
    }
    write(fd[1],"Hello",6);
    close(fd[1]);
    read(fd[0],buffer,sizeof(buffer));
    printf("read from pipe:%s\n",buffer);
    close(fd[0]);
    return 0;
}