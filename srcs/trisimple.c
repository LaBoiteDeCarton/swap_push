#include "push_swap.h"

void ft_trisimple_n(t_ps *ps, int n)
{
	int i;

	while (!ft_pileissorted_n(ps->pile_a, n))
	{
		i = 1;
		while (i++ < n)
		{
			if (*(int *)ps->pile_a->content > *(int *)ps->pile_a->next->content)
				sa(ps);
			ra(ps);
		}
		ra(ps);
		if (ft_lstsize(ps->moves) > ps->bm_size + ft_lstsize(ps->pile_init) * 2)
			break ;
	}
}

void ft_trisimple(t_ps *ps)
{
	ft_trisimple_n(ps, ft_lstsize(ps->pile_a));
}
