#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main(){

    pid_t pid;
    int status;

    if((pid = fork()) == 0){
        printf("PID :: %d", getpid());
        _exit(0);
    }
    else{
        pid_t terminated_pid = wait(&status);
        printf("O processo filho %d terminou. Exit code (%d)\n",terminated_pid, WEXITSTATUS(status));
        printf("Codigo do processo pai (%d)\n",getpid());
    }

    return 0;
}
