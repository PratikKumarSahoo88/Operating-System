#include <stdio.h>

#include <stdlib.h>

#include <pthread.h>



// Function executed by each thread

void* thread_function(void* arg) {

    int thread_num = *((int*)arg);

    printf("Thread %d: Running...\n", thread_num);

    printf("Thread %d: Task completed!\n", thread_num);

    pthread_exit(NULL); // end the thread

}



int main() {

    pthread_t threads[3];  // declare 3 threads

    int thread_args[3];

    int i, result;



    printf("Program started: Demonstrating threading in C\n\n");



    // Create threads

    for (i = 0; i < 3; i++) {

        thread_args[i] = i + 1;

        printf("Main: Creating Thread %d\n", i + 1);

        result = pthread_create(&threads[i], NULL, thread_function,&thread_args[i]);

        if (result != 0) {

            printf("Error creating thread %d\n", i + 1);

            exit(-1);

        }

    }



    // Wait for threads to finish

    for (i = 0; i < 3; i++) {

        pthread_join(threads[i], NULL);

    }



    printf("\nAll threads have finished execution.\n");

    pthread_exit(NULL);

    return 0;

}
