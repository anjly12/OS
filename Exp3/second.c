#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void main(){
char *args[]={"./EXEC",NULL};
execvp(args[0],args);
printf("END\n");
}
