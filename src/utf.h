#ifndef _CSTR_UTF_H
#define _CSTR_UTF_H

#define UTF8_CODEPOINT_2B 0x80
#define UTF8_CODEPOINT_3B 0x800
#define UTF8_CODEPOINT_4B 0x10000

#define UTF8_BYTEMASK   0xFF
#define UTF8_SHRTMASK   0xFFFF
#define UTF8_INTMASK    0xFFFFFF
#define UTF8_LONGMASK   0xFFFFFFFF

size_t cstr_utf_len(const cstr s);

#endif
