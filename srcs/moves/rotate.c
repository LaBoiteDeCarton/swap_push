/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:48:52 by dmercadi          #+#    #+#             */
/*   Updated: 2022/03/08 13:48:53 by dmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

static void	r_pile(t_list **alst)
{
	t_list	*tmp;

	if (*alst && (*alst)->next)
	{
		tmp = *alst;
		*alst = tmp->next;
		tmp->next = NULL;
		ft_lstadd_back(alst, tmp);
	}
}

t_ps	*ra(t_ps *ps)
{
	t_op	move;

	if (ps->pile_a && ps->pile_a->next)
	{
		move = op_ra;
		r_pile(&(ps->pile_a));
		ft_lstadd_move(ps, move);
	}
	return (ps);
}

t_ps	*rb(t_ps *ps)
{
	t_op	move;

	if (ps->pile_b && ps->pile_b->next)
	{
		move = op_rb;
		r_pile(&(ps->pile_b));
		ft_lstadd_move(ps, move);
	}
	return (ps);
}

t_ps	*rr(t_ps *ps)
{
	t_op	move;

	move = op_rr;
	r_pile(&(ps->pile_a));
	r_pile(&(ps->pile_b));
	ft_lstadd_move(ps, move);
	return (ps);
}
