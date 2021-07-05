#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char** argv){

    int fork_ret, exec_ret;

    for(int i = 1; i <argc; i++){
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