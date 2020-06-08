#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, const char *argv[]){
    char *fifo = "fifo";

    mkfifo(fifo, 0666);

    int fd = open(fifo, O_WRONLY);
    char buffer[128];
    while (1) {
        int bytes = read(0, buffer, 127);
        write(fd, buffer, bytes);
    }
    return 0;
}
