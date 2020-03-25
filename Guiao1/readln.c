#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "reusable_funcs.h"

#define sizeLine 128

int main(int argc, const char *argv[]){
    char line[sizeLine];

    int source = open("testfile.txt", O_RDONLY);
    if (source == -1) {
        printf("Couldn't oppen source file\n");
        return -1;
    }

    size_t sizeRet = readln(source, line, sizeLine);
    printf("%ld chars were read\n", sizeRet);
    printf("%s\n", line);
    
    close(source);
    return 0;
}
