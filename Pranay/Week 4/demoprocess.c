/* Author: K. Karthik
   Email id: karthikk_cse@cbit.ac.in
   
   Aim: Demostration of fork() system call 
   
   Desription: This  program is used to demonstrate excev function. 
    Child will run the prime number program
    parent will run the factorial program
    
  Note: ./cprime and ./factorial are binary executable of prime and factorial respectively 

*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{


int a;
printf("Process Id=%d \n",getpid());
int fd1=open("kk.txt",O_RDONLY,742);  //open system call
int fd2=open("kk1.txt",O_RDONLY,S_IRWXU|S_IRGRP|S_IXOTH);
printf(" fd1=%d,fd2=%d \n", fd1,fd2);

//scanf("%d",&a);


int  p;
    p = fork();
    if(p==-1)
    {
        printf("There is an error while calling fork() \n");
        printf("Process id= %d",getpid());
    }
    if(p==0)
    {
        char *arg[]={"karthik","kk","hithasri","himasri","lavanya",NULL};
        int r=execv("./cprime",arg);
        printf(" r= %d \n",r);
        printf("We are in the child process \n");
        printf("fork returnvalue= %d , Process id= %d \n",p,getpid());
    }
    else
    {
       char *arg[]={"karthik","kk","hithasri","himasri","lavanya",NULL};   
        printf("We are in the parent process \n");
        printf("fork return value= %d , Process id= %d \n",p,getpid());
        int r=execv("./cfactorial",arg);
        printf(" r= %d \n",r);
    }
    printf("\n Before end of parent .... \n");
    scanf("%d",&a);
    printf("End of process ");
    //scanf("%d",&a);
    return 0;
}
