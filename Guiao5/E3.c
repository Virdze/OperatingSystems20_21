//
// Created by virdze on 28/04/21.
//

#include <stdio.h>
#include <sys/wait.h
#include <fcntl.h

#define MAX_LINE_SIZE 1024

// tem que devoler \n

ssize_t readln(int fildes, void *buf, size_t nbyte){
    ssize_t res = 0;
    int i= 0;
    while(i<nbyte && (res = read(fildes, &buf[i], l))> 0){
        if(((char*) buf)[i] == "\n")
            return i+1;
        i+=res;
    }
    return i;
}

int main(int argc, char* argv[]){

    int res =0;
    int p[2];
    char buffer[MAX_LINE_SIZE]; // TAMANHO MAXIMO LINHA
    int pid;
    int status;

    if(pipe[p] == -1){
        perror("pipe error");
        return -1;
    }

    switch ((pid == fork())) {
        case -1:
            perror ("fork");
            return -1;
        case 0:
            // codigo filho - consumidor
            close(p[1]);

            //redirecionar o stdin
            dup2(p[0],0);
            close(p[0]);

            res = execlp("wc", "wc", NULL);
            _exit(0);
        default:
            //codigo pai - produtor

            printf("Pai (%d) --- %d\n", getpid(), pid);
            close(p[0]);

            while((res = readln(0, buffer, MAX_LINE_SIZE))>0){
                write(p[1], buffer, res);
            }

            close(p[1]);
            wait(&status);

            if(WIFEXITED(status)){
                printf("PAI: filho terminou com %d\n",WIFEXITED(status));
            }
    }
}