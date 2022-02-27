#include "push_swap.h"

int		ft_pileissorted_n(t_list *pile, int n)
{
	if (!pile)
		return (1);
	while (pile->next && n--)
	{
		if (*(int *)pile->content > *(int *)pile->next->content)
			return (0);
		pile = pile->next;
	}
	return (1);
}

int		ft_pileissorted(t_list *pile)
{
	if (!pile)
		return (1);
	while (pile->next)
	{
		if (*(int *)pile->content > *(int *)pile->next->content)
			return (0);
		pile = pile->next;
	}
	return (1);
}
