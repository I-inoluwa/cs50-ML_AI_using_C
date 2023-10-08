#include "main.h"

int state_match(state state1, state state2)
{
	if (state1 == NULL || state2 == NULL)
		return (0);

	if (((state1->coord)[0] == (state2->coord)[0]) && ((state1->coord)[1] == (state2->coord)[1]))
		return (1);

	return (0);
}

int in_explored(state pos_state, frontier_ explored)
{
	int i = 0;

	if (explored == NULL || pos_state == NULL)
		return (0);
	
	for (i = 0; explored[i] != NULL; i++)
	{
		if (state_match(pos_state, explored[i]))
			return (1);
	}

	return (0);
}

