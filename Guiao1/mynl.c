#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "reusable_funcs.h"

#define sizeLine 128

int main(int argc, const char *argv[]){
    char line[sizeLine];

    // TODO: Change --help comparison to strcmp
    if ((argc != 2) | (argv[1] == "--help")) {
        printf("Usage: ./mynl <source>\n");
        return 0;
    }

    int source = open(argv[1], O_RDONLY);
    if (source == -1) {
        printf("Couldn't open source file\n");
        return -1;
    }

    char intString[10];
    for (int i = 0; readln(source, line, sizeLine); i++) {
        itoa(i, intString); // Convert i to string and store it in intString
        strcat(intString, " ");
        write(1, intString, strlen(intString)); // Print it to stdout
        write(1, line, strlen(line));
    }

    close(source);
    return 0;
}
