#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

/*
//Exercicio 1

int main(int argc, char * argv[]){

    pid_t pid;
    int status;
    execlp(argv[1],argv[2] ,NULL);

    return 0;
}
*/

/*
//Exercicio 2

int main(int argc, char * argv[]){

    pid_t pid;
    int status;

    if((pid = fork()) == 0){
        execlp("ls","-l" ,NULL);
        _exit(pid);
    }
    else{
        pid_t terminated_pid = wait(&status);
        printf("Pai (%d) terminou filho (%d)\n", getpid(), terminated_pid);
    }

    return 0;
}

*/
/*

//Exercicio 3

int main(int argc, char * argv[]){
    printf("Argumentos recebidos:\n");

    for(int i = 1 ; i < strlen(*argv) - 2; i++){
        printf("%s ",argv[i]);
    }
    printf("\n");
    return 0;
}
*/

/*
//Exercicio 4

int main(int argc, char * argv[]) {
    strcpy(argv[0],"ex2");
    int ret = execv("ex2",argv);
    return 0;
}

*/


//Exercicio 5

int main(int argc, char** argv){

    int fork_ret, exec_ret;

    for(int i = 1; i < argc; i++){
        fork_ret = fork();
        if(fork_ret == 0){
            printf("Processom filho %d executa %s.\n",getpid(),argv[i]);
            exec_ret = execlp(argv[i],argv[i],NULL);
            perror("Reached error");
            _exit(exec_ret);
        }
    }
    for(int i = 1; i< argc; i++){
        printf("Sou o pai a espera de filhos.\n");
        wait(NULL);
    }

    printf("Todos os filhos terminaram\n");
    return 0;

}
















