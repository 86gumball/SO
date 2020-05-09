#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, const char *argv[]){
    execl("/usr/bin/ls", "ls", "-l", NULL);
    perror("execl falhou.");
    return 0;
}
