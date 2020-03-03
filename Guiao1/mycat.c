#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    char input;

    if (argc != 1 | argv[1] == "--help") {
        printf("Usage: ./mycat\n");
        return 0;
    }

    while (read(0, &input, 1) > 0 && input != '\n') {
        write(1, &input, 1);
    }
    printf("\n");
    return 0;
}
