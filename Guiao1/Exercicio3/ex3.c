#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

ssize_t readln(int fd, char*line, size_t size){
    ssize_t i = 0;
    ssize_t bytes_read;

    while(i < size && (bytes_read = read(fd, line, 1)) > 0 && line[i] != '\n')
        i += bytes_read;
    return i;
}

int main(char argc, char *argv[]) {
    int fd_dest;

    if((fd_dest = open(argv[1], O_WRONLY, O_RDONLY, O_CREAT, 0640)) < 0){
        perror("open destination error");
        return -1;
    }


    char c;
    ssize_t bytes_read = 0;

    while ((bytes_read = readln(0, &c, 1)) > 0) {
        write(fd_dest, &c, sizeof(char));
    }

    return 0;
}
