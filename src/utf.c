#include <stddef.h>
#include <stdio.h>

#include "str.h"
#include "utf.h"

static int get_charsize(const unsigned char c)
{
    if(c >= UTF8_CODEPOINT_16) {
        if(c >= UTF8_CODEPOINT_24) {
            if(c >= UTF8_CODEPOINT_32)
                return UTF8_CHARSIZE_32;
            return UTF8_CHARSIZE_24;
        }
        return UTF8_CHARSIZE_16;
    }
    return UTF8_CHARSIZE_8;
}

static utf8_char_t get_char(const cstr s, const size_t chrindex)
{
    static utf8_char_t ret;

    switch(get_charsize(s.buf[chrindex])) {
        case UTF8_CHARSIZE_8: 
            ret.c8 |= (utf8_char8_t)s.buf[chrindex]; break;
        case UTF8_CHARSIZE_16: {
            ret.c16 |= (utf8_char16_t)s.buf[chrindex] << 8;
            ret.c16 |= (utf8_char16_t)s.buf[chrindex + 1]; break;
        }
        case UTF8_CHARSIZE_24: {
            ret.c24 |= (utf8_char24_t)s.buf[chrindex] << 16;
            ret.c24 |= (utf8_char24_t)s.buf[chrindex + 1] << 8;
            ret.c24 |= (utf8_char24_t)s.buf[chrindex + 2]; break;
        }
        case UTF8_CHARSIZE_32: {
            ret.c32 |= (utf8_char32_t)s.buf[chrindex] << 24;
            ret.c32 |= (utf8_char32_t)s.buf[chrindex + 1] << 16;
            ret.c32 |= (utf8_char32_t)s.buf[chrindex + 2] << 8;
            ret.c32 |= (utf8_char32_t)s.buf[chrindex + 3]; break;
        }
    }

    return ret;
}

size_t cstr_utf_len(const cstr s)
{
    static size_t ret;
    size_t i;

    for(i = 0; i < s.len && s.buf[i] != '\0'; i++) {
        i += get_charsize((unsigned char)s.buf[i]);
        ret++;
    }

    return ret;
}

size_t cstr_utf_chrindex(const cstr s, const size_t chr)
{
    static size_t count;
    size_t i, j;

    for(i = 0; i < s.len && s.buf[i] != '\0'; i++) {
        j = get_charsize((unsigned char)s.buf[i]);
        i += j;
        count++;
        if(count == chr) {
            i -= j;
            break;
        }
    }

    return i;
}
