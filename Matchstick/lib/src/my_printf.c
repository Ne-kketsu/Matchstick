/*
** EPITECH PROJECT, 2018
** Display stdarg
** File description:
** Display the arguments followed by '\n'
** in the order in which they were passed
*/

#include <stdarg.h>
#include "../include/my_printf.h"
#include <unistd.h>

void print_argument_base(char c, va_list list);

void print_argument_capital_S_flag(va_list list);

void print_argument(char c, va_list list);

int print_argument_dot(char *c, va_list list, int i);

int print_argf(char c, va_list list, int i, int *d)
{
    (*d) = 1;
    if (c == 'o') {
        my_putchar('0');
        my_put_nbr_base(va_arg(list, long), "01234567");
    }
    if (c == 'x') {
        my_putstr("0x");
        my_put_nbr_base(va_arg(list, int), "0123456789abcdef");
    }
    if (c == 'X') {
        my_putstr("0X");
        my_put_nbr_base(va_arg(list, int), "0123456789abcdef");
    }
    if (c == '+')
        my_putchar('+');
    return (i + 2);
}

int my_printf(char *s, ...)
{
    int i;
    int d = 0;
    va_list list;

    va_start(list, s);
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == '%') {
            i += 1;
            (s[i] == '+') ? i = print_argf(s[i], list, i, &d) : i == 1;
            (s[i] == '#') ? i = print_argf(s[i + 1], list, i, &d) :
            s[i] == '.' ? i = print_argument_dot(s, list, i) : i == 1;
            print_argument(s[i], list);
        }
        else my_putchar(s[i]);
    }
    va_end(list);
    return (0);
}
