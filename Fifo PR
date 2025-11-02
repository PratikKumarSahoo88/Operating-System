#include <stdio.h>



int main() {

    int frames[10], pages[30];

    int n, f, pageFaults = 0, next = 0;



    printf("Enter number of frames: ");

    scanf("%d",&f);



    printf("Enter number of pages: ");

    scanf("%d",&n);



    printf("Enter reference string:\n");

    for (int i = 0; i < n; i++)

        scanf("%d",&pages[i]);



    for (int i = 0; i < f; i++)

        frames[i] = -1;



    for (int i = 0; i < n; i++) {

        int flag = 0;

        for (int j = 0; j<f; j++) {

            if (frames[j] == pages[i]) {

                flag = 1;

                break;

            }

        }



        if (!flag) {

            frames[next] = pages[i];

            next = (next + 1) % f;

            pageFaults++;

        }



        printf("\nFor page %d : ", pages[i]);

        for (int j = 0; j<f; j++)

            if (frames[j] != -1)

                printf("%d ", frames[j]);

            else

                printf("- ");

    }



    printf("\nTotal Page Faults = %d\n", pageFaults);

    return 0;

}
