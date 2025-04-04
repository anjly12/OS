#include <stdio.h>

int main() {
    int i, j, n, a[50], frame[10], no, k, avail, count = 0;
    int frequency[10];

    printf("\n\tLFU PAGE REPLACEMENT SCHEME\n");

    printf("Enter the number of requests/pages: ");
    scanf("%d", &n);

    printf("Enter the requests:\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &no);
    for (i = 0; i < no; i++) {
        frame[i] = -1;
        frequency[i] = 0;
    }
    printf("Page replacement:\n");

    for (i = 1; i <= n; i++) {
        printf("%d :  ",  a[i]);
        avail = 0;
        for (k = 0; k < no; k++) {
            if (frame[k] == a[i]) {
                avail = 1;
                frequency[k]++;
                break;
            }
        }

        if (avail == 0) {
            int min_frequency = frequency[0];
            int min_index = 0;
            for (k = 1; k < no; k++) {
                if (frequency[k] < min_frequency) {
                    min_frequency = frequency[k];
                    min_index = k;
                }
            }
            frame[min_index] = a[i];
            frequency[min_index] = 1;
            count++;
            for (k = 0; k < no; k++) {
                if (frame[k] != -1) {
                    printf("%d  ", frame[k]);
                }
                else {
                    printf("-  ");
                }
            }
        }
        else {
            printf("HIT");
        }
        printf("\n");
    }

    printf("Number of page faults = %d", count);
    printf("\n");
    return 0;
}
