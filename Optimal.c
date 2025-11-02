#include <stdio.h>



int predict(int pages[], int frames[], int n, int index, int f) {

    int res = -1, farthest = index;

    for (int i = 0; i < f; i++) {

        int j;

        for (j = index; j < n; j++) {

            if (frames[i] == pages[j]) {

                if (j > farthest) {

                    farthest = j;

                    res = i;

                }

                break;

            }

        }

        if (j == n)

            return i;

    }

    return (res == -1) ? 0 : res;

}



int main() {

    int frames[10], pages[30];

    int n, f, pageFaults = 0, filled = 0;



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

            if (filled < f) {

                frames[filled++] = pages[i];

            } else {

                int j = predict(pages, frames, n, i + 1, f);

                frames[j] = pages[i];

            }

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
