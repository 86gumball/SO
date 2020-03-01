#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define bufferSize 128

int main(void){
    char buffer[bufferSize];
    char errorPrint[] = "Couldn't open source file\n";
    int charsRead;

    int source = open("testfile.txt", O_RDONLY);
    if (source == -1) {
        write(1, errorPrint, strlen(errorPrint));
        return -1;
    }

    int dest = open("destfile.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
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
