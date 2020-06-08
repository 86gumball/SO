#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, const char *argv[]){
    char *fifo = "fifo";

    mkfifo(fifo, 0666);

    int fd = open(fifo, O_RDONLY);
    char buffer[128];
    while (1) {
        int bytes = read(fd, buffer, 127);
        write(1, buffer, bytes);
    }
    return 0;
}
