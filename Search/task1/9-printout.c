#include "main.h"

int print_tab(char **array)
{
	int i = 0, j = 0;
	FILE *file = fopen("printout.txt", "w");

	if (array == NULL || file == NULL)
		return (0);

	for (i = 0; array[i] != NULL; i++)
	{
		printf("\n\n");
		fprintf(file, "\n");
		for (j = 0; array[i][j]; j++)
		{
			fprintf(file, "%c   ", array[i][j]);
			printf("%c  ", array[i][j]);
		}
		fprintf(file, "\n");
		printf("\n\n");
	}

	fclose(file);
	return (i);
}

void print_state(state cs)
{
	if (cs == NULL)
		return;

	printf("\n\tchar: \"%c\"\t-\t{%d, %d}\n", cs->c, (cs->coord)[0], (cs->coord)[1]);
}

int print_frontier(frontier_ ft)
{
	int i = 0;

	if (ft == NULL)
		return (0);

	for (i = 0; ft[i] != NULL; i++)
	{
		printf("\n....................................................\n");
		print_state(ft[i]);
	}
	printf("\n====================================================\n");

	return (i);
}

void show_explored(frontier_ explored, char **arr)
{
	int i = 0, len = 0;
	char **path_arr = NULL;
	int *cd = NULL;

	if (explored == NULL || arr == NULL)
		return;

	path_arr = array_slice(0, array_len(arr) - 1, arr);
	if (path_arr == NULL)
		return;

	len = len_frontier(explored);
	for (i = 0; i < len; i++)
	{
		cd = explored[i]->coord;
		if (i == len - 1)
			path_arr = replace_arr(cd, '$', path_arr);
		else if (i > 25)
			path_arr = replace_arr(cd, 'A' + (i - 26), path_arr);
		else
			path_arr = replace_arr(cd, 'a' + i, path_arr);
	}

	print_tab(path_arr);
	free_arr(path_arr);
}

void show_path(frontier_ explored, char **arr)
{
	int i = 0, len = 0;
	char **path_arr = NULL;
	int *cd1 = NULL, *cd2 = NULL, *pivot = NULL;

	if (explored == NULL || arr == NULL)
		return;

	path_arr = array_slice(0, array_len(arr) - 1, arr);
	if (path_arr == NULL)
		return;

	len = len_frontier(explored);
	pivot = explored[0]->coord;
	// print_state(explored[len - 4]->parent);
	for (i = 0; i < len - 1; i++)
	{
		cd1 = explored[i]->coord;
		cd2 = explored[i + 1]->coord;
		if ((abs(cd2[0] - cd1[0]) == 1 && abs(cd2[1] - cd1[1]) == 0) || (abs(cd2[1] - cd1[1]) == 1 && abs(cd2[0] - cd1[0]) == 0))
		{
			if (i > 25)
				path_arr = replace_arr(cd1, 'A' + (i - 26), path_arr);
			else
				path_arr = replace_arr(cd1, 'a' + i, path_arr);
		}
		else
		{
			/*TO COMPLETE THIS*/
		}
	}
	cd1 = explored[i]->coord;
	path_arr = replace_arr(cd1, '$', path_arr);

	// print_tab(path_arr);
	free_arr(path_arr);
}