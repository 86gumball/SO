#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/* Se no final executar executar o comando "ps" e o identificador do pai
 * corresponder à shell em uso, no meu caso bash, funcionou corretamente.
 */

int main(int argc, const char *argv[]){
    printf("O meu identificador é: %d\n", getpid());
    printf("O identificador do meu pai é: %d\n", getppid());
    return 0;
}
