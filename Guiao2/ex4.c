#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, const char *argv[]){
    pid_t pid;
	int status;
    pid_t pid_filho;

	for (int i = 1; i <= 10; i ++) {
        pid = fork();
        if (fork < 0)
            perror("Fork Failed");

        // pid == 0 => processo filho
		if (pid == 0) {
			printf("[FILHO %d] PID: %d.\n", i, getpid());
			_exit(i);
		}
	}

	for (int i = 0; i < 10; i++) {
		pid_filho = wait(&status);
		printf("[PAI] process %d exited with code %d.\n", pid_filho, WEXITSTATUS(status));
	}
    return 0;
}
