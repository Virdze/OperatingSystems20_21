#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv){
    int ret;
    int pid;
    int status;

    printf("mensagem 1\n ");
    if ( (pid = fork() == 0)){
        //codigo filho
        ret = execl("/bin/ls","/bin/ls", "-l", NULL);

        printf("mensagem 2(filho)\n");
        _exit(0);
    } else {
        //codigo pai
        pid_t terminated_pid = wait(&status);

        printf("pai processo %d terminou com o exit code %d", terminated_pid, WEXITSTATUS(status));
        printf("mensagem 2 pai \n");
    }

    return 0;
}
