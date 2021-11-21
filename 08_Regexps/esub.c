#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>
#include <ctype.h>

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

int reduce(const char *sub, char *new_sub) {
    size_t size = strlen(sub);
    size_t i = 0;
    size_t j = 0;
    while(i < size) {
        if (sub[i] == '\\') {
            i++;
            if (i == size) {
                fprintf(stderr,"Invalid substitution: not enough characters (ends wuth '\\') \n");
                return -1;
            } else if (sub[i] == '\\') {
                new_sub[j] = sub[i];
            }
        } else {
            new_sub[j] = sub[i];
        }
        i++;
        j++;
    }

    return 0;
}

int convertToDigit(char ch) {
    return ch - '0';
}

int replaceSymbolsOnce(const char *s, const char *sub, regmatch_t pm[], char *result) {
    size_t FIRST = 0;

    size_t begin = pm[FIRST].rm_so;
    size_t end = pm[FIRST].rm_eo;
    size_t size = strlen(s);
    size_t subsize = strlen(sub);

    for(size_t i = 0; i < begin; i++) {
        result[i] = s[i];
    }

    result[begin] = '\0';
    size_t tmpsize = strlen(result);
    for(size_t i = 0; i < subsize; i++) {
        result[i + tmpsize] = sub[i];
    }

    for(size_t i = 0; i < size - end; i++) {
        result[i + tmpsize + subsize] = s[end + i];
    }

    result[tmpsize + subsize + size - end] = '\0';

    return 0;
}

int main(int argc, char *argv[]) {

    if (parseArgs(argc) != 0) {
        fprintf(stderr, "Cannot parese the arguments.\n");
        usage();
        return 1;
    }
    
    char result[4096];
    char sub[4096];
    size_t number = 0;
    size_t PM = strlen(argv[3]);

    regex_t re;
    regmatch_t pm[PM];

    if (regcomp(&re, argv[1], 0)) {
        fprintf(stderr,"Cannot compile the regexp\n");
        return 2;
    }
    
    strcpy(result, argv[3]);

    if (!regexec(&re, argv[3], PM, pm, 0)) {
        if (reduce(argv[2], sub /* out */) != 0) {
            fprintf(stderr, "Incorrect sub\n");
            return 3;
        }
        replaceSymbolsOnce(argv[3], argv[2], pm, result /* out */);
    }

    printf("%s\n", result);

    regfree(&re);

    return 0;
}