#include <stdio.h>
#include <unistd.h>

/* From 'man 2 fork':
 * On success, the PID of the child process is returned in the parent, and 0 is returned in the child.
 * On failure, -1 is returned in the parent, no child process is  created,  and errno is set appropriately.
*/

int main(int argc, const char *argv[]){
    int pid = fork();
    if (pid < 0) {
        perror("Fork failed");
    } else if (pid == 0) {
        printf("(FILHO) O meu identificador é: %d\n", getpid());
    } else {
        printf("(PAI) O meu identificador é: %d\n", getpid());
        printf("(PAI) O identificador do meu filho é: %d\n", pid);
    }
    return 0;
}
