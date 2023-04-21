#ifndef _CSTR_UTF_H
#define _CSTR_UTF_H

#define UTF8_CODEPOINT_8    0x80
#define UTF8_CODEPOINT_16   0xC0
#define UTF8_CODEPOINT_32   0xE0
#define UTF8_CODEPOINT_64   0xF0

size_t cstr_utf_len(const cstr s);
size_t cstr_utf_chrindex(const cstr s, const size_t chr);

#endif
