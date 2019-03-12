/*
** EPITECH PROJECT, 2019
** Initialize game board and malloc every stuff
** File description:
** init_gameboard
*/

#include "include/matchstick.h"

void init_gameboard2(game_board_t *g_board)
{
    for (int i = 0; i < g_board->nb_lines; i += 1) {
        g_board->board[i] = (char *) malloc(sizeof(char) * g_board->nb_col + 1);
        g_board->board[i][g_board->nb_col] = 0;
    }
}

int init_gameboard(char **argv, game_board_t *g_board)
{
    if (g_board == NULL)
        return (84);
    srandom(time(NULL));
    g_board->nb_max_matches = my_getnbr(argv[2]);
    g_board->nb_lines = my_getnbr(argv[1]) + 2;
    g_board->nb_col = (g_board->nb_lines - 2) * 2 + 1;
    g_board->board = (char **) malloc(g_board->nb_lines * sizeof(char *) + 1);
    g_board->p_input = NULL;
    g_board->len = 0;
    g_board->check_error = 0;
    g_board->player_play = 1;
    g_board->ia_line_to_rm = 0;
    g_board->iarm_m = 0;
    if (g_board->board == NULL) {
        free(g_board);
        return (84);
    }
    init_gameboard2(g_board);
    return (0);
}