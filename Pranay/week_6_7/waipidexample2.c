#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include<time.h>


int  main(int argc, char *argv[])
{

  int pid1,pid2;
  
  pid1=fork();
  
  if(pid1==-1)
  {
    printf("Child not created ");
    return 1;
  }
  
  if(pid1==0)
  {
    sleep(4);
    printf("In child 1 --> Finished execution %d \n",getpid());
    return 0;
  }
    
    
    pid2=fork();
    
    if(pid2==-1)
  {
    printf("Child 2 not created ");
    return 2;
  }
  
  
    if(pid2==0)
  {
    sleep(1);
    printf("In child 2 --> Finished execution %d \n",getpid());
    return 0;
  }
  
  
  int p1=waitid(pid1);
  //int p1=waitpid(pid1,NULL,0);         
  printf("Waited for %d \n",p1);
  
  int p2=waitid(pid2);
  //int p2=waitpid(pid2,NULL,0); 
  printf("Waited for %d \n",p2);
  
  
  return 0;
} 
    
