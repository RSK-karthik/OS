
// int main()
// {
//     pid_t pid;
//     int status;
//     siginfo_t info;
//     if ((pid=fork())<0){
//         printf("fork error");
//     }
//     else if(pid==0){
//         exit(7);
//     }
//     if (waitid(P_ALL,0,&info,WEXITED)!=pid){
//         printf("wait error");
//     }
//     printf("%d\n",status);
//     if ((pid=fork())<0){
//         printf("fork error");
//     }
//     else if(pid == 0){
//         abort();
//     }
//     if (waitid(P_ALL,0,&info,WEXITED)!=pid){
//         printf("wait error");
//     }
//     printf("%d\n",status);
//     if ((pid = fork()) < 0)
//         printf("fork error");
//     else if (pid == 0)              /* child */
//         status = 0;                /* divide by 0 generates SIGFPE */

//     if (waitid(P_ALL,0,&info,WEXITED) != pid)       /* wait for child */
//         printf("wait error");
//     printf("\n%d\n",status);               /* and print its status */

//     exit(0);
// }

#define pr_exit(n) printf("%d\n", n)
#define err_sys perror
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(void)
{
    pid_t   pid;
    int     status;
    siginfo_t info;
    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0)              /* child */
        exit(7);

    if (waitid(P_PID,pid,&info,WEXITED) != pid)       /* wait for child */
        err_sys("wait error");
    pr_exit(status);                /* and print its status */

    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0)              /* child */
        abort();                    /* generates SIGABRT */

    if (waitid(P_PID,pid,&info,WEXITED) != pid)       /* wait for child */
        err_sys("wait error");
    pr_exit(status);                /* and print its status */

    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0)              /* child */
        status = 0;                /* divide by 0 generates SIGFPE */

    if (waitid(P_PID,pid,&info,WEXITED) != pid)       /* wait for child */
        err_sys("wait error");
    pr_exit(status);                /* and print its status */

    exit(0);
}