#include <stddef.h>

#include "str.h"
#include "utf.h"

size_t cstr_utf_len(const cstr s)
{
    static size_t ret;
    size_t i;

    for(i = 0; i < s.len && s.buf[i] != '\0'; i++) {
        if((s.buf[i] & UTF8_BYTEMASK) > UTF8_CODEPOINT_2B) {
            i += 1;
            if((s.buf[i] & UTF8_SHRTMASK) > UTF8_CODEPOINT_3B) {
                i += 1;
                if((s.buf[i] & UTF8_INTMASK) > UTF8_CODEPOINT_4B)
                    i += 1;
            }
        }
        ret++;
    }

    return ret;
}
