#ifndef _CSTR_H
#define _CSTR_H

#include <stddef.h>

typedef struct cstr {
    size_t len;
    char *buf;
} cstr;

/* cstr_newarr: create cstr from array 
 *
 * creates a new cstr with data from ARR and of length SIZE 
 * if either arguments are 0, return an empty cstr */
extern cstr cstr_newarr(const char *arr, const size_t size);

/* cstr_new: create cstr from null-terminated string
 *
 * creates a new cstr from a standard null-terminated string
 * if nulstr is NULL, return empty cstr */
extern cstr cstr_new(const char *nulstr);

/* cstr_free: frees a cstr
 *
 * frees cstr buffer and resets the length */
extern void cstr_free(cstr s);

/* cstr_buf: get cstr buffer
 *
 * returns s.buf */
extern char *cstr_buf(const cstr s);

/* cstr_len: get cstr length
 *
 * return s.len */
extern size_t cstr_len(const cstr s);

/* cstr_dup: duplicate cstr
 *
 * creates a duplicate cstr from argument S */
extern cstr cstr_dup(const cstr s);

/* cstr_ncmp: compares 2 cstrs with limit
 *
 * compares S1 to S2 up to MAX characters
 * if MAX is greater than length of the 2, compares up to the largest length */
extern size_t cstr_ncmp(const cstr s1, const cstr s2, size_t max);

/* cstr_cmp: compares 2 cstrs
 *
 * compares S1 to S2 up to the biggest's length */
extern size_t cstr_cmp(const cstr s1, const cstr s2);

/* cstr_ncat: concatenates 2 cstrs
 *
 * concatenates S2 into S1 up to MAX size */
extern void cstr_ncat(cstr *s1, const cstr s2, size_t max);

/* cstr_cat: concatenates 2 cstrs
 *
 * concatenates all of S2 into S1 */
extern void cstr_cat(cstr *s1, const cstr s2);

/* cstr_catstr: concatenates null-terminated string into cstr
 *
 * concatenates NULSTR into S1 */
extern void cstr_catstr(cstr *s1, const char *nulstr);

#endif
