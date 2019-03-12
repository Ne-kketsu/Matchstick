/*
** EPITECH PROJECT, 2019
** Remove given nbr of sticks
** File description:
** remove_sticks
*/

#include "include/matchstick.h"

void rm_sticks(game_board_t *g_board, int line, int nb_matches)
{
    for (int i = g_board->nb_col - 1; i > 0; i -= 1) {
        if (g_board->board[line][i] == '|' && nb_matches > 0) {
            g_board->board[line][i] = ' ';
            nb_matches -= 1;
        }
    }
}