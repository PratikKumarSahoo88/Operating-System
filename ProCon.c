#include <stdio.h>
#include <stdlib.h>
#define SIZE 5   // buffer size
int buffer[SIZE];
int in = 0, out = 0;
int choice, item;

void produce() {
    if ((in + 1) % SIZE == out) {
        printf("\nBuffer is Full. Producer cannot add item.\n");
    } else {
        printf("Enter the value to produce: ");
        scanf("%d", &item);
        buffer[in] = item;
        in = (in + 1) % SIZE;
        printf("Produced: %d\n", item);
    }
}

void consume() {
    if (in == out) {
        printf("\nBuffer is Empty. Consumer cannot consume.\n");
    } else {
        item = buffer[out];
        out = (out + 1) % SIZE;
        printf("Consumed: %d\n", item);
    }
}

int main() {
    while (1) {
        printf("\n1. Produce\n2. Consume\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: produce(); break;
            case 2: consume(); break;
            case 3: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
