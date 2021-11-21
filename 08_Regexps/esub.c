#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

#define PM 4

void usage()
{
    fprintf(stderr, "Usage:\n\t ./esub <regexp> <substitution> <string>\n\n");
}

int parseArgs(int argc)
{
    int ARGS_NUM = 4;

    if (argc != ARGS_NUM) {
        return -1;
    }

    return 0;
}

int main(int argc, char *argv[]) {

    if (parseArgs(argc) != 0) {
        return 1;
    }

    size_t number = 0;
    char *line=NULL;

    regex_t re;
    regmatch_t pm[PM];

    if (regcomp(&re, argv[1], 0)) {
        return 2;
    }

    for(; getline(&line, &number, stdin); number=0, line=NULL) {
        if (!regexec(&re, line, PM, pm, 0)) {
            for(int i = 0; i < PM; i++) {
                printf("%d: %d/%d\n", i, pm[i].rm_so, pm[i].rm_eo);
            }
        } else {
            // pass
        }
        free(line);
    }

    regfree(&re);

    return 0;
}