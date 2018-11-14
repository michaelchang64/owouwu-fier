/* ====================
 * Title:   owouwu-fier
 * Author:  Michael Chang
 * Date:    11/4/2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char **argv) {
    if(argc != 2) { // program terminates if there are not strictly 2 args
        return 1;
    }
    char c;
    char prev;
    FILE *f = fopen(argv[1], "r");
    while((c = fgetc(f)) != EOF) {
        if(c == 'u') {
            printf("uwu");
        } else if(c == 'o') {
            printf("owo");
        } else if(c == 'U') {
            printf("UWU");
        } else if(c == 'O') {
            printf("OWO");
        } else if(c == 'r' ||  c == 'l') {
            putchar('w');
        } else if(c == 'R' || c == 'L') {
            putchar('W');
        } else if(c == 'n' || c == 'N') {
            prev = c;
            c = fgetc(f);
            if(!isalpha(c) || ispunct(c)) {
                putchar(prev);
                putchar(c);
            } else {
                putchar(prev);
                prev = c;
                c = fgetc(f);
                if(!isalpha(c) || ispunct(c) || c == EOF) {
                    putchar(prev);
                    putchar(c);
                } else {
                    putchar('y');
                    putchar(prev);
                    ungetc(c, f);
                }
            }
        } else {
            putchar(c);
        }
    }
    putchar('\b');
    fclose(f);
    return 0;
}
