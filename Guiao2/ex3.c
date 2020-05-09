#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, const char *argv[]){
    pid_t pid;
    pid_t pid_filho;
    int status;

    for (int i = 1; i <= 10; i++) {
        // Executa o fork() e testa se funciona antes de correr o resto do código
        pid = fork();
        if (pid < 0)
            perror("Fork failed");

        // pid == 0 => processo filho
        else if (pid == 0) {
            printf("[FILHO %d] O meu pid é: %d\n", i, getpid());
            printf("[FILHO %d] O pid do meu pai é: %d\n", i, getppid());
            _exit(i);
        } else {
            pid_filho = wait(&status);
            printf("[PAI] O meu processo filho %d terminou com código %d\n", pid_filho, WEXITSTATUS(status));
        }
    }

    return 0;
}
