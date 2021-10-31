#define _GNU_SOURCE
#include <string.h>
#include <dlfcn.h>
#include <errno.h>

int remove(const char *filename) {
    typedef int (*system_call)(const char* filename);
    system_call system_remove = dlsym((void *)RTLD_NEXT, "remove");

    char *flag = strstr(filename, "PROTECT");
    if (flag != NULL) {
        errno = EPERM;
        return 1;
    }

    system_remove(filename);
    return 0;
}