#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define bufferSize 128

int main(int argc, char* argv[]){
    char buffer[bufferSize];
    int charsRead;

    if (argc != 3 | argv[1] == "--help") {
        printf("Usage: ./mycp <source> <dest>\n");
        return 0;
    }

    int source = open(argv[1], O_RDONLY);
    if (source == -1) {
        printf("Couldn't open source file\n");
        return -1;
    }

    int dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (dest == -1) {
        printf("Couldn't open dest file\n");
        close(source);
        return -1;
    }

    while ((charsRead = read(source, buffer, bufferSize)) > 0) {
        write(dest, buffer, charsRead);
    }

    close(source);
    close(dest);
    return 0;
}
