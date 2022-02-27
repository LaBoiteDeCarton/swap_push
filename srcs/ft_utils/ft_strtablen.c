#include "push_swap.h"

int		ft_strtablen(char **s)
{
	int size;

	size = 0;
	while (*s)
	{
		s++;
		size++;
	}
	return (size);
}
