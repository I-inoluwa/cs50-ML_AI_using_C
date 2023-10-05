#ifndef MAIN_H
#define MAIN_H

#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

size_t _strlen(const char *s);
char *_strdup(char *str);

char **array_slice(size_t ind, size_t jnd, char **array);
size_t array_len(char **array);
char **replace_arr(int *coord, char new_char, char **arr);

char **split_str(char *str, char *delim);
int *get_str_len_alt(char *str, int ix, char *delim);
int is_delim(char c, char *delim);
int check_space(char *str, char *delim);


int print_tab(char **array);
int printt_tab(int array[]);
void print_state(state cs);
int print_frontier(frontier_ ft);
void show_path(frontier_ explored, char **arr);
void show_explored(frontier_ explored, char **arr);

void free_arr(char **array);
void free_int_arr(int **array);

char **handle_file(char *filename);
int *handle_input(char **arr);

int *int_copy(int *arr, int len);
int is_num(char *str);
int make_number(char *str);

state move_template(state cur_state);
state up(state cur_state, char **arr);
state down(state cur_state, char **arr);
state left(state cur_state, char **arr);
state right(state cur_state, char **arr);

state get_state(state cur_state, state (*move)(state, char **), char **arr);
state copy_state(state cur_state);
void free_state(state cur_state);

frontier_ copy_frontier_pop(frontier_ frontier);
frontier_ add_state(state new_state, frontier_ frontier);
frontier_ stack_algorithm(char **arr, frontier_ frontier, state *goal_states);

int len_frontier(frontier_ frontier);
void free_frontier(frontier_ frontier);
int empty(frontier_ frontier);

int state_match(state state1, state state2);
int in_explored(state pos_state, frontier_ explored);

frontier_ initialize(char **arr);
state pop(frontier_ *frontier);
state set_goal_state(int *coord, char **arr);
frontier_ push(frontier_ new_ft, frontier_ old_ft);
frontier_ set_goals(char **arr, int N, int M, int K);


#endif