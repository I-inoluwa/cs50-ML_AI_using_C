#include "main.h"

/**
 * TO UPDATE THE CODE TO BE DYNAMIC. I.E.,
 * START POINT AND GOALS CAN BE SET DYNAMICALLY, BASED ON CRITERIAS, SUCH AS -
 * COORDINATES 0R CHARACTER AT THOSE POINTS. IN FUTURE, ADD COLOR OF BLOCK.
 * ALSO, TO IMPROVE THE SEARCH ALGORITHM.
 * MAKE SOME MODIFICATIONS TO PARENT ATTRIBUTE TOO.
 * HELPS WITH TRACKING PATH, AND MAYBE IMPROVING ALGORITHM.
*/

int main(void)
{
	char **arr = NULL, **temparr = NULL;
	int N = 0, M = 0, K = 0, *retval = NULL;
	frontier_ goals = NULL, initial = NULL, final = NULL;

	arr = handle_file("input.txt");
	// print_tab(arr);
	retval = handle_input(arr);
	N = retval[0], M = retval[1], K = retval[2];
	free(retval);
	printf("N: %d\nM: %d\nK: %d\n\n", N, M, K);

	temparr = array_slice(1, array_len(arr) - 1, arr);
	free_arr(arr);

	goals = set_goals(temparr, N, M, K);

	arr = array_slice(0, array_len(temparr) - (K + 1), temparr);
	free_arr(temparr);


	initial = initialize(arr);
	final = stack_algorithm(arr, initial, goals);

	print_frontier(final);
	show_path(final, arr);
	show_explored(final, arr);
	free_frontier(goals), free_frontier(final);
	free_arr(arr);

	return (0);
}

char **replace_arr(int *coord, char new_char, char **arr)
{
	int x = 0, y = 0;

	if (arr == NULL)
		return (NULL);
	
	x = coord[0], y = coord[1];
	if (x >= array_len(arr) || y >= _strlen(arr[x]))
	{
		return (arr);
	}

	arr[x][y] = new_char;

	return (arr);
}

frontier_ set_goals(char **arr, int N, int M, int K)
{
	int jnd = N, *coord = NULL;
	char **sc = NULL;
	frontier_ goals = NULL;
	state goal = NULL;

	if (arr == NULL || K == 0)
		return (NULL);

	coord = malloc(sizeof(int) * 3);
	coord[2] = -1;

	for (jnd = N; jnd < N + K; jnd++)
	{
		sc = split_str(arr[jnd], " ");
		if (is_num(sc[0]) && is_num(sc[1]))
		{
			coord[0] = make_number(sc[0]) - 1;
			coord[1] = make_number(sc[1]) - 1;
			goal = set_goal_state(coord, arr);
			goals = add_state(goal, goals);
			free_state(goal);
		}
		else
		{
			printf("Wrong input\n");
		}

		free_arr(sc);
		// break;
	}

	free(coord);

	return (goals);
}
