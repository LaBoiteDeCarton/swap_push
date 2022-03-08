/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tritriple2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:33:36 by dmercadi          #+#    #+#             */
/*   Updated: 2022/03/08 16:33:37 by dmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tri.h"

static void	tr_small(t_ps *ps, int n)
{
	if (n == 2
		&& *(int *)ps->pile_b->content < *(int *)ps->pile_b->next->content)
		sb(ps);
	else if (n == 3)
	{
		if (*(int *)ps->pile_b->content < *(int *)ps->pile_b->next->content)
			sb(ps);
		rb(ps);
		if (*(int *)ps->pile_b->content < *(int *)ps->pile_b->next->content)
			sb(ps);
		rrb(ps);
		if (*(int *)ps->pile_b->content < *(int *)ps->pile_b->next->content)
			sb(ps);
	}
}

static void	boucle(t_ps *ps, void *p1, void *p2, int n)
{
	int	i;

	i = 0;
	while (i++ < n)
	{
		if (ft_cmporder(ps->pile_b->content, p1))
			rb(ps);
		else if (ft_lstcmp(ps->pile_b, &ft_cmporder, p2))
			ra(pa(ps));
		else
			pa(ps);
	}
}

void	rec_tritripleright(t_ps *ps, int n, int start)
{
	void	*pivot1;
	void	*pivot2;

	if (n < 4)
		tr_small(ps, n);
	else if (n > 3)
	{
		pivot1 = ft_lstgetn(ps->ordered, start + n / 3);
		pivot2 = ft_lstgetn(ps->ordered, start + 2 * n / 3);
		boucle(ps, pivot1, pivot2, n);
		rec_tritripleleft(ps, n / 3 + (n % 3 > 0), start + 2 * n / 3);
		n_move(n_move(ps, &rra, n / 3 + (n % 3 == 2)), &rrb, n / 3);
		rec_tritripleleft(ps, n / 3 + (n % 3 == 2), start + n / 3);
		rec_tritripleright(ps, n / 3, start);
		n_move(ps, &pb, 2 * n / 3 + (n % 3 > 0));
	}
}
