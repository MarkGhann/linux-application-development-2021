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
            }
            if (isdigit(sub[i]) != 0) {
                new_sub[j] = '\\';
                j++;
            }
            new_sub[j] = sub[i];
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
    size_t pmsize = 0;

    for(size_t p = 0; p < strlen(s); p++) {
        if (pm[p].rm_eo != -1) {
            pmsize++;
        } else {
            break;
        }
    }

    size_t i = begin;
    size_t j = 0;
    size_t k = 0;
    while(j < subsize) {
        if (sub[j] == '\\') {
            if (isdigit(sub[j + 1]) != 0) {
                j++;

                int d = convertToDigit(sub[j]);
                if (d >= pmsize) {
                    fprintf(stderr,"Invalid substitution: nonexistent nesting %d (total: %ld).\n", d, pmsize);
                    return -1;
                }

                for(k = pm[d].rm_so; k < pm[d].rm_eo; i++, k++) {
                    result[i] = s[k];
                }

                j++;
                continue;
            }
        }
        result[i] = sub[j];
        i++;
        j++;
    }

    for(size_t k = 0; s[end + k] != '\0'; i++, k++) {
        result[i] = s[end + k];
    }
    result[i] = '\0';

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
    char err[4096];
    size_t number = 0;
    size_t PM = strlen(argv[3]);

    regex_t re;
    regmatch_t pm[PM];

    int r = regcomp(&re, argv[1], REG_EXTENDED);
    size_t n = regerror(r, &re, err, 4096);

    if (strcmp(err, "Success") != 0) {
        fprintf(stderr,"Cannot compile the regexp\n");
        return 2;
    }
    
    strcpy(result, argv[3]);

    r = regexec(&re, argv[3], PM, pm, 0);
    n = regerror(r, &re, err, 4096);

    if (strcmp(err, "Success") == 0) {
        if (reduce(argv[2], sub /* out */) != 0) {
            fprintf(stderr, "Incorrect sub\n");
            return 3;
        }

        if (replaceSymbolsOnce(argv[3], sub, pm, result /* out */) != 0) {
            fprintf(stderr, "Cannot replace.\n");
            return 4;
        }
    }

    printf("%s\n", result);

    regfree(&re);

    return 0;
}