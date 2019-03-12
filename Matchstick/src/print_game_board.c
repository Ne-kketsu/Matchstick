/*
** EPITECH PROJECT, 2019
** Print the game board
** File description:
** print_game_board
*/

#include "include/matchstick.h"

void print_game_board(game_board_t *g_board)
{
    for (int i = 0; i < g_board->nb_lines; i += 1) {
        my_putstr(g_board->board[i]);
        my_putchar('\n');
    }
}