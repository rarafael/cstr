/* MIT License
 * 
 * Copyright (c) 2023 rarafael
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

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

/* cstr_size: get cstr buffer size
 *
 * return s.len */
extern size_t cstr_size(const cstr s);

/* cstr_len: get length in characters
 *
 * returns character count, same as cstr_utf_len() */
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

/* cstr_utf_len: gets character length from utf8
 *
 * returns length of characters in utf8 from S */
extern size_t cstr_utf_len(const cstr s);

/* cstr_ncpy: copy a cstr into another with max
 *
 * copy S2 into S1 from beginning up until MAX characters
 * if MAX is greater than S2 length, copy all of S2
 * if MAX is greater than S1 length, reallocate S1 to fit */
extern void cstr_ncpy(cstr *s1, const cstr s2, size_t max);

/* cstr_cpy: copy a cstr into another
 *
 * copy S2 into S1 */
extern void cstr_cpy(cstr *s1, const cstr s2);

/* cstr_cpystr: copy null-terminated string into cstr
 *
 * copies NULSTR into S1 */
extern void cstr_cpystr(cstr *s1, const char *nulstr);

#endif
