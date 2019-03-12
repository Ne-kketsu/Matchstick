/*
** EPITECH PROJECT, 2018
** Display function
** File description:
** disp_stdarg
*/

#include <stdarg.h>
#include "../include/my_printf.h"

void print_argument_base(char c, va_list list)
{
    if (c == 'b')
        my_put_nbr_base(va_arg(list, long), "01");
    else if (c == 'p') {
        my_putstr("0x");
        my_put_nbr_base(va_arg(list, long), "0123456789abcdef");
    }
    else if (c == 'o')
        my_put_nbr_base(va_arg(list, long), "01234567");
    else if (c == 'X')
        my_put_nbr_base(va_arg(list, int), "0123456789ABCDEF");
    else if (c == 'x')
        my_put_nbr_base(va_arg(list, int), "0123456789abcdef");
}

void print_argument_capital_S_flag(va_list list)
{
    char *str = va_arg(list, char *);
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 && str[i] > 7) {
            my_putstr("\\");
            my_putchar('0');
            my_put_nbr_base(str[i], "01234567");
        }
        else if (str[i] <= 7) {
            my_putstr("\\");
            my_putstr("00");
            my_put_nbr_base(str[i], "01234567");
        }
        else my_putchar(str[i]);
    }
}

void print_argument(char c, va_list list)
{
    if (c == 'c')
        my_putchar(va_arg(list, int));
    if (c == 's')
        my_putstr(va_arg(list, char *));
    if (c == 'S')
        print_argument_capital_S_flag(list);
    if (c == 'd' || c == 'i')
        my_put_nbr(va_arg(list, int));
    if (c == 'u')
        my_put_nbr_unsigned(va_arg(list, unsigned int));
    if (c == '%')
        my_putchar(c);
    if (c == 'b' || c == 'p' || c == 'o' || c == 'X' || c == 'x')
        print_argument_base(c, list);
    if (c == ' ')
        my_putchar(c);
}

int print_argument_dot(char *c, va_list list, int i)
{
    int j = va_arg(list, int);
    int k = 0;
    int l = 1;
    long res = 0;

    for (i += 1; c[i] >= '0' && c[i] <= '9'; i++) {
        res = 10 * res + (c[i] - 48);
    }
    while (l <= j) {
        l = l * 10;
        k += 1;
    }
    l = 0;
    res = res - k;
    while (l < res) {
        my_putchar('0');
        l += 1;
    }
    my_put_nbr(j);
    return (i + 1);
}
