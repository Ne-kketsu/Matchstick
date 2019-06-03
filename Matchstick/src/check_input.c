/*
** EPITECH PROJECT, 2019
** Check player input
** File description:
** check_input
*/

#include "../include/matchstick.h"

int check_line(game_board_t *g_board)
{
    if (getline(&g_board->p_input, &g_board->len, stdin) < 0)
        return (0);
    if ((g_board->prm_l = my_getnbr(g_board->p_input)) == 0) {
        my_printf("Error: invalid input (positive number expected)\n");
        g_board->check_error = 84;
        return (84);
    }
    if (g_board->prm_l > g_board->nb_lines - 1 || g_board->prm_l < 1) {
        my_printf("Error: this line is out of range\n");
        g_board->check_error = 84;
        return (84);
    }
    return (1);
}

int check_matches(game_board_t *g_board)
{
    int matches = 0;

    if (getline(&g_board->p_input, &g_board->len, stdin) < 0)
        return (0);
    if ((g_board->nb_rm_matches = my_getnbr(g_board->p_input)) == 0) {
        my_printf("Error: invalid input (positive number expected)\n");
        g_board->check_error = 84;
        return (84);
    }
    if (check_min_matches(g_board) == 84)
        return (84);
    if (check_max_matches(g_board) == 84)
        return (84);
    matches = compute_avaible_matches(g_board);
    if (matches < g_board->nb_rm_matches) {
        my_printf("Error: not enough matches on this line\n");
        g_board->check_error = 84;
        return (84);
    }
    return (1);
}

int check_p_inputs(game_board_t *g_board)
{
    int i = 0;

    my_printf("Line: ");
    if ((i = check_line(g_board)) == 0)
        return (0);
    if (i == 84)
        return (84);
    my_printf("Matches : ");
    if ((i = check_matches(g_board)) == 0)
        return (0);
    if (i == 84)
        return (84);
    return (1);
}

int check_ia_input(game_board_t *g_board, int nb_matches, int line)
{
    int matches = 0;

    if (line > g_board->nb_lines - 1 || line < 1) {
        return (84);
    }
    for (int i = g_board->nb_col - 1; i > 0; i -= 1) {
        if (g_board->board[line][i] == '|') {
            matches += 1;
        }
    }
    if (matches < nb_matches) {
        return (84);
    }
    return (0);
}