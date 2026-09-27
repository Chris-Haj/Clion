#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int childPid;

void handler(int num) {
    printf("son change status\n");
}

int main() {
    int waitReturnPid;
    childPid = fork();
    signal(SIGCHLD, handler);
    if (childPid == 0) {
        while(1){
            printf("w.\n");
        }
        printf("never visit here\n");
    } else {
        kill(childPid,SIGINT);
        wait(NULL);
        printf("Parent exiting...\n");
    }
}