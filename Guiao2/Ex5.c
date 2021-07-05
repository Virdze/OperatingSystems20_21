#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>


int main() {
    pid_t pid;
    int num = 10;
    int status;

    for (int i = 1; i <= num; i++) {
        if ((pid = fork()) == 0) {
            //codiog filho
            printf("processo-filho (%d): %d\n", i,  getpid());

        } else {
            pid_t terminated_pid = wait(&status);
            printf("sou o pai (%d): %d -- %d\n", getpid, WEXITSTATUS(status), terminated_pid);
            _exit(i);
        }
    }
    _exit(0);
}