#include "main.h"

int print_tab(char **array)
{
	int i = 0, j = 0;

	if (array == NULL)
		return (0);

	for (i = 0; array[i] != NULL; i++)
	{
		printf("\n\n");
		for (j = 0; array[i][j]; j++)
			printf("%c  ", array[i][j]);
		printf("\n\n");
	}

	return (i);
}

void print_to_file(char **array, FILE *file)
{
	int i = 0, j = 0;

	if (array == NULL || file == NULL)
		return;

	for (i = 0; array[i] != NULL; i++)
	{
		fprintf(file, "\n");
		for (j = 0; array[i][j]; j++)
			fprintf(file, "%c   ", array[i][j]);

		fprintf(file, "\n");
	}

	printf("SUCCESSFULLY PRINTED\n");
}

void show_explored(frontier_ explored, char **arr)
{
	int i = 0, len = 0, x = 0, y = 0, a = 0, b = 0, j = 0;
	char **path_arr = NULL, swp = '.';
	state cur = NULL, next = NULL;
	FILE *file = fopen("explored.txt", "w");

	if (explored == NULL || arr == NULL)
		return;

	path_arr = array_slice(0, array_len(arr) - 1, arr);
	if (path_arr == NULL)
		return;

	len = len_frontier(explored);
	for (i = 0; i < len - 1; i++)
	{
		cur = explored[i];	
		next = explored[i + 1];
		x = next->coord[0], y = next->coord[1];
		a = cur->coord[0], b = cur->coord[1];	

		if (y - b == 1 && a == x)
			swp = '>';
		else if (b - y == 1 && a == x)
			swp = '<';
		else if (a - x == 1 && b == y)
			swp = '^';
		else if (x - a == 1 && b == y)
			swp = '!';
		else
		{
			swp = 'a' + j;
			j++;
		}
		if (i == 0)
			swp = 'A';
		path_arr = replace_arr(cur->coord, swp, path_arr);
	}
	path_arr = replace_arr((explored[i])->coord, 'B', path_arr);
	print_to_file(path_arr, file);
	free_arr(path_arr);
	fclose(file);
}

void track_path(frontier_ explored, char **arr)
{
	int x = 0, y = 0, a = 0, b = 0;
	state cur = NULL;
	char **path_arr = NULL, swp = '.';
	FILE *file = fopen("search_path.txt", "w");

	if (explored == NULL || arr == NULL)
		return;

	path_arr = array_slice(0, array_len(arr) - 1, arr);
	if (path_arr == NULL)
		return;

	cur = explored[len_frontier(explored) - 1];
	path_arr = replace_arr(cur->coord, 'B', path_arr);
	cur = cur->parent;

	while (cur != NULL)
	{
		if (cur->parent == NULL)
		{
			path_arr = replace_arr(cur->coord, 'A', path_arr);
			break;
		}
		x = cur->coord[0], y = cur->coord[1];
		a = cur->parent->coord[0], b = cur->parent->coord[1];	

		if (y > b)
			swp = '>';
		else if (b > y)
			swp = '<';
		else if (x < a)
			swp = '^';
		else if (x > a)
			swp = '!';
		else
			swp = '%';
		
		path_arr = replace_arr(cur->coord, swp, path_arr);
		cur = cur->parent;
	}
	print_to_file(path_arr, file);
	free_arr(path_arr);
	fclose(file);
}
