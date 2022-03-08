/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tripivot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:53:52 by dmercadi          #+#    #+#             */
/*   Updated: 2022/03/08 13:53:53 by dmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tri.h"

void	recpivotright(t_ps *ps, int n, int start)
{
	int	pivot;
	int	i;

	if (n < 4)
	{
		n_move(ps, &pa, n);
		trisimple_n(ps, n);
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

void	recpivotleft(t_ps *ps, int n, int start)
{
	int	pivot;
	int	i;

	if (n < 4)
		trisimple_n(ps, n);
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
		recpivotright(ps, n / 2, start);
	}
}

void	tripivot(t_ps *ps)
{
	recpivotleft(ps, ft_lstsize(ps->pile_a), 0);
}
