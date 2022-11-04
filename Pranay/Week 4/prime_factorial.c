/* Author: K. Karthik
   Email id: karthikk_cse@cbit.ac.in
   
   Aim: Demostration of fork() system call 
   
   Desription: This  program is used to demonstrate the fork() system call. 
   
   
	Fork system call is used for creating a new process, which is called child process, which runs 
    concurrently with the process that makes the fork() call (parent process). After a new child process 
    is created, both processes will execute the next instruction following the fork() system call.
    A child process uses the same pc(program counter), same CPU registers, same open files which use in the parent process. 
	


Properties of Child Process: 

The following are some of the properties that a child process inherited from parent:


    1) The CPU counters and the resource utilizations are initialized to reset to zero.
    2) When the parent process is terminated, child processes do not receive any signal because PR_SET_PDEATHSIG attribute in prctl() is reset.
    3) The thread used to call fork() creates the child process. So the address of the child process will be the same as that of parent.
    4)The file descriptor of parent process is inherited by the child process. For example the offset of the file or status of flags and the I/O attributes 
    will be shared among the file descriptors of child and parent processes.So file descriptor of parent class will refer to same file descriptor of child class.
    
    5) The open message queue descriptors of parent process are inherited by the child process. For example if a file descriptor contains a message in parent process 
    the same message will be present in the corresponding file descriptor of child process. So we can say that the flag values of these file descriptors are same.
    Similarly open directory streams will be inherited by the child processes.
    
    6) The default Timer slack value of the child class is same as the current timer slack value of parent class.
    
    
The following are some of the Properties that are not inherited by Child proces:
   
    
    1) Memory locks
    2) The pending signal of a child class is empty.
    3) Process associated record locks (fcntl())
    4) Asynchronous I/O operations and I/O contents.
    5) Directory change notifications.
    6) Timers such as alarm(), setitimer() are not inherited by the child class.
    


   
*/



#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include <stdlib.h>

int main()
{
      printf(" Before fork");
      int fd1=open("kk.txt",O_RDONLY,742);  //kk.txt is a shared resource to parent and child process
      int a;   // a is shared  variable to parent and child process
      printf(" Process Id of parent %d \n",getpid());
	int rf=fork();
/* Child process and Parent process execution code can be segregated based on rturn value of fork() system call

Fork :

   Upon successful execution fork() system call   in  child process --> fork() system call will return zero value
   Upon successful execution fork() system call  in parent process --> fork() system call return positive integer value (i.e process id of child process)
   
   Upon uncusccessful execution  fork() system call --> fork() system call returns -1 and It will be in parent process 
   
    

*/	
	
	if(rf==0)   // Upon successful execution fork() -->  Child process will execute below code in if block 
	{
	      printf("Inside child process \n");
	       printf(" Process Id of child pid= %d  rf=%d \n ",getpid(),rf);
           printf("Child process: to execute the prime number program\nEnter a number: ");
	       scanf("%d",&a);
           int flag = 0;
	       for(int i=2;i<=a/2;i++){
              if (a%i==0){
                flag=1;
                break;
              }
           }
           if(flag==0){
            printf("Given number %d is a prime number\n",a);
           }
           else{
            printf("Given number %d is not a prime number\n",a);
           }
	  
	}
	
	else if (rf> 0) // Upon successful execution fork() system call --> Parent process will exceute below code in elseif block
	{
	
	  printf("Inside parent process");
	  printf(" Process Id of parent pid=%d rf=%d \n",getpid(),rf);
      printf("Parent process: to execute the factorial of a number\nEnter a number: ");
	    scanf("%d",&a);
	    int total = 1, i = 1;
        while(i<=a){
            total=total*i;
            i=i+1;
        }
        printf("Factorial value is: %d\n",total);
	}
	else{   // Upon uncusccessful execution  fork() system call Parent process will exceute below code in else block
                 printf(" Fork unsucessful \n Indide parent and Process Id of parent pid= %d  rf=%d \n  ",getpid(),rf);
         }
         
         printf("End of process %d\n", getpid());  
	
	return 0;
}

