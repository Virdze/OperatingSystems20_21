#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

/*
// Exercicio 4

int main() {
    pid_t pid;
    int status;

    for(int i = 0; i < 10 ; i++){
        if((pid = fork()) == 0){
            printf("Código do filho: (%d)\n", getpid());

            _exit(i);
        }
    }

    for(int i = 0; i < 10; i++){
        pid_t terminated_pid = wait(&status);
        printf("Pai: exit code(%d) - %d\n", WEXITSTATUS(status),terminated_pid);
    }

    return 0;
}
*/

/*
//Exercicio 5

int main(){

    pid_t pid;
    int status;

    for(int i = 0 ; i < 10; i++){
        if((pid = fork()) == 0){
            printf("processo_filho (%d) : %d\n", i, getpid());
        }
        else{
            pid_t terminated_pid = wait(&status);
            printf("Sou o pai (%d): %d -- %d\n", getpid(), WEXITSTATUS(status),terminated_pid);
            _exit(i);
        }
    }
    _exit(0);

}
*/
//Exercicio 6

int main(int argc, char * argv[]){

    if(argc < 2){
        printf("usage: prigram <needle>\n");
        _exit(-1);
    }

    pid_t pid;

    int needle = atoi(argv[1]);
    int rows = 10;
    int cols = 10000;
    int rand_max = 10000;
    int status;
    int **matrix;
    int pids[rows];

    printf("Generating numbers from 0 to %d... ",rand_max);
    matrix = (int **) malloc(sizeof(int*) * rows);
    for(int i = 0; i < rows; i++){
        matrix[i] = (int*) malloc(sizeof(int) * cols);
        for( int j = 0; j < cols; j++){
            matrix[i][j] = rand() % rand_max;
        }
    }
    printf("Done.\n");

    for(int i = 0; i < rows; i++) {
        if ((pid = fork()) == 0) {
            printf("[pid %d] row : %d\n", getpid(), i);
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == needle)
                    _exit(i);
            }
            _exit(-1);
        }
        else{
            //codigo pai
            pids[i] = pid;
        }

    }

    for(int i = 0; i < rows; i++){
        pid_t terminated_pid = waitpid(i,&status,0);

        if(WIFEXITED(status)){
            if(WEXITSTATUS(status) < 255){
                printf("(pai) process %d exited. FOUND NUMBER AT ROW: %d\n", getpid(),terminated_pid);
            }else
                printf("(pai) process %d exited. Nothing found\n",terminated_pid);
        }else {
            printf("(pai) process %d existed. Something went wrong!\n", terminated_pid);
        }
    }
    return 0;
}