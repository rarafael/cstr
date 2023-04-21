#include <stddef.h>
#include <stdio.h>

#include "str.h"
#include "utf.h"

static int compare_character(const unsigned char c)
{
    if(c >= UTF8_CODEPOINT_16) {
        if(c >= UTF8_CODEPOINT_32) {
            if(c >= UTF8_CODEPOINT_64)
                return 3;
            return 2;
        }
        return 1;
    }
    
    return 0;
}

size_t cstr_utf_len(const cstr s)
{
    static size_t ret;
    size_t i;

    for(i = 0; i < s.len && s.buf[i] != '\0'; i++) {
        i += compare_character((unsigned char)s.buf[i]);
        ret++;
    }

    return ret;
}

size_t cstr_utf_chrindex(const cstr s, const size_t chr)
{
    static size_t count;
    size_t i, j;

    for(i = 0; i < s.len && s.buf[i] != '\0'; i++) {
        j = compare_character((unsigned char)s.buf[i]);
        i += j;
        count++;
        if(count == chr) {
            i -= j;
            break;
        }
    }

    return i;
}
