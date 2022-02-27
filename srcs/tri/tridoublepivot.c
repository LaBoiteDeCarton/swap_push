#include "tri.h"

void	rec_tridoublepivotright(t_ps *ps, int n, int start)
{
	void	*pivot1;
	void	*pivot2;
	int i;

	if (n == 1)
		pa(ps);
	else if (n == 2)
	{
		if (*(int *)ps->pile_b->content < *(int *)ps->pile_b->next->content)
			sb(ps);
		pa(ps);
		pa(ps);
	}
	// else if (n == 3)
	// {
	// 	tri_trois_right(ps);
	// 	pa(ps);
	// 	pa(ps);
	// 	pa(ps);
	// }
	else if (n > 2)
	{
		pivot1 = ft_lstgetn(ps->ordered, start + n / 3);
		pivot2 = ft_lstgetn(ps->ordered, start + 2 * n / 3);
		i = 0;
		while (i++ < n)
		{
			if (ft_cmporder(ps->pile_b->content, pivot1))
				rb(ps);
			else if (ft_lstcmp(ps->pile_b, &ft_cmporder, pivot2))
			{
				pa(ps);
				ra(ps);
			}
			else
				pa(ps);
		}
		rec_tridoublepivotleft(ps, n / 3 + (n % 3 > 0), start + 2 * n / 3);
		rec_tridoublepivotleftbot(ps, n / 3 + (n % 3 == 2), start + n / 3);
		rec_tridoublepivotrightbot(ps, n / 3, start);
	}
}

void	rec_tridoublepivotleftbot(t_ps *ps, int n, int start)
{
	void	*pivot1;
	void	*pivot2;
	int i;

	if (n == 1)
		rra(ps);
	else if (n == 2) //on peut rajouter des conditions pour des n == 3 et 4 et 5 selon ce aui est le plus optimal
	{
		rra(ps);
		rra(ps);
		if (*(int *)ps->pile_a->content > *(int *)ps->pile_a->next->content)
			sa(ps);
	}
	// else if (n == 3)
	// 	tri_trois_left(ps);
	else if (n > 2)
	{
		pivot1 = ft_lstgetn(ps->ordered, start + n / 3); // 1 / 2 lst[1] lst[2] pivot1 inclus dans moyen pivot2 inclus dans grand
		pivot2 = ft_lstgetn(ps->ordered, start + 2 * n / 3);
		i = 0;
		while (i++ < n)
		{
			rra(ps);
			if (ft_cmporder(ps->pile_a->content, pivot1))
			{
				pb(ps);
				rb(ps);
			}
			else if (ft_lstcmp(ps->pile_a, &ft_cmporder, pivot2))
				pb(ps);
		}
		rec_tridoublepivotleft(ps, n / 3 + (n % 3 > 0), start + 2 * n / 3);
		rec_tridoublepivotright(ps, n / 3 + (n % 3 == 2), start + n / 3);
		rec_tridoublepivotrightbot(ps, n / 3, start);
	}
}

void	rec_tridoublepivotrightbot(t_ps *ps, int n, int start)
{
	void	*pivot1;
	void	*pivot2;
	int i;

	if (n == 1)
	{
		rrb(ps);
		pa(ps);
	}
	else if (n == 2)
	{
		rrb(ps);
		rrb(ps);
		if (*(int *)ps->pile_b->content < *(int *)ps->pile_b->next->content)
		{
			rb(ps);
			pa(ps);
			rrb(ps);
			pa(ps);
		}
		else
			n_move(ps, &pa, 2);
	}
	// else if (n == 3)
	// {
	// 	n_move(ps, &rrb, 3);
	// 	tri_trois_right(ps);
	// 	pa(ps);
	// 	pa(ps);
	// 	pa(ps);
	// }
	else if (n > 2)
	{
		pivot1 = ft_lstgetn(ps->ordered, start + n / 3); // 1 / 2 lst[1] lst[2] pivot1 inclus dans moyen pivot2 inclus dans grand
		pivot2 = ft_lstgetn(ps->ordered, start + 2 * n / 3);
		i = 0;
		while (i++ < n)
		{
			rrb(ps);
			if (!ft_cmporder(ps->pile_b->content, pivot1) && ft_lstcmp(ps->pile_b, &ft_cmporder, pivot2))
			{
				pa(ps);
				ra(ps);
			}
			else if (!ft_lstcmp(ps->pile_b, &ft_cmporder, pivot2))
				pa(ps);
		}
		rec_tridoublepivotleft(ps, n / 3 + (n % 3 > 0), start + 2 * n / 3);
		rec_tridoublepivotleftbot(ps, n / 3 + (n % 3 == 2), start + n / 3);
		rec_tridoublepivotright(ps, n / 3, start);
	}
}

void	rec_tridoublepivotleft(t_ps *ps, int n, int start)
{
	void	*pivot1;
	void	*pivot2;
	int i;

	if (n == 2)
	{
		if (*(int *)ps->pile_a->content > *(int *)ps->pile_a->next->content)
			sa(ps);
	}
	// else if (n == 3)
	// 	tri_trois_left(ps);
	else if (n > 2)
	{
		pivot1 = ft_lstgetn(ps->ordered, start + n / 3); 
		pivot2 = ft_lstgetn(ps->ordered, start + 2 * n / 3);
		i = 0;
		while (i++ < n)
		{
			if (ft_cmporder(ps->pile_a->content, pivot1))
			{
				pb(ps);
				rb(ps);
			}
			else if (ft_lstcmp(ps->pile_a, &ft_cmporder, pivot2))
				pb(ps);
			else
				ra(ps);
		}
		rec_tridoublepivotleftbot(ps, n / 3 + (n % 3 > 0), start + 2 * n / 3);
		rec_tridoublepivotright(ps, n / 3 + (n % 3 == 2), start + n / 3);
		rec_tridoublepivotrightbot(ps, n / 3, start);
	}
}

//on utilise un indice sur la list ordered afin de ne pas retrier les "sous segments" car c'est deja fait de base.

void	tridoublepivot(t_ps *ps)
{
	rec_tridoublepivotleft(ps, ft_lstsize(ps->pile_a), 0);
}