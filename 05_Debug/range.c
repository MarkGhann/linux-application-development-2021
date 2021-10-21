#include <stdio.h>
#include<stdlib.h>

int MAX_ARGS = 4;
int MIN_ARGS = 2;

void usage() {
    fprintf(stderr, "Usage:\n");
}

int toint(char *number) {
    return atoi(number);
}

void parseargs(int argc, char* argv[], int *mode, int *start, int *end, int *step) {
    switch(argc) {
        case 1: {
            *mode = 1;
            usage();
        } break;
        case 2: {
            *mode = 2;
            *end = toint(argv[1]);
        } break;
        case 3: {
            *mode = 3;
            *start = toint(argv[1]);
            *end = toint(argv[2]);
        } break;
        case 4: {
            *mode = 4;
            *start = toint(argv[1]);
            *end = toint(argv[2]);
            *step = toint(argv[3]);
        } break;
        default: {
            usage();
            return;
        }
    }
    
    return;
}

int main(int argc, char* argv[]) {
    int mode = 0;
    int start = 0;
    int end = 0;
    int step = 1;

    parseargs(argc, argv, &mode, &start, &end, &step);

    if (mode == 0) {
        return -1;
    }

    int i = start;
    while(i < end) {
        fprintf(stdout, "%i\n", i);
        i += step;
    }

    return 0;
}