#include "tri.h"

void trisimple_n(t_ps *ps, int n)
{
	int i;

	if (n > 1)
	{
		while (!ft_pileissorted_n(ps->pile_a, n))
		{
			i = 1;
			while (i++ < n)
			{
				if (*(int *)ps->pile_a->content > *(int *)ps->pile_a->next->content)
					sa(ps);
				ra(ps);
			}
			n_move(ps, &rra, n - 1);
			if (ft_lstsize(ps->moves) > ps->bm_size + ft_lstsize(ps->pile_init) * 2)
				break ;
		}
	}
}

void trisimple(t_ps *ps)
{
	trisimple_n(ps, ft_lstsize(ps->pile_a));
}
