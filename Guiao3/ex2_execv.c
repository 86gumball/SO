#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, const char *argv[]){
    pid_t pid = fork();
    int status;
    int execRet;

    char *command[] = {"ls", "-l", NULL};

    if (pid < 0) 
        perror("Fork failed.");

    else if (pid == 0) {
        execRet = execv("/usr/bin/ls", command);

        if (execRet == -1) {
            printf("execl failed\n");
            _exit(1);
        }
    }

    else {
        wait(&status);
        printf("\nChild executed with exit code: %d\n", WEXITSTATUS(status));
    }

    return 0;
}
