#include "push_swap.h"

void ft_trisimple_n(t_ps *ps, int n)
{
	int i;

	while (!ft_pileissorted_n(ps->pile_a, n))
	{
		i = n;
		while (i-- > 1)
		{
			if (*(int *)ps->pile_a->content > *(int *)ps->pile_a->next->content)
				sa(ps);
			// if (ft_pileisordered(ps->pile_a))
			// 	break ;
			ra(ps);
		}
		// if (ft_pileisordered(ps->pile_a) > n / 2)
		// 	n_move(ps, rra, n - ft_pileisordered(ps->pile_a));
		// else if (ft_pileisordered(ps->pile_a) <=  n / 2)
		// 	n_move(ps, ra, ft_pileisordered(ps->pile_a));
		// if (ft_pileissorted(ps->pile_a))
		// 	break;
		ra(ps);
		if (ft_lstsize(ps->moves) > ps->bm_size + 200)
			break ;
	}
}

void ft_trisimple(t_ps *ps)
{
	ft_trisimple_n(ps, ft_lstsize(ps->pile_a));
}