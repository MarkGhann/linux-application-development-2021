#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 4096

void usage() {
    fprintf(stderr, "Usage:\n\t ./move infile outfile");
}

int parseArgs(int argc /* , char *argv[] */) {
    if (argc != 3) {
        usage();
        return -1;
    }

    return 0;
}

int main(int argc, char *argv[])
{
    if (parseArgs(argc /*, argv */) != 0) {
        return -1;
    }

    FILE *infile;
    const char* infile_name = argv[1];
    errno = 0;
    infile = fopen(infile_name, "r");
    if (errno != 0) {
        perror("move: can't open the file");
    }

    FILE *outfile;
    const char* outfile_name = argv[2];
    errno = 0;
    outfile = fopen(outfile_name, "wb");
    if (errno != 0) {
        fclose(outfile);
        perror("move: can't open the file");
    }

    char conductor[BUF_SIZE + 1]; // +1 -- spare space 
    flag = true;

    while(!feof(infile)) {
        errno = 0;
        fgets(conductor, BUF_SIZE, infile);
        if (errno != 0) {
            fclose(infile);
            fclose(outfile);
            perror("move: can't get data from the file");
            flag = false;
            break;
        }

        int len = strlen(conductor);
        conductor[len - 1] = '\n';
        conductor[len] = '\0';
    
        errno = 0;
        fputs(conductor, outfile);
        if (errno != 0) {
            fclose(infile);
            fclose(outfile);
            perror("move: can't put data into the file");
            flag = false;
            break;
        }
    }

    fclose(outfile);
    fclose(infile);

    if (flag) {
        remove(infile_name);
    }

    return 0;
}