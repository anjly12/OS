#include <stdio.h>
void main(){
int n,i,j;
double avg_wt=0,avg_tat=0;
printf("Enter the number of processes: ");
scanf("%d",&n);
int bt[n],wt[n],tat[n];
printf("Enter the burst time of the processes\n");
for(i=0;i<n;i++){
printf("P%d Burst time: ",(i+1));
scanf("%d",&bt[i]);
}
wt[0]=0;
for(i=0;i<n;i++){
wt[i]=wt[i-1]+bt[i-1];
avg_wt=avg_wt+wt[i];
}
avg_wt=avg_wt/n;
for(i=0;i<n;i++){
tat[i]=wt[i]+bt[i];
avg_tat=avg_tat+tat[i];
}
avg_tat=avg_tat/n;
printf("PID\tBurstTime\tWaitingTime\tTurnAroundTime\n");
for(i=0;i<n;i++){
printf("P%d\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
}
printf("\n");
printf("Average waiting time: %.2f\nAverage turn around time: %.2f\n",avg_wt,avg_tat);
printf("\n");
for(i=0;i<n;i++){
printf("----------");
}
printf("\n| ");
for(i=0;i<n;i++){
printf("  P%d   |",i+1);
}
printf("\n");
for(i=0;i<n;i++){
printf("----------");
}
printf("\n0\t");
int current_time=0;
for(i=0;i<n;i++){
current_time=current_time+bt[i];
printf("%d\t",current_time);
}
printf("\n");
}
