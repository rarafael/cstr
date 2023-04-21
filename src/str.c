#include <stdlib.h>

#include "str.h"
#include "mem.h"

cstr cstr_newarr(const char *arr, const size_t size)
{
    static cstr ret;
    size_t i;

    if(!arr || !size)
        return ret;

    ret.len = size + 1;
    ret.buf = ecalloc(ret.len, sizeof(char));

    for(i = 0; i < size; i++) {
        ret.buf[i] = arr[i];
    }

    ret.buf[ret.len - 1] = '\0';

    return ret;
}

cstr cstr_new(const char *nulstr)
{
    static size_t len;

    if(!nulstr)
        return cstr_newarr(nulstr, len);

    for(len = 0; nulstr[len] != '\0'; ++len);

    return cstr_newarr(nulstr, len);
}

size_t cstr_len(const cstr s)
{
    return s.len;
}

char *cstr_buf(const cstr s)
{
    return s.buf;
}

cstr cstr_dup(const cstr s)
{
    return cstr_newarr(s.buf, s.len);
}

size_t cstr_ncmp(const cstr s1, const cstr s2, size_t max)
{
    static size_t ret;

    if(!max)
        return ret;

    if(max > s1.len || max > s2.len)
        max = s1.len >= s2.len ? s1.len : s2.len;

    for(ret = 0; ret < max; ret++) {
        if(s1.buf[ret] != s2.buf[ret])
            break;
    }

    return ret;
}

size_t cstr_cmp(const cstr s1, const cstr s2)
{
    static size_t max;

    max = s1.len >= s2.len ? s1.len : s2.len;

    return cstr_ncmp(s1, s2, max);
}

void cstr_free(cstr s)
{
    free(s.buf);
    s.len = 0;
}

void cstr_ncat(cstr *s1, const cstr s2, size_t max)
{
    size_t i, j;

    if(max >= s2.len)
        max = s2.len;

    j = s1->len - 1;
    s1->len += max;
    s1->buf = erealloc(s1->buf, s1->len);

    for(i = 0; i < max; i++, j++) {
        s1->buf[j] = s2.buf[i];
    }
}

void cstr_cat(cstr *s1, const cstr s2)
{
    cstr_ncat(s1, s2, s2.len);
}

void cstr_catstr(cstr *s1, const char *nulstr)
{
    cstr tmp;
    tmp = cstr_new(nulstr);
    cstr_cat(s1, tmp);
    cstr_free(tmp);
}