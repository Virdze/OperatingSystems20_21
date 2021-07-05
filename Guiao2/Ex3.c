#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
/*
int main(){
    pid_t pid;
    int num = 10;
    int status;

    for(int i = 1; i <= num; i++){
      if((pid = fork()) == 0){
          //codigo do filho
          printf("Processo (%d) -- %d\n", getpid());
          sleep(2);
          _exit(i);
      } else {
          //codigo do pai
          pid_t terminated_pid = wait(&status);
          printf("pai: o processo %d terminou. Exit code (%d)\n", terminated_pid, WEXITSTATUS(status));
      }
    }
    return 0;
}

*/