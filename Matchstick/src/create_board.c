/*
** EPITECH PROJECT, 2019
** Place Sticks and create frame
** File description:
** create_board
*/

#include "../include/matchstick.h"

void set_sticks(game_board_t *g_board, int i, int j)
{
    static int k = 0;
    if (i > 0 && i < g_board->nb_col - 1) {
        if (i == g_board->nb_col / 2) {
            g_board->board[j][i] = '|';
            for (int l = 0; l <= k; l += 1) {
                g_board->board[j][i - l] = '|';
                g_board->board[j][i + l] = '|';
            }
            k += 1;
        }
        else if (g_board->board[j][i] != '|')
            g_board->board[j][i] = ' ';
    }
}

void create_board(game_board_t *g_board)
{
    for (int j = 0; j < g_board->nb_lines; j += 1) {
        for (int i = 0; i < g_board->nb_col; i += 1) {
            if (j == 0 || j == g_board->nb_lines - 1)
                g_board->board[j][i] = '*';
            else if (i == 0 || i == g_board->nb_col - 1) {
                g_board->board[j][i] = '*';
            }
            else
                set_sticks(g_board, i, j);
        }
    }
}