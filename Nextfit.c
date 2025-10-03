#include <stdio.h>

int main() {
    int blockSize[10], processSize[10], blockNo, processNo;
    int allocation[10], lastAlloc = 0;
    
    printf("Enter number of blocks: ");
    scanf("%d", &blockNo);
    printf("Enter size of each block:\n");
    for (int i = 0; i < blockNo; i++)
        scanf("%d", &blockSize[i]);

    printf("Enter number of processes: ");
    scanf("%d", &processNo);
    printf("Enter size of each process:\n");
    for (int i = 0; i < processNo; i++) {
        scanf("%d", &processSize[i]);
        allocation[i] = -1;
    }

    // Next Fit Allocation
    for (int i = 0; i < processNo; i++) {
        int j = lastAlloc;
        int count = 0;
        while (count < blockNo) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                lastAlloc = j;
                break;
            }
            j = (j + 1) % blockNo;
            count++;
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < processNo; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
    return 0;
}
