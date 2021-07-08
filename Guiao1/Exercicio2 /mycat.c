#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define MAXBUFFERSIZE 1024

int main(){

    ssize_t bytes_read = 0;
    char * buffer = malloc(MAXBUFFERSIZE * sizeof(char));

    while((bytes_read = read(0, buffer, MAXBUFFERSIZE)) > 0){
        write(1,buffer,MAXBUFFERSIZE);
    }
    return 0;
}