#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void *ecalloc(size_t n, size_t len)
{
    static void *ret;

    ret = calloc(n, len);
    if(!ret) {
        fprintf(stderr, "failed calloc: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    return ret;
}

void *erealloc(void *ptr, size_t len)
{
    static void *ret;

    ret = realloc(ptr, len);
    if(!ret && (len)) {
        free(ptr);
        fprintf(stderr, "failed realloc: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    return ret;
}
