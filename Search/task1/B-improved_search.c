#include "main.h"

int moves_made(state cur_state)
{
	state temp = NULL;
	int i = 0;

	if (cur_state == NULL)
		return (0);

	temp = cur_state;
	for (i = 0; temp->parent != NULL; i++)
	{
		temp = temp->parent;
	}

	return (i);
}

int heuristic(state pos, state goal)
{
	int result = 0, x, y, a, b;

	if (pos == NULL)
		return (0);

	x = pos->coord[0], y = pos->coord[1];
	a = goal->coord[0], b = goal->coord[1];

	result = abs(a - x) + abs(b - y);
	return (result);
}

state min_state(frontier_ frontier, state goal, state min)
{
	int i = 0, cur_val = 0, min_val = -1, flag = 0;
	state cur = NULL;

	if (frontier == NULL)
		return (NULL);

	if (min == NULL || !(in_explored(min, frontier)))
		min = frontier[0];

	min_val = heuristic(min, goal) + moves_made(min);
	for (i = 0; frontier[i] != NULL; i++)
	{
		cur = frontier[i];
		cur_val = heuristic(cur, goal) + moves_made(cur);
		if (cur_val <= min_val)
		{
			min_val = cur_val;
			min = cur;
			flag++;
		}
	}

	printf("\nFlag is: %d\n", flag);
	return (min);
}

frontier_ improved_search(char **arr, frontier_ initial, state *goal_states)
{
	state cur_state = NULL, goal = NULL, pos_state = NULL, keep_state = NULL;
	frontier_ explored = NULL, new_frontier = NULL, frontier = NULL;
	int ind = 0, i = 0, j = 0, end = 0;
	int len = len_frontier(goal_states);

	state (*move[4])(state, char **) = {
	    right,
	    up,
	    left,
	    down
	    };

	if (arr == NULL || initial == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
	{
		goal = goal_states[i];
		frontier = copy_frontier(initial);
		while (1)
		{
			cur_state = copy_state(min_state(frontier, goal, keep_state));
			free_state(keep_state);
			keep_state = copy_state(cur_state);
			new_frontier = remove_state(frontier, cur_state);
			free_frontier(frontier);
			frontier = new_frontier;

			if (!(in_explored(cur_state, explored)))
				explored = add_state(cur_state, explored);
			if (state_match(cur_state, goal))
			{
				printf("GOAL REACHED!\n\n");
				printf("\nGoal at {%d, %d}.\n", (goal->coord)[0], (goal->coord)[1]);
				free_state(cur_state);
				end = 1;
				break;
			}

			for (ind = 0; ind < 4; ind++)
			{
				pos_state = move[ind](cur_state, arr);
				if (pos_state != NULL)
				{
					if ((pos_state->c == '.') && (!(in_explored(pos_state, explored))))
						frontier = add_state(pos_state, frontier);
				}
				free_state(pos_state);
			}

			free_state(cur_state);
			if (empty(frontier))
			{
				printf("SOLUTION COULD NOT BE FOUND\n");
				break;
			}
		}
		free_state(keep_state);
		free_frontier(frontier);
	}
	if (end == 1)
		return (explored);

	free_frontier(explored);

	return (NULL);
}
