#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, const char *argv[]){
    execlp("ls", "ls", "-l", NULL);
    perror("execlp failed.");
    return 0;
}
