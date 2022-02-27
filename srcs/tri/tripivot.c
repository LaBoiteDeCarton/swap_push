#include "tri.h"

void recpivotright(t_ps *ps, int n, int start)
{
	int	pivot;
	int	i;

	if (n == 1)
		pa(ps);
	else if (n == 2)
	{
		pa(ps);
		pa(ps);
		recpivotleft(ps, 2, 0);
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
		recpivotleft(ps, n / 2 + (n % 2), start + n / 2);
		recpivotright(ps, n / 2, start);
	}
}

void recpivotleft(t_ps *ps, int n, int start)
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
		recpivotleft(ps, n / 2 + (n % 2), start + n / 2);
		recpivotright(ps, n / 2 , start);
	}
}

void tripivot(t_ps *ps)
{
	recpivotleft(ps, ft_lstsize(ps->pile_a), 0);
}