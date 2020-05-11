#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int system(char input[]){
    int tam = strlen(input);

    char* command[tam];
    char* token;
    int i;
    int status;

    char copy_input[tam]; // Necessário, senão não funcionaria com o strtok pois podia receber const char input[]
    strcpy(copy_input, input);

    token = strtok(copy_input, " ");
    for (i = 0; token != NULL; i++) {
        command[i] = token;
        token = strtok(NULL, " ");
    }
    command[i] = NULL;

    pid_t pid;
    pid = fork();

    if (pid < 0) {
        perror("Fork failed.");
        return -1;
    } else if (pid == 0) {
        execvp(command[0], command);
        return -1;
    } else {
        wait(&status);
        return WEXITSTATUS(status);
    }
}

int main(int argc, const char *argv[]){
    system("ls -l");
    sleep(2);
    system("pwd");
    sleep(2);
    system("ps -e");
    return 0;
}
