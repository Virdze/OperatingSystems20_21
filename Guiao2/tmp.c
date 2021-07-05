#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
/*
int main() {

    pid_t pid = getpid();
    pid_t ppid = getppid();

    printf("-> main: %d\n", pid);
    printf("-> pai da main: %d\n",ppid);

    pid_t filho;
    if((filho = fork()) == 0) {
        sleep(1);
        _exit(0);
    }

    printf ( "passei aqui (%d) \n",filho);

    return 0;
}
*/