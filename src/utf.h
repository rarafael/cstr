#ifndef _CSTR_UTF_H
#define _CSTR_UTF_H

#define UTF8_CODEPOINT_8    0x80
#define UTF8_CODEPOINT_16   0xC0
#define UTF8_CODEPOINT_24   0xE0
#define UTF8_CODEPOINT_32   0xF0

#define UTF8_CHARSIZE_8     0
#define UTF8_CHARSIZE_16    1
#define UTF8_CHARSIZE_24    2
#define UTF8_CHARSIZE_32    3

#include <stdint.h>
#include <stddef.h>
#include "str.h"

typedef uint8_t utf8_char8_t;
typedef uint16_t utf8_char16_t;
typedef uint32_t utf8_char24_t;
typedef uint32_t utf8_char32_t;

typedef union utf8_char_t {
    utf8_char8_t c8;
    utf8_char16_t c16;
    utf8_char24_t c24;
    utf8_char32_t c32;
} utf8_char_t;

size_t cstr_utf_len(const cstr s);
size_t cstr_utf_chrindex(const cstr s, const size_t chr);

#endif
