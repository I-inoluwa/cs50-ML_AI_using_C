#include "main.h"

int *handle_input(char **arr)
{
	char **line_arr = NULL;
	int N = 1, M = 1, K = 1, i = 0, *retval = NULL;

	line_arr = split_str(arr[0], " ");

	for (i = 0; line_arr[i]; i++)
	{
		if (is_num(line_arr[i]))
		{
			if (i == 0)
				N = make_number(line_arr[i]);
			if (i == 1)
				M = make_number(line_arr[i]);
			if (i == 2)
				K = make_number(line_arr[2]);
		}
		else
		{
			printf("Wrong Input\n");
			free_arr(line_arr);
			return (NULL);
		}
	}
	if (!(N >= 1 && N <= 1000) || !(M >= 1 && M <= 1000) || !(K >= 1 && K <= 500))
	{
		free_arr(line_arr);
		return (NULL);
	}
	free_arr(line_arr);

	retval = malloc(sizeof(int) * 4);
	if (retval == NULL)
		return (NULL);
	retval[0] = N, retval[1] = M, retval[2] = K;
	retval[3] = -1;

	return (retval);
}
