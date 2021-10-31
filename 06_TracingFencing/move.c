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

int move(char *argv[]) {

    int ret = 0;

    FILE *infile;
    const char* infile_name = argv[1];
    errno = 0;
    infile = fopen(infile_name, "r");
    if (errno != 0) {
        perror("./move (trying to open the file)");
        return errno;
    }

    FILE *outfile;
    const char* outfile_name = argv[2];
    errno = 0;
    outfile = fopen(outfile_name, "wb");
    if (errno != 0) {
        perror("./move (trying to open the file)");
        ret = errno;
        errno = 0;
        fclose(infile);
        if (errno != 0) {
            perror("./move (trying to close the file)");
            ret = errno;
        }
        return ret;
    }

    char conductor[BUF_SIZE + 1]; // +1 -- spare space 
    int flag = 0;

    while(!feof(infile)) {
        errno = 0;
        fgets(conductor, BUF_SIZE, infile);
        if (errno != 0) {
            perror("./move (trying to get data from the file)");
            ret = errno;
            flag = 1;
            break;
        }
    
        errno = 0;
        fputs(conductor, outfile);
        if (errno != 0) {
            perror("./move (trying to put data into the file)");
            ret = errno;
            flag = 2;
            break;
        }
    }

    errno = 0;
    fclose(outfile);
    if (errno != 0) {
        perror("./move (trying to close the file)");
        ret = errno;
        flag = 3;
    }

    errno = 0;
    fclose(infile);
    if (errno != 0) {
        perror("./move (trying to close the file)");
        ret = errno;
        flag = 4;
    }

    if (flag == 0) {
        errno = 0;
        remove(infile_name);
        if (errno != 0) {
            perror("./move (trying to delete the file)");
            ret = errno;
        }
    }

    return ret;
}
int main(int argc, char *argv[])
{
    if (parseArgs(argc /*, argv */) != 0) {
        return -1;
    }
    
    errno = 0;
    int ret = move(argv);
    if ((ret == 0) && errno != 0) {
        perror("./move");
        ret = errno;
    }

    return 0;
}