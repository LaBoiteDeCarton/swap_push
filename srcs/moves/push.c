/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:48:48 by dmercadi          #+#    #+#             */
/*   Updated: 2022/03/08 13:48:49 by dmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

static void	p_pile(t_list **alstfrom, t_list **alstto)
{
	t_list	*tmp;

	if ((*alstfrom))
	{
		tmp = *alstfrom;
		*alstfrom = tmp->next;
		tmp->next = *alstto;
		*alstto = tmp;
	}
}

t_ps	*pa(t_ps *ps)
{
	t_op	move;

	if (ps->pile_b)
	{
		move = op_pa;
		p_pile(&(ps->pile_b), &(ps->pile_a));
		ft_lstadd_move(ps, move);
	}
	return (ps);
}

t_ps	*pb(t_ps *ps)
{
	t_op	move;

	if (ps->pile_a)
	{
		move = op_pb;
		p_pile(&(ps->pile_a), &(ps->pile_b));
		ft_lstadd_move(ps, move);
	}
	return (ps);
}
