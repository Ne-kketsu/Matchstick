/*
** EPITECH PROJECT, 2019
** Function defining the ia movement
** File description:
** ia_move
*/

#include "include/matchstick.h"

int random_number(int min_num, int max_num)
{
    int result = 0;
    int low_num = 0;
    int hi_num = 0;

    if (min_num < max_num) {
        low_num = min_num;
        hi_num = max_num + 1;
    }
    else {
        low_num = max_num + 1;
        hi_num = min_num;
    }

    srand(time(NULL));
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}

int compute_ia_move(game_board_t *g_board)
{
    g_board->ia_line_to_rm = random_number(1, g_board->nb_lines - 1);
    g_board->iarm_m = random_number(1, g_board->nb_max_matches);

    if (g_board->iarm_m == 0) {
        return (1);
    }
    if (check_ia_input(g_board, g_board->iarm_m, g_board->ia_line_to_rm) == 84)
        return (1);
    if (g_board->player_play != 1)
        rm_sticks(g_board, g_board->ia_line_to_rm, g_board->iarm_m);
    return (0);
}

int ia_move(game_board_t *g_board)
{
    if (g_board->player_play == 1)
        return (0);
    if (check_endgame_ia(g_board) == 1)
        return (1);
    if (g_board->check_error != 84)
        print_game_board(g_board);
    my_printf("AI's turn...\n");
    while (compute_ia_move(g_board) == 1);
    my_printf("AI removed %d match(es) from line %d\n", \
    g_board->iarm_m, g_board->ia_line_to_rm);
    return (0);
}