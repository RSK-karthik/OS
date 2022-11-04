#include<stdio.h>
#include<stdlib.h>
void func (){
    printf("Exiting from function\n");
}

int main()
{
    atexit(func);
    printf("Exiting from main()\n");
    exit(0);
}