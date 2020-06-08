#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, const char *argv[]){
    char *fifo = "fifo";

    mkfifo(fifo, 0666);

    int fd = open(fifo, O_RDONLY);
    while (1)
        sleep(1);
    return 0;
}
