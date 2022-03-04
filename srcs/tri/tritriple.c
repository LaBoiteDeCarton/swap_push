#include "tri.h"

void	tr_small(t_ps *ps, int n)
{
	if (n == 2 &&
			*(int *)ps->pile_b->content < *(int *)ps->pile_b->next->content)
		sb(ps);
	else if (n == 3)
	{
		if (*(int *)ps->pile_b->content < *(int *)ps->pile_b->next->content)
			sa(ps);
		ra(ps);
		if (*(int *)ps->pile_b->content < *(int *)ps->pile_b->next->content)
			sa(ps);
		rra(ps);
		if (*(int *)ps->pile_b->content < *(int *)ps->pile_b->next->content)
			sa(ps);
	}
}

static void leftthenright(t_ps *ps, int ls, int sl, int rs, int sr)
{
	rec_tritripleleft(ps, ls, sl);
	rec_tritripleright(ps, rs, sr);
}

void	rec_tritripleright(t_ps *ps, int n, int start)
{
	void	*pivot1;
	void	*pivot2;
	int i;

	if (n < 4)
		tr_small(ps, n);
	else if (n > 3)
	{
		pivot1 = ft_lstgetn(ps->ordered, start + n / 3); // 1 / 2 lst[1] lst[2] pivot1 inclus dans moyen pivot2 inclus dans grand
		pivot2 = ft_lstgetn(ps->ordered, start + 2 * n / 3);
		i = 0;
		while (i++ < n)
		{
			if (ft_cmporder(ps->pile_b->content, pivot1))
				rb(ps);
			else if (ft_lstcmp(ps->pile_b, &ft_cmporder, pivot2))
				ra(pa(ps));
			else
				pa(ps);
		}
		rec_tritripleleft(ps, n / 3 + (n % 3 > 0), start + 2 * n / 3);
		n_move(n_move(ps, &rra, n / 3 + (n % 3 == 2)), &rrb, n / 3);
		leftthenright(ps, n / 3 + (n % 3 == 2), start + n / 3, n / 3, start);
		n_move(ps, &pb, 2 * n / 3 + (n % 3 > 0));
	}
}

void	rec_tritripleleft(t_ps *ps, int n, int start)
{
	void	*pivot1;
	void	*pivot2;
	int i;

	if (n < 4)
		trisimple_n(ps, n);
	else if (n > 3)
	{
		pivot1 = ft_lstgetn(ps->ordered, start + n / 3); // 1 / 2 lst[1] lst[2] pivot1 inclus dans moyen pivot2 inclus dans grand
		pivot2 = ft_lstgetn(ps->ordered, start + 2 * n / 3);
		i = 0;
		while (i++ < n)
		{
			if (ft_cmporder(ps->pile_a->content, pivot1))
				pb(ps);
			else if (ft_lstcmp(ps->pile_a, &ft_cmporder, pivot2))
				rb(pb(ps));
			else
				ra(ps);
		}
		rec_tritripleright(ps, n / 3, start);
		n_move(n_move(ps, &rrb, n / 3 + (n % 3 == 2)), &rra, n / 3 + (n % 3 > 0));
		leftthenright(ps, n / 3 + (n % 3 > 0), start + 2 * n / 3, n / 3 + (n % 3 == 2), start + n / 3);
		n_move(ps, &pa, 2 * n / 3);
	}
}

void	tritriple(t_ps *ps)
{
	rec_tritripleleft(ps, ft_lstsize(ps->pile_a), 0);
}