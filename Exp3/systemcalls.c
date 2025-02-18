#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
void main(){
pid_t childid=fork();
if(childid==0){
printf("Child is created\n");
printf("Child ID=%d\n",getpid());
printf("Parent ID=%d\n",getppid());
}
if(childid>0){
printf("Parent and child is created\n");
printf("Child process ID:%d\n",childid);
printf("Parent process ID:%d\n",getppid());
wait(NULL);
printf("Child process is terminated and parent is moved from running to waiting state\n");
}
if(childid<0){
printf("Child is not created\n");
}
exit(0);
}
