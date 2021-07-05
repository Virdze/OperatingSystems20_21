//
// Created by virdze on 28/04/21.
//

#include <unistd.h
#include <stdio.h>
#include <sys/wait.h
#include <fcntl.h

int min(int argv, char* argv[]){

    int res = 0;
    int p[2];
    int pid;
    int status;

    if(pipe(p) == -1) {
        perror("pipe error");
        return -1;
    }

    switch ((pid = fork())) {
        case -1;
            perror ("fork");
            return -1;
        case 0:
            //codigo filho - produtor -> ls
            close(p[0]);

            dup2(p[1],1);
            close(p[1]);

            execlp("ls","ls", "/etc",NULL);
            _exit(0);
        default:
            //codigo pai - consumidor -> wc

            close(p[1]);

            dup2(p[0], 0);
            close(p[0]);

            execlp("wc","wc","-l")
    }
}