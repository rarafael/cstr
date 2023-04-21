#ifndef _CSTR_STR_H
#define _CSTR_STR_H

#include <stddef.h>

typedef struct cstr {
    size_t len;
    char *buf;
} cstr;

cstr cstr_newarr(const char *arr, const size_t size);
cstr cstr_new(const char *nulstr);
void cstr_free(cstr s);
char *cstr_buf(const cstr s);
size_t cstr_len(const cstr s);
size_t cstr_size(const cstr s);
cstr cstr_dup(const cstr s);
size_t cstr_ncmp(const cstr s1, const cstr s2, size_t max);
size_t cstr_cmp(const cstr s1, const cstr s2);
void cstr_free(cstr s);
void cstr_ncat(cstr *s1, const cstr s2, size_t max);
void cstr_cat(cstr *s1, const cstr s2);
void cstr_catstr(cstr *s1, const char *nulstr);
void cstr_ncpy(cstr *s1, const cstr s2, size_t max);
void cstr_cpy(cstr *s1, const cstr s2);
void cstr_cpystr(cstr *s1, const char *nulstr);

#endif
