//
// Created by virdze on 14/04/21.
//

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char * argv[]) {
    int res = 0;

    int input_fd = open("/etc/passwd", O_RDONLY);
    int output_fd = open("saida.txt", O_CREAT | O_TRUNC | O_WRONLY, 0666);
    int error_fd = open("erros.txt", O_CREAT | O_TRUNC | O_WRONLY, 0666);

    res = dup2(input_fd, 0);
    res = dup2(output_fd, 1);
    res = dup2(error_fd, 2);

    close(input_fd);
    close(output_fd);
    close(error_fd);

    setbuf(stdout, NULL);

    res = execlp ("wc", "wc", NULL);


    return  0;

}