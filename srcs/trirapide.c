#include "push_swap.h"

void ft_rectrirapiderightn(t_ps *ps, int n)
{
	int i;
	int ls;
	int rs;

	if (n > 1)
	{
		n_move(ps, pa, n / 2);
		ft_rectrirapideleftn(ps, n / 2);
		ft_rectrirapiderightn(ps, n - n / 2);
		i = 0;
		ls = n / 2;
		rs = n - n / 2;
		while (i < n)
		{
			if (!ls)
				rs--;
			else if (!rs)
			{
				ls--;
				pb(ps);
			}
			else if (*(int *)ps->pile_a->content < *(int *)ps->pile_b->content)
			{
				ls--;
				pb(ps);
			}
			else
				rs--;
			rb(ps);
			i++;
		}
		n_move(ps, rrb, n);
	}
}

void ft_rectrirapideleftn(t_ps *ps, int n)
{
	int i;
	int ls;
	int rs;

	if (n > 1)
	{
		n_move(ps, pb, n / 2);
		ft_rectrirapiderightn(ps, n / 2);
		ft_rectrirapideleftn(ps, n - n / 2);
		i = 0;
		ls = n - n / 2;
		rs = n / 2;
		while (i < n)
		{
			if (!ls)
			{
				rs--;
				pa(ps);
			}
			else if (!rs)
				ls--;
			else if (*(int *)ps->pile_a->content < *(int *)ps->pile_b->content)
				ls--;
			else
			{
				rs--;
				pa(ps);
			}
			ra(ps);
			i++;
		}
		n_move(ps, rra, n);
	}
}

void ft_trirapide(t_ps *ps)
{
	ft_rectrirapideleftn(ps, ft_lstsize(ps->pile_a));
}