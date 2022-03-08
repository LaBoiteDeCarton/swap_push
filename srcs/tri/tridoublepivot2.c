/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tridoublepivot2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:59:51 by dmercadi          #+#    #+#             */
/*   Updated: 2022/03/08 13:59:52 by dmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tri.h"

static void	dpr_small(t_ps *ps, int n)
{
	if (n < 3)
	{
		n_move(ps, &pa, n);
		trisimple_n(ps, n);
	}
	else
		insertleft_n(ps, 3);
}

void	rec_tridoublepivotright(t_ps *ps, int n, int start)
{
	void	*pivot1;
	void	*pivot2;
	int		i;

	if (n < 4)
		dpr_small(ps, n);
	else if (n > 3)
	{
		pivot1 = ft_lstgetn(ps->ordered, start + n / 3);
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
		rec_tridoublepivotleft(ps, n / 3 + (n % 3 > 0), start + 2 * n / 3);
		rec_tridoublepivotleftbot(ps, n / 3 + (n % 3 == 2), start + n / 3);
		rec_tridoublepivotrightbot(ps, n / 3, start);
	}
}
