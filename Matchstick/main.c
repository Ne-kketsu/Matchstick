/*
** EPITECH PROJECT, 2019
** Main function for Matchstick project
** File description:
** main
*/

#include "include/matchstick.h"

int check_arg(int argc, char **argv)
{
    if (argc != 3) {
        write(2, "Invalid number of argument.", 28);
        return (84);
    }
    if (my_getnbr(argv[1]) < 1) {
        write(2, "Error: invalid input (positive number expected)\n", 48);
        return (84);
    }
    if (my_getnbr(argv[2]) < 1) {
        write(2, "Error: invalid input (positive number expected)\n", 48);
        return (84);
    }
    return (0);
}

int main(int argc, char **argv)
{
    game_board_t *g_board = malloc(sizeof(game_board_t));
    int i = 0;

    if (check_arg(argc, argv) == 84)
        return (84);
    if (init_gameboard(argv, g_board) == 84)
        return (84);
    create_board(g_board);
    while (1) {
        if (g_board->check_error != 84)
            print_game_board(g_board);
        if ((i = get_p_move(g_board)) == 0)
            return (0);
        if (i == 2)
            return (2);
        if ((i = ia_move(g_board)) == 1)
            return (1);
    }
    return (0);
}