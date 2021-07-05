//
// Created by virdze on 21/04/21.
//


#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/wait.h>
#include <string.h>


int main(arg){

    int p[2];
    char line[] = "linha\n";
    char buffer[20];
    int res;
    int status;

    //criar pipe
    if(pipe(p) == -1){
        perror("Pipe not createdd");
        return -1;
    }

    switch(fork()) {
        case -1:
            perror("Fork not made");
            return -1;
        case 0:
            //codigo filho
            //fechar extremidade e escrita

            close(p[1]);

            //ler do pipe
            res = read(p[0], &buffer, sizeof(buffer));
            printf("Filho: read %s from pipe: res = %d\n", buffer, res);

            //fechar extremidade de leitura (não precisa mais dele)

            close(p[0]);
            _exit(0);
        default:
            //codigo pai
            //fechar exremidade de leitura
            close(p[0]);

            // escrever para o pipe
            for(int i = 0; i< num)
                write(p[1], &line, strlen(line));
            printf("[PAI] wrote line to piep");

            //fechar extremidade de escrita (não precisa mais dele)
            close(p[1]);
            wait(&status);
    }

    return 0;

}