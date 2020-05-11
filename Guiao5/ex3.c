#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, const char *argv[]){
    int pipe_fd[2];

    if (pipe(pipe_fd) < 0) {
        perror("pipe failed");
        _exit(1);
    }

    pid_t pid;
    pid = fork();
    if (pid < 0) {
        perror("fork failed");
        _exit(1);
    }

    // filho
    else if (pid == 0) {
        close(pipe_fd[1]); // fechar o descritor de escrita

        dup2(pipe_fd[0], 0);
        // 0, pipe_fd[0] -> leitura pipe

        close(pipe_fd[0]);
        // 0 -> leitura pipe
 
        execlp("wc", "wc", NULL);
        
        _exit(1);
    }
    
    // pai
    else {
        close(pipe_fd[0]); // fechar o escritor de leitura

        char buffer[128];
        int bytes = 0;
        while ((bytes = read(0, buffer, 127)) > 0) 
            write(pipe_fd[1], buffer, bytes);

        close(pipe_fd[1]);
        wait(NULL);
    }
    return 0;
}
