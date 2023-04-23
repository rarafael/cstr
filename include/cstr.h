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
 * arr: pointer to char array to source from
 * size: size of array
 *
 * returns: generated cstr, must be freed with cstr_free()
 *
 * returns a cstr sourced from array 'arr' and of size 'size + 1'
 * if either arr or size are 0, return an empty cstr */
extern cstr cstr_newarr(const char *arr, const size_t size);

/* cstr_new: create cstr from null-terminated string
 * 
 * nulstr: pointer to null-terminated string
 *
 * returns: generated cstr, must be freed with cstr_free()
 *
 * creates a new cstr from a standard null-terminated string
 * if nulstr is NULL, return empty cstr */
extern cstr cstr_new(const char *nulstr);

/* cstr_free: frees a cstr
 *
 * s: cstr to be freed
 *
 * frees cstr buffer and resets the length */
extern void cstr_free(cstr *s);

/* cstr_buf: get cstr buffer
 *
 * s: cstr to get buffer from
 *
 * returns: null-terminated char buffer (s.buf) */
extern char *cstr_buf(const cstr s);

/* cstr_size: get cstr buffer size
 *
 * s: cstr to get size from
 *
 * returns: size of string in bytes (s.len);
 *          accounts for null-terminating byte */
extern size_t cstr_size(const cstr s);

/* cstr_len: get length in characters
 *
 * s: cstr to get length from
 *
 * returns: character count, same as cstr_utf_len();
 *          doesn't count whitespace characters */
extern size_t cstr_len(const cstr s);

/* cstr_dup: duplicate cstr
 *
 * s: cstr to be duplicated
 *
 * returns: a duplicate of s, to be freed with cstr_free() */
extern cstr cstr_dup(const cstr s);

/* cstr_ncmp: compares 2 cstrs with limit
 *
 * s1: reference cstr
 * s2: cstr to be compared
 * max: max amount of characters to compare in bytes
 *
 * returns: number of sequential equal bytes 
 *
 * compares 2 cstrs up to 'max' bytes, with 's1' as the reference point;
 * if either of the cstr's length is 0, or 'max' is 0, return 0;
 * if 'max' is greater than any of the cstr's length, compare up to the
 * greatest length between the two */
extern size_t cstr_ncmp(const cstr s1, const cstr s2, size_t max);

/* cstr_cmp: compares 2 cstrs
 *
 * s1: reference cstr
 * s2: cstr to be compared
 *
 * returns: number of sequential equal bytes
 *
 * compares 2 cstrs, with 's1' as the reference string, up to the biggest's
 * length */
extern size_t cstr_cmp(const cstr s1, const cstr s2);

/* cstr_cmpstr: compares cstr with null-terminated string
 *
 * s: reference cstr
 * nulstr: null-terminated string
 *
 * returns: number of sequential equal bytes
 *
 * compares with 's' as the reference string */
extern size_t cstr_cmpstr(const cstr s, const char *nulstr);

/* cstr_ncat: concatenates 2 cstrs with limit
 *
 * s1: cstr to be concatenated
 * s2: end string
 * max: max amount of bytes to add
 * 
 * concatenates 's2' into 's1' up to max characters of s2;
 * if max is greater than s2's length, concatenate up to it */
extern void cstr_ncat(cstr *s1, const cstr s2, size_t max);

/* cstr_cat: concatenates 2 cstrs
 *
 * s1: cstr to be concatenated
 * s2: end string
 *
 * concatenates all of 's2' to the end of 's1', same as
 * "cstr_ncat(s1, s2, s2.len) */
extern void cstr_cat(cstr *s1, const cstr s2);

/* cstr_catstr: concatenates null-terminated string into cstr
 *
 * s: cstr to be concatenated
 * nulstr: null-terminated end string
 *
 * concatenates all of 'nulstr' into cstr 's' */
extern void cstr_catstr(cstr *s, const char *nulstr);

/* cstr_ncpy: copy a cstr into another with max
 *
 * s1: cstr to be overwritten
 * s2: reference
 * max: max amount of bytes to overwrite
 *
 * copy 's2' into 's1' from index 0 up to 'max' bytes;
 * if max is greater than s2, copy over all of s2;
 * if s1 is not big enough to fit all of s2, reallocate it's buffer */
extern void cstr_ncpy(cstr *s1, const cstr s2, size_t max);

/* cstr_cpy: copy a cstr into another
 *
 * s1: cstr to be overwritten
 * s2: reference
 *
 * copy all of 's2' into 's1', same as "cstr_ncpy(s1, s2, s2.len)" */
extern void cstr_cpy(cstr *s1, const cstr s2);

/* cstr_cpystr: copy null-terminated string into cstr
 *
 * s: cstr to be overwritten
 * nulstr: reference null-terminated string
 *
 * copies all of 'nulstr' into cstr 's' */
extern void cstr_cpystr(cstr *s, const char *nulstr);

/* cstr_utf_len: gets length in characters from UTF-8
 *
 * s: cstr to get length from
 *
 * returns character count in UTF-8 from 's',
 * does not count whitespace characters */
extern size_t cstr_utf_len(const cstr s);

/* cstr_utf_chrindex: returns memory index to character
 *
 * s: cstr to get index from
 * chr: UTF-8 character index reference
 *
 * returns the memory index in cstr 's' to UTF-8 character of index 'chr',
 * as returned by cstr_utf_len() */
extern size_t cstr_utf_chrindex(const cstr s, const size_t chr);

#endif
