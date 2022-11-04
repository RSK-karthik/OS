#include <stdio.h>
#include <stdlib.h>
#include<fcntl.h>
#include<unistd.h>

//File Discriptors
int fd1;
int fd2;

void functionA () {  // Exit Handler 
   close(fd1); 
   printf("We are in  functionA and closed the file fd1 \n");
}

void functionB () {  // Exit Handler 
   close(fd2); 
   printf("We are in  functionB and closed the file fd2\n");
}



int main () {
   /* register the termination function */
   char buf[10];
   fd1=open("file1.txt",O_RDONLY,742); 
   fd2=open("file2.txt",O_RDONLY,S_IRWXU|S_IRGRP|S_IXOTH);
   
   read(fd1,buf,10);
   write(1,buf,10);
   printf("\nCompleted the operation A \n");
   atexit(functionA );
   
   read(fd2,buf,10);
   write(1,buf,10);
   printf("\nCompleted the operation B \n");
   atexit(functionB );
   
   printf("Starting  main program...\n");

   printf("Exiting main program...\n");

   return(0);
}
