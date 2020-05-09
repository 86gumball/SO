#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, const char *argv[]){
    char *command[] = {"ls", "-l", NULL};
    execvp("ls", command);
    perror("execvp falhou.");
    return 0;
}
