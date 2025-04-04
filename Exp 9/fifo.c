#include <stdio.h>
int main(){
int no_frame, no_request, i, pgf = 0, j = 0, page_hits = 0;
printf("\n\tFIFO PAGE REPLACEMENT SCHEME\n");
printf("Enter the number of requests: ");
scanf("%d", &no_request);
printf("Enter the number of frames: ");
scanf("%d", &no_frame);
int frame[no_frame], req[no_request];
for (i = 0; i < no_frame; i++) {
frame[i] = -1;
}
printf("Enter the requests/pages:\n");
for (i = 0; i < no_request; i++) {
scanf("%d", &req[i]);
}
printf("Page replacement:\n");
for (i = 0; i < no_request; i++) {
int avail = 0;
printf("%d : ", req[i]);
for (int a = 0; a < no_frame; a++) {
if (frame[a] == req[i]) {
avail = 1;
page_hits++;
break;
}
}
if (avail == 0) {  
frame[j] = req[i];
j = (j + 1) % no_frame;
pgf++;
}
if (avail == 1) {
printf("HIT\n");
} else {
for (int a = 0; a < no_frame; a++) {
if (frame[a] == -1)
 printf("-  ");
else
printf("%d  ", frame[a]);
}
printf("\n");
}
}
printf("Number of page faults = %d\n", pgf);
printf("Number of page hits = %d\n", page_hits);
}
