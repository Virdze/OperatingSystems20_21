#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

#define MAXBUFFERSIZE 1024


int main(char argc, char *argv[]) {
    int fd_source, fd_dest;
    ssize_t bytes_read;

    clock_t start, stop;
    double time;

    start = clock();

    if ((fd_source = open(argv[1], O_RDONLY)) < 0) {
        perror("open");
        return -1;
    }

    if ((fd_dest = open(argv[2], O_WRONLY, O_RDONLY, O_CREAT, 0640)) < 0) {
        perror("open");
        return -1;
    }
    char buffer[MAXBUFFERSIZE];

    while ((bytes_read = read(fd_source, buffer, MAXBUFFERSIZE)) > 0) {
        write(fd_dest, buffer, bytes_read);
    }

    close(fd_source);
    close(fd_dest);

    stop = clock();

    printf("Took %ld seconds to execute this process\n", (stop - start)/CLOCKS_PER_SEC);

    return 0;
}