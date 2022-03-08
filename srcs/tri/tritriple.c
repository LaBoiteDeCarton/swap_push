/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tritriple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:54:15 by dmercadi          #+#    #+#             */
/*   Updated: 2022/03/08 13:54:17 by dmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tri.h"

static void	boucle(t_ps *ps, void *p1, void *p2, int n)
{
	int	i;

	i = 0;
	while (i++ < n)
	{
		if (ft_cmporder(ps->pile_a->content, p1))
			pb(ps);
		else if (ft_lstcmp(ps->pile_a, &ft_cmporder, p2))
			rb(pb(ps));
		else
			ra(ps);
	}
}

void	rec_tritripleleft(t_ps *ps, int n, int start)
{
	void	*pivot1;
	void	*pivot2;

	if (n < 4)
		trisimple_n(ps, n);
	else if (n > 3)
	{
		pivot1 = ft_lstgetn(ps->ordered, start + n / 3);
		pivot2 = ft_lstgetn(ps->ordered, start + 2 * n / 3);
		boucle(ps, pivot1, pivot2, n);
		rec_tritripleright(ps, n / 3, start);
		n_move(ps, &rrb, n / 3 + (n % 3 == 2));
		n_move(ps, &rra, n / 3 + (n % 3 > 0));
		rec_tritripleleft(ps, n / 3 + (n % 3 > 0), start + 2 * n / 3);
		rec_tritripleright(ps, n / 3 + (n % 3 == 2), start + n / 3);
		n_move(ps, &pa, 2 * n / 3);
	}
}

void	tritriple(t_ps *ps)
{
	rec_tritripleleft(ps, ft_lstsize(ps->pile_a), 0);
}
