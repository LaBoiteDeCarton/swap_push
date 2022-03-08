/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tridoublepivot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:53:40 by dmercadi          #+#    #+#             */
/*   Updated: 2022/03/08 13:53:41 by dmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tri.h"

void	rec_tridoublepivotleftbot(t_ps *ps, int n, int start)
{
	void	*pivot1;
	void	*pivot2;
	int		i;

	if (n < 4)
		trisimple_n(n_move(ps, &rra, n), n);
	else if (n > 3)
	{
		pivot1 = ft_lstgetn(ps->ordered, start + n / 3);
		pivot2 = ft_lstgetn(ps->ordered, start + 2 * n / 3);
		i = 0;
		while (i++ < n)
		{
			rra(ps);
			if (ft_cmporder(ps->pile_a->content, pivot1))
				rb(pb(ps));
			else if (ft_lstcmp(ps->pile_a, &ft_cmporder, pivot2))
				pb(ps);
		}
		rec_tridoublepivotleft(ps, n / 3 + (n % 3 > 0), start + 2 * n / 3);
		rec_tridoublepivotright(ps, n / 3 + (n % 3 == 2), start + n / 3);
		rec_tridoublepivotrightbot(ps, n / 3, start);
	}
}

static void	dprb_small(t_ps *ps, int n)
{
	if (n == 1)
		pa(rrb(ps));
	if (n == 2)
	{
		rrb(rrb(ps));
		if (*(int *)ps->pile_b->content < *(int *)ps->pile_b->next->content)
			pa(rrb(pa(rb(ps))));
		else
			pa(pa(ps));
	}
	if (n == 3)
	{
		rrb(rrb(rrb(ps)));
		insertleft_n(ps, 3);
	}
}

void	rec_tridoublepivotrightbot(t_ps *ps, int n, int start)
{
	void	*pivot1;
	void	*pivot2;
	int		i;

	if (n < 4)
		dprb_small(ps, n);
	else if (n > 3)
	{
		pivot1 = ft_lstgetn(ps->ordered, start + n / 3);
		pivot2 = ft_lstgetn(ps->ordered, start + 2 * n / 3);
		i = 0;
		while (i++ < n)
		{
			rrb(ps);
			if (!ft_cmporder(ps->pile_b->content, pivot1)
				&& ft_lstcmp(ps->pile_b, &ft_cmporder, pivot2))
				ra(pa(ps));
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
	int		i;

	if (n < 4)
		trisimple_n(ps, n);
	else if (n > 3)
	{
		pivot1 = ft_lstgetn(ps->ordered, start + n / 3);
		pivot2 = ft_lstgetn(ps->ordered, start + 2 * n / 3);
		i = 0;
		while (i++ < n)
		{
			if (ft_cmporder(ps->pile_a->content, pivot1))
				rb(pb(ps));
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

void	tridoublepivot(t_ps *ps)
{
	rec_tridoublepivotleft(ps, ft_lstsize(ps->pile_a), 0);
}
