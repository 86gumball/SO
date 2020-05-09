#include <stdio.h>

int main(int argc, const char *argv[]){
    printf("Número de argumentos: %d\n", argc);
    printf("Lista de argumentos: {\n");
    for (int i = 0; i < argc; i++) {
        printf("\t\"%s\",\n", argv[i]);
    }
    printf("}\n");
    return 0;
}
