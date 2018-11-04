/* ====================
 * Title:   owouwu-fier
 * Author:  Michael Chang
 * Date:    11/4/2018
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if(argc != 2) { // program terminates if there are not strictly 2 args
        return 1;
    }
    char c;
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
        } else if(c == 'r') {
            putchar('w');
        } else {
            putchar(c);
        }
    }
    fclose(f);
    return 0;
}
