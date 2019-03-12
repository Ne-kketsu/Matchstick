/*
** EPITECH PROJECT, 2019
** Header file for Matchstick project
** File description:
** matchstick
*/

#ifndef MATCHSTICK_H_
	#define MATCHSTICK_H_
//INCLUDES    
#define _GNU_SOURCE
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "src/lib/include/my_printf.h"

typedef struct game_board_s {
    int iarm_m;
    int nb_max_matches;
    int nb_avaible_matches;
    int nb_rm_matches;
    int ia_line_to_rm;
    int prm_l;
    int nb_lines;
    int nb_col;
    int end_g;
    int check_error;
    int player_play;
    char **board;
    char *p_input;
    size_t len;
}game_board_t;

//PROTOTYPES
int my_getnbr(char const *str);
void print_game_board(game_board_t *g_board);
void create_board(game_board_t *g_board);
void set_sticks(game_board_t *g_board, int i, int j);
int init_gameboard(char **argv, game_board_t *g_board);
void rm_sticks(game_board_t *g_board, int line, int nb_matches);
int get_p_move(game_board_t *g_board);
int check_endgame_p(game_board_t *g_board);
int check_endgame_ia(game_board_t *g_board);
int check_ia_input(game_board_t *g_board, int nb_matches, int line);
int check_p_inputs(game_board_t *g_board);
int check_matches(game_board_t *g_board);
int check_max_matches(game_board_t *g_board);
int check_min_matches(game_board_t *g_board);
int compute_avaible_matches(game_board_t *g_board);
int check_line(game_board_t *g_board);
int ia_move(game_board_t *g_board);
#endif /* !MATCHSTICK_H_ */
