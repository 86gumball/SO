#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, const char *argv[]){
    // Abrir os descritores
    int in_passwd = open("/etc/passwd", O_RDONLY);
    int out_saida = open("saida.txt", O_CREAT | O_WRONLY | O_APPEND, 0777);
    int err_erros = open("erros.txt", O_CREAT | O_WRONLY | O_APPEND, 0777);

    // Duplicação dos descritores
    int a = dup2(in_passwd, 0);
    int b = dup2(out_saida, 1);
    int c = dup2(err_erros, 2);

    // Error checking
    if (a == -1) 
        printf("Failed dup2 for stdin\n");
    if (b == -1) 
        printf("Failed dup2 for stdout\n");
    if (c == -1) 
        printf("Failed dup2 for stderr\n");

    // Teste prints
    printf("Isto deve aparecer em saida.txt\n");
    perror("Isto deve aparecer em erros.txt");

    // Teste gets
    char line[128];
    fgets(line, 127, stdin);
    printf("%s\n", line);


    // Fechar os descritores
    close(in_passwd);
    close(out_saida);
    close(err_erros);
    return 0;
}
