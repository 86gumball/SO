#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int ctrl_c_counter = 0;
int segundos = 0;

void sigint_handler(int signum) {
    printf("Error received\n");
    printf("Time passed: %d\n", segundos);
    ctrl_c_counter++;
}

void sigquit_handler(int signum) {
    printf("O utilizador clicou %d vezes em Ctrl+C\n", ctrl_c_counter);
    _exit(0);
}

void sigalrm_handler(int signum) {
    segundos++;
    alarm(1);
}

int main(int argc, const char *argv[]){
    if ((signal(SIGINT, sigint_handler) == SIG_ERR))
        perror("signal failed");

    if ((signal(SIGQUIT, sigquit_handler) == SIG_ERR))
        perror("signal failed");

    if ((signal(SIGALRM, sigalrm_handler) == SIG_ERR))
        perror("signal failed");

    alarm(1);
    while (1)
        pause();

    return 0;
}
