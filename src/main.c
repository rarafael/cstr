#include <stdio.h>

#include <cstr.h>

int main(void)
{
    cstr a, b;
    a = cstr_new("hello");
    b = cstr_new("world");
    puts(cstr_buf(a));
    puts(cstr_buf(b));
    cstr_free(a);
    cstr_free(b);
    return 0;
}
