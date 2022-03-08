/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trirapide.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:53:58 by dmercadi          #+#    #+#             */
/*   Updated: 2022/03/08 13:53:59 by dmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tri.h"

static t_ps	*para(t_ps *ps)
{
	pa(ps);
	ra(ps);
	return (ps);
}

static t_ps	*pbrb(t_ps *ps)
{
	pb(ps);
	rb(ps);
	return (ps);
}

void	rectrirapiderightn(t_ps *ps, int n)
{
	int	ls;
	int	rs;

	if (n > 1)
	{
		n_move(ps, &pa, n / 2);
		rectrirapiderightn(ps, n - n / 2);
		rectrirapideleftn(ps, n / 2);
		ls = n / 2;
		rs = n - n / 2;
		while (1)
		{
			if (!ls || !rs)
				break ;
			ls -= *(int *)ps->pile_a->content < *(int *)ps->pile_b->content;
			rs -= *(int *)ps->pile_a->content > *(int *)ps->pile_b->content;
			if (*(int *)ps->pile_a->content < *(int *)ps->pile_b->content)
				pb(ps);
			rb(ps);
		}
		n_move(ps, &pbrb, ls);
		n_move(ps, &rb, rs);
		n_move(ps, &rrb, n);
	}
}

void	rectrirapideleftn(t_ps *ps, int n)
{
	int	ls;
	int	rs;

	if (n > 1)
	{
		n_move(ps, &pb, n / 2);
		rectrirapiderightn(ps, n / 2);
		rectrirapideleftn(ps, n - n / 2);
		ls = n - n / 2;
		rs = n / 2;
		while (1)
		{
			if (!ls || !rs)
				break ;
			ls -= *(int *)ps->pile_a->content < *(int *)ps->pile_b->content;
			rs -= *(int *)ps->pile_a->content > *(int *)ps->pile_b->content;
			if (*(int *)ps->pile_a->content > *(int *)ps->pile_b->content)
				pa(ps);
			ra(ps);
		}
		n_move(ps, &para, rs);
		n_move(ps, &ra, ls);
		n_move(ps, &rra, n);
	}
}

void	trirapide(t_ps *ps)
{
	rectrirapideleftn(ps, ft_lstsize(ps->pile_a));
}
