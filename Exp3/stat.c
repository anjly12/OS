#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>
void main(){
char*path,path1[10];
struct stat*nfile;
nfile=(struct stat*)malloc(sizeof(struct stat));
printf("Enter the filename:");
scanf("%s",path1);
stat(path1,nfile);
printf("User ID:%d\n",nfile->st_uid);
printf("Blocksize:%ld\n",nfile->st_blksize);
printf("Last access time:%ld\n",nfile->st_atime);
printf("Last modification:%ld\n",nfile->st_mtime);
printf("Production mode:%d\n",nfile->st_mode);
printf("Size of file d:%ld\n",nfile->st_size);
printf("Number of links:%ld\n",nfile->st_nlink);
}
