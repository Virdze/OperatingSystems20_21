/*
 * A função system faz a execucao de um prog ou de um comando externo ao prog
 *
 */

#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int mysystem(char* command){

    int fork_ret, exec_ret, wait_ret, status,res;

    // Estamos a assunmir o maximo de argumentos isto teria de ser melhoado com realloc por exemplo

    char *exec_args[20];
    char *string;
    int i = 0;

    //Usamos aqui a função *strtok(char *str, const char *delim)
    string = strtok(command," ");

    while(string != NULL) {
        exec_args[i] = string;
        strings = strtok(NULL, " ");
        i++;
    }

    exec_args[i] = NULL;

    //Sem fork o programa principal era trocado pelo programa no passado no exec
    fork__ret = fork(),
    if(fork_ret==0) {
        exec_ret = execvp(exec_args[0], exec_args);
        _exit(exec_ret);
    }
    else {
        if (fork_ret != -1) {
            wait_ret = wait(&status);
            if(WIFEXITED(status)){
                res = WEXITEDSTATUS(status);
            }
            else{
                res=-1;
            }
        }
        else{
            res=-1;
        }
    }
    return res;
}