#include <stdio.h>
#include <limits.h>

int main() {
    int no_frame, no_request, i, pgf = 0, page_hits = 0;
    
    printf("\n\tLRU PAGE REPLACEMENT SCHEME\n");

    printf("Enter the number of requests/pages: ");
    scanf("%d", &no_request);

    printf("Enter the number of frames: ");
    scanf("%d", &no_frame);

    int frame[no_frame], req[no_request];
    int last_used[no_frame];

    for (i = 0; i < no_frame; i++) {
        frame[i] = -1;
        last_used[i] = -1;
    }

    printf("Enter the requests:\n");
    for (i = 0; i < no_request; i++) {
        scanf("%d", &req[i]);
    }

    printf("Page replacement:\n");
    for (i = 0; i < no_request; i++) {
        int avail = 0, least_recent = -1, min_time = INT_MAX; 
        printf("%d : ", req[i]);

        for (int a = 0; a < no_frame; a++) {
            if (frame[a] == req[i]) {
                avail = 1;
                page_hits++;
                last_used[a] = i;
                break;
            }
        }

        if (!avail) {
            int empty_frame = -1;

            for (int a = 0; a < no_frame; a++) {
                if (frame[a] == -1) {
                    empty_frame = a;
                    break;
                }
            }

            if (empty_frame != -1) {
                frame[empty_frame] = req[i];
                last_used[empty_frame] = i;
            } else {
                for (int a = 0; a < no_frame; a++) {
                    if (last_used[a] < min_time) {
                        min_time = last_used[a];
                        least_recent = a;
                    }
                }
                frame[least_recent] = req[i];
                last_used[least_recent] = i;
            }
            pgf++;

            for (int a = 0; a < no_frame; a++) {
                if (frame[a] == -1)
                    printf("- ");
                else
                    printf("%d ", frame[a]);
            }
            printf("\n");
        } else {
            printf("HIT\n");
        }
    }
    printf("Number of page faults = %d\n", pgf);
    printf("Number of page hits = %d\n", page_hits);
}
