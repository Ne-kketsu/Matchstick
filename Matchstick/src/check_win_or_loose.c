/*
** EPITECH PROJECT, 2019
** Check win and loose condition
** File description:
** check_win_or_loose
*/

#include "../include/matchstick.h"

void check_last_stick(game_board_t *g_board, int i)
{
    if (g_board->nb_avaible_matches == 1)
        rm_sticks(g_board, i, 1);
}

int check_endgame_ia(game_board_t *g_board)
{
    g_board->end_g = 1;
    g_board->nb_avaible_matches = 0;
    for (int i = 1; i < g_board->nb_lines; i += 1) {
        for (int j = 1; j < g_board->nb_col; j += 1) {
            if (g_board->board[i][j] == '|') {
                g_board->nb_avaible_matches += 1;
                check_last_stick(g_board, i);
                g_board->end_g = 0;
            }
        }
    }
    if (g_board->end_g || g_board->nb_avaible_matches == 1) {
        my_printf("AI's turn...\n");
        my_printf("AI removed %d match(es) from line %d\n", \
        g_board->iarm_m, g_board->ia_line_to_rm);
        print_game_board(g_board);
        my_printf("I lost... snif... but I'll get you next time!!\n");
        return (1);
    }
    return (0);
}

int check_endgame_p(game_board_t *g_board)
{
    g_board->end_g = 1;
    g_board->nb_avaible_matches = 0;
    for (int i = 1; i < g_board->nb_lines; i += 1) {
        for (int j = 1; j < g_board->nb_col; j += 1) {
            if (g_board->board[i][j] == '|') {
                g_board->nb_avaible_matches += 1;
                g_board->end_g = 0;
            }
        }
    }
    if (g_board->end_g) {
        print_game_board(g_board);
        my_printf("You lost, too bad...\n");
        return (2);
    }
    return (0);
}