#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv){
    int ret;


    printf("mensagem 1\n ");
    //Exercicio1 resume-se a esta alinea
    //ret = execl("/bin/ls","/bin/ls","-l",NULL);



    //ret = execlp("ls","/bin/ls","-l",NULL);
    ret = execv("ls","/bin/ls","-l",NULL);

    return 0;
}
