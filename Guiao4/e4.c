#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int mysystem(char* command) {

    int fork_ret, exec_ret, wait_ret, status, res;

    // Estamos a assunmir o maximo de argumentos isto teria de ser melhoado com realloc por exemplo

    char *exec_args[20];
    char *string;
    int i = 0;

    //Usamos aqui a função *strtok(char *str, const char *delim)
    string = strtok(command, " ");

    while (string != NULL) {
        exec_args[i] = string;
        strings = strtok(NULL, " ");
        i++;
    }

    exec_args[i] = NULL;

    //Sem fork o programa principal era trocado pelo programa no passado no exec
    fork__ret = fork(),
    if (fork_ret == 0) {
        exec_ret = execvp(exec_args[0], exec_args);
        _exit(exec_ret);
    } else {
        if (fork_ret != -1) {
            wait_ret = wait(&status);
            if (WIFEXITED(status)) {
                res = WEXITEDSTATUS(status);
            } else {
                res = -1;
            }
        } else {
            res = -1;
        }
    }
    return res;
}

int main(int argc, char* argv[]){
    int res = 0;
    int commandindex = 1;
    char command[1024];
    int input_fd, output_fd;

    bzero(stdout, NULL);

    //redirect stdin

    if(strcmp (argv[commandindex], "-i") == 0){
        input_fd = open(argv[commandindex + 1], O_RDONLY);
        res = dup2 (input_fd, 0);
        close(input_fd);

        commandindex += 2;
    }

    // REDIRECT STDOUT

    if(strcmp (argv[commandindex], "-o") == 0) {
        output_fd = open(argv[commandindex + 1], O_CREAT | O_TRUNC | O_WRONLY,0600);
        res = dup2(output_fd, 1);
        close(output_fd);

        commandindex += 2;
    }

    // parse remainder commands

    while(commandindex < argc){
        strcat (command, argv[commandindex]);
        strcat (command, " ");
        commandindex++;
    }

    //execute command
    mysystem(command);

    return 0;
}