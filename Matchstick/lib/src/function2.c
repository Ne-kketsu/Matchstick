/*
** EPITECH PROJECT, 2018
** Usefull function
** File description:
** 2nd set of usefull function
*/

#include "../include/my_printf.h"

void my_put_nbr_unsigned(unsigned int nb)
{
    unsigned int n = nb;

    if (n > 9)
    {
        my_put_nbr_unsigned(n / 10);
        my_put_nbr_unsigned(n % 10);
    }
    else
        my_putchar(n + '0');
}
