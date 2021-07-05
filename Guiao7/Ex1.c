#include <stdio.h>
#include <signal.h>
#include <sys/types.h>


int ctrl_c = 0;
int segundos = 0;

void sigint_handler(int signum){
    ctrl_c++;
    printf("%d segundos\n",signum);
}

void sigquit(int signum){
    printf("%d",ctrl_c);
    exit(0);
}

void signalrm_handler(int signum){
    segundos++;
    alarm(1);
}

int main(){
    signal(SIGINT,sigint_handler);
    signal(SIGQUIT,sigquit);
    signal(SIGALRM, signalrm_handler);

    while(1){
        pause();
    }
}