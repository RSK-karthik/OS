#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char *argv[])
{


int a;
int fd1=open("kk.txt",O_RDONLY,742);  //open system call
int fd2=open("kk1.txt",O_RDONLY,S_IRWXU|S_IRGRP|S_IXOTH);
printf(" fd1=%d,fd2=%d\n", fd1,fd2);
printf("Process Id=%d\n",getpid());
scanf("%d",&a);

}
