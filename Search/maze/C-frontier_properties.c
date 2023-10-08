#include "main.h"

int len_frontier(frontier_ frontier)
{
	int ind = 0;

	if (frontier == NULL)
		return (0);

	for (ind  = 0; frontier[ind] != NULL; ind++)
	;

	return (ind);
}


int empty(frontier_ frontier)
{
	int i = 0, len = len_frontier(frontier);

	if (frontier == NULL || frontier[0] == NULL)
		return (1);

	return (0);
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
