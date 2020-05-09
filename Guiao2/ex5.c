#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, const char *argv[]){
    pid_t pid;
    pid_t pid_filho;
    int status;

    for (int i = 0; i < 10; i++) {
        pid = fork();

        if (pid < 0)
            perror("Fork failed");

        // Processo filho
        else if (pid == 0) {
            printf("[Processo %d] pid: %d\n", i, getpid());
            printf("[Processo %d] parent pid: %d\n", i, getppid());
        }

        // Processo pai
        else
            _exit(0);
    }
    return 0;
}
