/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:49:01 by dmercadi          #+#    #+#             */
/*   Updated: 2022/03/08 13:49:02 by dmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

int	ft_lstcountop(t_list *lst, t_op op)
{
	int	count;

	if (!lst)
		return (0);
	count = 0;
	while (lst)
	{
		if (*(t_op *)lst->content != op)
			break ;
		count++;
		lst = lst->next;
	}
	return (count);
}

int	op_is_rot(t_op op)
{
	return ((op == op_ra || op == op_rb
			|| op == op_rra || op == op_rrb));
}

void	ft_malloc_and_add_move(t_list **moves, t_op op, t_ps *ps)
{
	t_op	*p_op;
	t_list	*move;

	p_op = (t_op *)malloc(sizeof(t_op));
	if (!p_op)
	{
		ps_free(ps);
		put_error(ERR_MALLOC);
	}
	*p_op = op;
	move = ft_lstnew(p_op);
	if (!move)
	{
		free(p_op);
		ps_free(ps);
		put_error(ERR_MALLOC);
	}
	ft_lstadd_front(moves, move);
}
