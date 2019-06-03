/*
** EPITECH PROJECT, 2018
** Usefull function for my_printf
** File description:
** fonction
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
    return;
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

int my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i += 1;
    }
    return (0);
}

void my_put_nbr(long int nb)
{
    long int n = nb;

    if (nb < 0) {
        nb = nb * - 1;
        n = nb;
        my_putchar('-');
    }
    if (n > 9)
    {
        my_put_nbr(n / 10);
        my_put_nbr(n % 10);
    }
    else
        my_putchar(n + '0');
}

long int my_put_nbr_base(long int nb, char *base)
{
    int size = my_strlen(base);

    if (nb >= size)
        my_put_nbr_base(nb / size, base);
    my_putchar(base[nb % size]);
    return (0);
}