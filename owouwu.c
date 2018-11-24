/* ====================
 * Title:   owouwu-fier
 * Author:  Michael Chang
 * Date:    11/4/2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int isvowel(int ch);
int nyCase(int ch);

int main(int argc, char **argv) {
    if(argc != 2) { // program terminates if there aren't strictly 2 args
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
                putchar(prev);
            if(!isalpha(c) || ispunct(c)) {
                putchar(c);
            } else {
                prev = c;
                c = fgetc(f);
                if(nyCase(prev)) {
                    putchar(prev);
                    putchar(c);
                } else {
                    if(isupper(prev))
                        putchar('Y');
                    else
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

int isvowel(int ch) {
    int c = toupper(ch);
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int nyCase(int ch) {
    int c = toupper(ch);
    return (!isvowel(c) || c == 'Y' || !isalpha(c) || ispunct(c) || c == EOF);
}
