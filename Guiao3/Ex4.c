#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char** argv){
    
    strcpy(argv[0], "e3");
    int ret = execv("e3",argv);

    return 0;
}

