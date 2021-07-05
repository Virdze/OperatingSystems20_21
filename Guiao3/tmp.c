#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv){
    int ret;
    char* exec_args [] =

    printf("mensagem 1\n ");

    //ret = execlp("ls","/bin/ls","-l",NULL);
    ret = execv("/bin/ls",exec_args);
    //ret = execvp("ls",exec_args);
    return 0;
}
