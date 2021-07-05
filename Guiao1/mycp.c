#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(char argc, char **argv){
    int res = open(argv[1],O_CREAT | O_TRUNC | O_RDWR, 0600);
    for()
}