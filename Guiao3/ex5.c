#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, const char *argv[]){
    pid_t pid;
    int status;

    for (int i = 1; i < argc; i++) {
        pid = fork();
        if (pid < 0) 
            perror("Fork failed.");
        else if (pid == 0) 
            execlp(argv[i], argv[i], NULL);
        else 
            wait(NULL);
    }
    return 0;
}
