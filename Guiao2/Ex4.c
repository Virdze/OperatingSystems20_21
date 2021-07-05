#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(){
    pid_t pid;
    int num = 10;
    int status;

    for(int i = 1; i <= num; i++) {
        if((pid = fork()) == 0){
            //codigo do filho
            printf("Processo filho (%d): %d\n",i,getpid());
            sleep(3);
            _exit(i);
        }
    }

    for(int i = 1; i <= num; i++){
        pid_t terminated_pid = wait(&status);
        printf("Pai -- processo (%d) - (%d)\n", WEXITSTATUS(status),terminated_pid);
    }

    return 0;
}