#include "push_swap.h"

void ft_recpivotright(t_ps *ps, int n, int start)
{
	int	pivot;
	int	i;

	if (n == 1)
		pa(ps);
	else if (n == 2)
	{
		pa(ps);
		pa(ps);
		ft_recpivotleft(ps, 2, 0);
	}
	else if (n > 1)
	{
		pivot = *(int *)ft_lstgetn(ps->ordered, start + n / 2);
		i = 0;
		while (i++ < n)
		{
			if (*(int *)ps->pile_b->content < pivot)
				rb(ps);
			else
				pa(ps);
		}
		n_move(ps, &rrb, n / 2);
		ft_recpivotleft(ps, n / 2 + (n % 2), start + n / 2);
		ft_recpivotright(ps, n / 2, start);
	}
}

void ft_recpivotleft(t_ps *ps, int n, int start)
{
	int	pivot;
	int	i;

	if (n == 2 && *(int *)ps->pile_a->content > *(int *)ps->pile_a->next->content)
		sa(ps); //techniquement pas utile
	else if (n > 2)
	{
		pivot = *(int *)ft_lstgetn(ps->ordered, start + n / 2);
		i = 0;
		while (i++ < n)
		{
			if (*(int *)ps->pile_a->content < pivot)
				pb(ps);
			else
				ra(ps);
		}
		n_move(ps, &rra, n / 2 + (n % 2));
		ft_recpivotleft(ps, n / 2 + (n % 2), start + n / 2);
		ft_recpivotright(ps, n / 2 , start);
	}
}

void ft_tripivot(t_ps *ps)
{
	ft_recpivotleft(ps, ft_lstsize(ps->pile_a), 0);
}