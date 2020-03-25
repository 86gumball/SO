#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void reverse(char s[]) {
     int i, j;
     char c;

     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
}

/* Implementation found on:
 * https://stackoverflow.com/questions/190229/where-is-the-itoa-function-in-linux
 */
void itoa(int n, char s[]) {
     int i, sign;

     if ((sign = n) < 0)  /* record sign */
         n = -n;          /* make n positive */
     i = 0;
     do {       /* generate digits in reverse order */
         s[i++] = n % 10 + '0';   /* get next digit */
     } while ((n /= 10) > 0);     /* delete it */
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     reverse(s);
}

size_t readln(int fd, char *line, size_t size) {
    size_t sizeRet = 0;
    while (read(fd, line, 1) && sizeRet < size - 1 && line[0] != '\n') {
        line = line + 1;
        sizeRet++;
    }
    line[sizeRet] = '\0';
    return sizeRet;
}
