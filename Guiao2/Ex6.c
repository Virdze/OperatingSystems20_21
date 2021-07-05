#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


int main (int argc, char * argv[]){
    if(argc < 2) {
        printf("Usage : program <needle>\n");
        exit(-1);
    }

    pid_t pid;
    int needle = atoi(argv[1]);
    int rows = 10;
    int cols = 10000;
    int rand_max = 10000;
    int status;
    int **matrix;
    //Para o exercicio 7
    int pids[rows];

    //ALOCATE and populate matrix with random numbers.

    printf("Generating numbers from 0 to %d... ",rand_max);
    matrix = (int **) malloc(sizeof(int*) * rows);
    for(int i = 0; i < rows; i++){
        matrix[i] = (int*) malloc(sizeof(int) * cols);
        for( int j = 0; j < cols; j++){
            matrix[i][j] = rand() % rand_max;
        }
    }
    printf("Done.\n");

    for(int i = 0; i < rows; i++){
        if((pid = fork() == 0)){
            //codigo do filho
            printf("[pid %d] row: %d\n", getpid(), 1);
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == needle)
                    _exit(i);
            }
            _exit(-1); // tambem pode ser _exit(255) quando nao encontrar o elemento que procura
        } else{
            //codigo pai
            pids[i] = pid;
        }
    }

    for(int i = 0; i < rows; i++){
        //pid_t terminated_pid = wait(&status);
        pid_t terminated_pid = waitpid(i,&status,0);

        if(WIFEXITED(status)){
            if(WEXITSTATUS(status) < 255){
                printf("(pai) process %d exited. Found number at row: %d\n", terminated_pid);
            } else
                printf("(pai) process %d exited. Nothing found\n",terminated_pid);
        }else {
            printf("(pai) process %d existed. Something went wrong!\n", terminated_pid);
        }
    }
    return 0;
}