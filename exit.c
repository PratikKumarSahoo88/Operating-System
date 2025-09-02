#include<stdio.h>
#include<stdlib.h>
int main(){
    printf("Program is running...\n");
    printf("Calling exit() now...\n");
    exit(0);
    printf("this will not be printed.\n");
    return 0;
}