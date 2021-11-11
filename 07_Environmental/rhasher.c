#define _GNU_SOURCE

#include <ctype.h>
#include <rhash.h>
#include <string.h>
#include <stdlib.h>

#define PROMPT NULL

#ifdef READLINE_ENABLED
#include <readline/readline.h>
#define ENDOFLINE NULL
#else
#define ENDOFLINE -1
#endif

void usage()
{
    fprintf(stderr, "Usage:\n\t <ALGORITHM NAME> <STRING (WITH \") OR FILE>\n\t Supported algorithms:\n\t\t1. MD5\n\t\t2. SHA1\n\t\t3. TTH\n\t\t4. SHA256");
}

void strToIns(char *str, size_t count, char **ins, char **data) {
    *ins = str;
    size_t j = count;
    for(size_t i = 0; i < count; i++) {
        if (str[i] == ' ') {
            str[i] = '\0';
            j = i;
            break;
        }
    }

    for(size_t i = j + 1; i < count; i++) {
        if (str[i] != ' ') {
            *data = str + i;
            break;
        }
    }

    for(size_t i = 0; i < count; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }
}

int detectNature(char **data) {
    char STRINGLITTER = '\"';

    if ((*data)[0] == STRINGLITTER) {
        *data = *data + 1;
        return 1;
    }

    return 0;
}

void makeUpper(char *data) {
    for(size_t i = 0; i < strlen(data); i++) {
        data[i] = toupper(data[i]);
    }
}

int detectType(const char *ins) {
    char *copy = (char*)malloc(strlen(ins) * sizeof(char));
    strcpy(copy, ins);

    makeUpper(copy /* out */);

    if (strcmp(copy, "MD5") == 0) {
        return 0;
    } else if(strcmp(copy, "SHA1") == 0) {
        return 1;
    } else if(strcmp(copy, "TTH") == 0) {
        return 2;
    } else if(strcmp(copy, "SHA256") == 0) {
        return 3;
    }

    free(copy);
    return -1;
}

enum rhash_print_sum_flags detectStyle(const char *ins) {

    if (isupper(ins[0])) {
        return RHPR_HEX;
    }

    return RHPR_BASE64;
}

int receiveHash(const char *ins, char *data, char *res) {
    unsigned char buffer[4096];

    enum rhash_ids algorithm;

    enum rhash_print_sum_flags style = detectStyle(ins);
    int data_type = detectNature(&data /* out */);
    int ins_type = detectType(ins);

    switch(ins_type) {
        case 0: { // MD5
            algorithm = RHASH_MD5;
        } break;
        case 1: { // SHA1
            algorithm = RHASH_SHA1;
        } break;
        case 2: { // TTH
            algorithm = RHASH_TTH;
        } break;
        case 3: { // SHA256
            algorithm = RHASH_SHA256;
        } break;
        default: {
            fprintf(stderr, "Error: Unsupported hash method\n");
            return -1;
        }
    }

    int r = 0;
    switch(data_type) {
        case 0: { // file
            r = rhash_file(algorithm, data, buffer);
        } break;
        case 1: { // string
            r = rhash_msg(algorithm, data, strlen(data), buffer);
        } break;
        default: {
            fprintf(stderr, "Error: Unsupported data\n");
            return -1;
        }
    }

    if (r < 0) {
        fprintf(stderr, "Error: Cannot take hash\n");
        return -1;
    }

    rhash_print_bytes(res, buffer, rhash_get_digest_size(algorithm), style);

    return 0;
}

int main() {
    rhash_library_init();

    char *str = NULL;
    size_t count = 0;
#ifdef READLINE_ENABLED
    printf("-- readline mode enabled --\n");
#else
    printf("-- getline mode enabled --\n");
#endif
    printf(">>> ");
#ifdef READLINE_ENABLED
    str = readline(PROMPT);
    char *cntn = str;
#else
    int cntn = getline(&str, &count, stdin);
#endif

    for(;cntn != ENDOFLINE;) {
        char *ins = NULL;
        char *data= NULL;
#ifdef READLINE_ENABLED
        count = strlen(str);
#endif

        strToIns(str, count, &ins /* out */, &data /* out */);
        
        if (data == NULL || ins == NULL) {
            usage();
        } else {
            char res[4096];
            int fail = receiveHash(ins, data, res /* out */);

            if (fail != 0) {
                printf("conversion failed\n");
            } else {
                printf("result: %s\n", res);
            }
        }
        
        printf(">>> ");

#ifdef READLINE_ENABLED
        str = readline(PROMPT);
        cntn = str;
#else
        cntn = getline(&str, &count, stdin);
#endif
    }

    printf("\n");
    return 0;
}