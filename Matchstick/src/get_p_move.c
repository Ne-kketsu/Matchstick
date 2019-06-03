/*
** EPITECH PROJECT, 2019
** Get info concerning the player move
** File description:
** get_p_move
*/

#include "../include/matchstick.h"

void print_p_move(game_board_t *g_board)
{
    my_printf("Player removed %d ", g_board->nb_rm_matches);
    my_printf("match(es) from line %d\n", g_board->prm_l);
}

int get_p_move(game_board_t *g_board)
{
    int i = 0;
    g_board->player_play = 1;

    if (g_board->check_error != 84)
        my_printf("\nYour Turn:\n");
    if ((i = check_p_inputs(g_board)) == 0)
        return (0);
    if (i == 84)
        return (84);
    rm_sticks(g_board, g_board->prm_l, g_board->nb_rm_matches);
    print_p_move(g_board);
    if (check_endgame_p(g_board) == 2)
        return (2);
    g_board->player_play = 0;
    g_board->check_error = 0;
    return (1);
}