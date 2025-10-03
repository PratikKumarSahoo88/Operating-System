#include <stdio.h>

int main() {
    int pageTable[20], n, pageSize, logicalAddr, pageNum, offset, frameNum, physicalAddr;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page size: ");
    scanf("%d", &pageSize);

    printf("Enter page table (frame number for each page, -1 if not in memory):\n");
    for (int i = 0; i < n; i++) {
        printf("Page %d -> Frame: ", i);
        scanf("%d", &pageTable[i]);
    }

    printf("\nEnter a logical address: ");
    scanf("%d", &logicalAddr);

    // Divide logical address into page number and offset
    pageNum = logicalAddr / pageSize;
    offset = logicalAddr % pageSize;

    if (pageNum >= n) {
        printf("Invalid logical address! Page number out of range.\n");
        return 0;
    }

    frameNum = pageTable[pageNum];
    if (frameNum == -1) {
        printf("Page fault! Page %d is not in memory.\n", pageNum);
        return 0;
    }

    // Calculate physical address
    physicalAddr = frameNum * pageSize + offset;

    printf("\nLogical Address: %d", logicalAddr);
    printf("\nPage Number: %d", pageNum);
    printf("\nOffset: %d", offset);
    printf("\nFrame Number: %d", frameNum);
    printf("\nPhysical Address: %d\n", physicalAddr);

    return 0;
}

/* output
Enter number of pages: 4
Enter page size: 100
Enter page table (frame number for each page, -1 if not in memory):
Page 0 -> Frame: 5
Page 1 -> Frame: 9
Page 2 -> Frame: -1
Page 3 -> Frame: 7

Enter a logical address: 250
Page fault! Page 2 is not in memory. */
