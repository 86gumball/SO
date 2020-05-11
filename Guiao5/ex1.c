#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

// Comunicação pai -> filho
int main(int argc, const char *argv[]){
    int pipe_fd[2];

    if (pipe(pipe_fd) < 0) {
        perror("pipe creation failed");
        _exit(1);
    }

    pid_t pid;
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        _exit(1);
    } 

    // filho
    else if (pid == 0) {
        close(pipe_fd[1]); // Fechar descritor de escrita

        char buff[128];
        int bytes = read(pipe_fd[0], buff, 128);
        printf("Li %d bytes: %s\n", bytes, buff);
        _exit(0);
    } 

    // pai
    else {
        close(pipe_fd[0]); // Fechar descritor de leitura
        char *str = "Estra string foi criada pelo processo pai";
        write(pipe_fd[1], str, strlen(str) + 1);

        wait(NULL);
    }
    return 0;
}
