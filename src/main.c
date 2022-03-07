#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* error declaration */
#define BADUSAGE "\e[0;91m[error]\e[0m Wrong arguments suplied!\n\e[0;94mUsage\e[0m: repeat <times> <string>\n"
#define PIPEBADUSAGE "\e[0;91m[error]\e[0m Wrong arguments suplied!\n\e[0;94mUsage\e[0m: program <statement> | repeat <times>\n"

int main(int argc, const char *argv[])
{
    char* str = malloc(strlen(argv[2]));
    FILE* fd = stdin;

    /* if connected to the terminal, take string from argv[2] */
    if(isatty(fileno(fd))) 
    {
        if (argc <= 1 || argc > 3) 
        {
            fprintf(stderr, BADUSAGE);
            exit(EXIT_FAILURE);
        }
        strcpy(str, argv[2]);
    }

    /* if coming from pipe, take string from stdin */
    else {
        if (argc <= 1 || argc > 2) 
        {
            fprintf(stderr, PIPEBADUSAGE);
            exit(EXIT_FAILURE);
        }
        fgets(str, 1024, stdin);
    }

    for (unsigned long int i = 0; i < strtoul(argv[1], NULL, 10); i++) { printf("%s", str); }

    return 0;
}
