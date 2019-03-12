/*
** EPITECH PROJECT, 2018
** Header file for My Printf
** File description:
** Contain usefull prototypes
*/

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_
void my_put_nbr_unsigned(unsigned int nb);
void my_put_nbr(long int nb);
int my_putstr(char *str);
int my_strlen(char const *str);
void my_putchar(char c);
int my_printf(char *s, ...);
long int my_put_nbr_base(long int nb, char *base);
#endif /* !MY_PRINTF_H_ */
