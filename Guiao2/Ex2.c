#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    pid_t pid;
    int status;

    if((pid = fork()) == 0){
        printf("Codigo processo filho (%d)\n",pid = getpid());
        sleep(2);
        _exit(0);
    }else{
        pid_t terminated_pid = wait(&status);
        printf("Filho (%d) terminou. Exit code: (%d).\nCodigo do processo pai:(%d)\n",pid,WEXITSTATUS(status),getpid());
    }

    return 0;
}
