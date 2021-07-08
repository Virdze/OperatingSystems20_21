#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

ssize_t readln(int fd, char*line, size_t size){
    ssize_t i = 0;
    ssize_t bytes_read;

    while(i < size && (bytes_read = read(fd, line, 1)) > 0){
        i += bytes_read;
        if(line[i] == '\n') break;
    }
    return i;
}

int main() {
    char c;
    ssize_t bytes_read = 0;

    while ((bytes_read = readln(0, &c, 1)) > 0) {
        write(1, &c, sizeof(char));
    }

    return 0;
}
