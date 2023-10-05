#include "main.h"

int *int_copy(int *arr, int len)
{
	int *intc = NULL, i = 0;

	intc = malloc(sizeof(int) * (len + 1));
	intc[len] = -1;
	for (i = 0; i < len; i++)
	{
		intc[i] = arr[i];
	}

	return (intc);
}

int is_num(char *str)
{
	int i;
	char c;

	if (str == NULL)
		return (0);

	for (i = 0; (c = str[i]); i++)
	{
		if (!(c >= '0' && c <= '9'))
			return (0);
	}

	return (1);
}

int make_number(char *str)
{
	int i, num = 0;
	char c;

	if (!(is_num(str)))
		return (-1);

	for (i = 0; (c = str[i]) != '\0'; i++)
	{
		if (i == 0 && c == '-')
		{
			num = -1;
			continue;
		}

		if ((c >= '0' && c <= '9'))
		{
			if (num == -1)
				num *= c - '0';
			else
				num = (num * 10) + (c - '0');
		}
	}

	return (num);
}

int printt_tab(int array[])
{
	int i = 0;

	if (array == NULL)
		return (0);

	for (i = 0; array[i] != -1; i++)
	{
		printf("%d\n", array[i]);
	}

	return (i);
}
