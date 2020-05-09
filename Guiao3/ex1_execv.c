#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, const char *argv[]){
    char *command[] = {"ls", "-l", NULL};
    execv("/usr/bin/ls", command);
    perror("execv falhou.");
    return 0;
}
