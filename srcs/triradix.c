#include "triradix.h"

void	tri_trois_left(t_ps *ps)
{
	pb(ps);
	rec_triradixleft(ps, 2, 0);
	if (*(int *)ps->pile_a->content < *(int *)ps->pile_b->content)
	{
		ra(ps);
		if (*(int *)ps->pile_a->content < *(int *)ps->pile_b->content)
		{
			ra(ps);
			pa(ps);
			rra(ps);
			rra(ps);
		}
		else
		{
			pa(ps);
			rra(ps);
		}
	}
	else
		pa(ps);
}

void	tri_trois_right(t_ps *ps)
{
	pa(ps);
	rec_triradixright(ps, 2, 0);
	if (*(int *)ps->pile_b->content > *(int *)ps->pile_a->content)
	{
		rb(ps);
		if (*(int *)ps->pile_b->content > *(int *)ps->pile_a->content)
		{
			rb(ps);
			pb(ps);
			rrb(ps);
			rrb(ps);
		}
		else
		{
			pb(ps);
			rrb(ps);
		}
	}
	else
		pb(ps);
}

void	rec_triradixright(t_ps *ps, int n, int start)
{
	void	*pivot1;
	void	*pivot2;
	int i;

	if (n == 2)
	{
		if (*(int *)ps->pile_b->content < *(int *)ps->pile_b->next->content)
			sb(ps);
	}
	else if (n == 3)
		tri_trois_right(ps);
	else if (n > 2)
	{
		pivot1 = ft_lstgetn(ps->ordered, start + n / 3); // 1 / 2 lst[1] lst[2] pivot1 inclus dans moyen pivot2 inclus dans grand
		pivot2 = ft_lstgetn(ps->ordered, start + 2 * n / 3);
		i = 0;
		while (i++ < n)
		{
			if (ft_cmporder(ps->pile_b->content, pivot1))
				rb(ps);	//rajouter comme quoi ra + rb == rr
			else if (ft_lstcmp(ps->pile_b, &ft_cmporder, pivot2))
			{
				pa(ps);
				ra(ps);
			}
			else
				pa(ps);
		}
		rec_triradixleft(ps, n / 3 + (n % 3 > 0), start + 2 * n / 3);
		n_move(ps, &rra, n / 3 + (n % 3 == 2));
		n_move(ps, &rrb, n / 3);
		rec_triradixleft(ps, n / 3 + (n % 3 == 2), start + n / 3);
		rec_triradixright(ps, n / 3, start);
		n_move(ps, &pb, 2 * n / 3 + (n % 3 > 0));
	}
}

void	rec_triradixleft(t_ps *ps, int n, int start)
{
	void	*pivot1;
	void	*pivot2;
	int i;

	if (n == 2) //on peut rajouter des conditions pour des n == 3 et 4 et 5 selon ce aui est le plus optimal
	{
		if (*(int *)ps->pile_a->content > *(int *)ps->pile_a->next->content)
			sa(ps);
	}
	else if (n == 3)
		tri_trois_left(ps);
	else if (n > 2)
	{
		pivot1 = ft_lstgetn(ps->ordered, start + n / 3); // 1 / 2 lst[1] lst[2] pivot1 inclus dans moyen pivot2 inclus dans grand
		pivot2 = ft_lstgetn(ps->ordered, start + 2 * n / 3);
		i = 0;
		while (i++ < n)
		{
			if (ft_cmporder(ps->pile_a->content, pivot1))
				pb(ps);
			else if (ft_lstcmp(ps->pile_a, &ft_cmporder, pivot2))
			{
				pb(ps);
				rb(ps);
			}
			else
				ra(ps);
		}
		rec_triradixright(ps, n / 3, start);
		n_move(ps, &rrb, n / 3 + (n % 3 == 2));
		n_move(ps, &rra, n / 3 + (n % 3 > 0));
		rec_triradixright(ps, n / 3 + (n % 3 == 2), start + n / 3);
		rec_triradixleft(ps, n / 3 + (n % 3 > 0), start + 2 * n / 3);
		n_move(ps, &pa, 2 * n / 3);
	}
}

//on utilise un indice sur la list ordered afin de ne pas retrier les "sous segments" car c'est deja fait de base.

void	triradix(t_ps *ps)
{
	rec_triradixleft(ps, ft_lstsize(ps->pile_a), 0);
}