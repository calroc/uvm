#ifndef __STDIO_H__
#define __STDIO_H__

#include <assert.h>

int puts(char* str)
{
    asm (str) -> void { syscall print_str; };
    return 0;
}

// Internal buffer used by printf
char* __buffer[32];

void __write_char(char c)
{
    __buffer[0] = c;
    __buffer[1] = 0;
    asm (__buffer) -> void { syscall print_str; };
}

int printf(char* format, ...)
{
    unsigned int ch_written = 0;
    unsigned int var_arg_idx = 1;

    // For each character of the format string
    for (unsigned int i = 0;; ++i)
    {
        char c = format[i];

        if (c == 0)
        {
            break;
        }

        // Format specifier
        if (c == '%')
        {
            // Percent character
            if (format[i+1] == '%')
            {
                __write_char('%');
                ++i;
                ++ch_written;
                continue;
            }

            // String
            if (format[i+1] == 's')
            {
                ++i;

                // Get the integer argument and print it
                asm (var_arg_idx) -> void {
                    get_var_arg;
                    syscall print_str;
                };
                ++var_arg_idx;

                continue;
            }

            // Decimal integer
            if (format[i+1] == 'd' || format[i+1] == 'i')
            {
                ++i;

                // Get the integer argument and print it
                asm (var_arg_idx) -> void {
                    get_var_arg;
                    syscall print_i64;
                };
                ++var_arg_idx;

                continue;
            }

            // TODO: %x %X for printing hexadecimal integers

            // TODO: %p for printing pointers

            // TODO: %f for printing floats

            // Floats (f32)
            if (format[i+1] == 'f')
            {
                ++i;

                // Get the float argument and print it
                asm (var_arg_idx) -> void {
                    get_var_arg;
                    syscall print_f32;
                };
                ++var_arg_idx;

                continue;
            }

            // Unknown format specifier
            // Just print it in the output for now
            // That makes it easier to debug the problem than a panic.
        }

        // Print this character
        // NOTE: may want to be careful about printing
        // in the middle of a UTF-8 unicode character?
        __write_char(c);
        ++ch_written;
    }

    // Return total number of chars written
    return ch_written;
}

#endif
