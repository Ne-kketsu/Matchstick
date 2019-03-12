/*
** EPITECH PROJECT, 2019
** Check player inputs
** File description:
** check_input2
*/

#include "include/matchstick.h"

int compute_avaible_matches(game_board_t *g_board)
{
    int matches = 0;

    for (int i = g_board->nb_col - 1; i > 0; i -= 1) {
        if (g_board->board[g_board->prm_l][i] == '|') {
            matches += 1;
        }
    }
    return (matches);
}

int check_min_matches(game_board_t *g_board)
{
    if (g_board->nb_rm_matches < 1) {
        my_printf("Error: you have to remove at least one match\n");
        g_board->check_error = 84;
        return (84);
    }
    return (0);
}

int check_max_matches(game_board_t *g_board)
{
    if (g_board->nb_rm_matches > g_board->nb_max_matches) {
        my_printf("Error: you cannot remove more than %d matches per turn\n", \
        g_board->nb_max_matches);
        g_board->check_error = 84;
        return (84);
    }
    return (0);
}