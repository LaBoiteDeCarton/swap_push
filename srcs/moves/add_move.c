/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:48:30 by dmercadi          #+#    #+#             */
/*   Updated: 2022/03/08 13:48:31 by dmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

static void	ft_lstadd4_move(t_ps *ps)
{
	if (ft_lstsize(ps->moves) > 3)
	{
		if (*(t_op *)ps->moves->content == op_ra
			&& *(t_op *)ps->moves->next->content == op_sa
			&& *(t_op *)ps->moves->next->next->content == op_ra
			&& *(t_op *)ps->moves->next->next->next->content == op_sa)
			pa(ra(ra(pb(sa(rra(sa(rra(ps))))))));
		else if (*(t_op *)ps->moves->content == op_sa
			&& *(t_op *)ps->moves->next->content == op_rra
			&& *(t_op *)ps->moves->next->next->content == op_sa
			&& *(t_op *)ps->moves->next->next->next->content == op_rra)
			pa(rra(rra(pb(ra(sa(ra(sa(ps))))))));
		else if (*(t_op *)ps->moves->content == op_rb
			&& *(t_op *)ps->moves->next->content == op_sb
			&& *(t_op *)ps->moves->next->next->content == op_rb
			&& *(t_op *)ps->moves->next->next->next->content == op_sb)
			pb(rb(rb(pa(sb(rrb(sb(rrb(ps))))))));
		else if (*(t_op *)ps->moves->content == op_sb
			&& *(t_op *)ps->moves->next->content == op_rrb
			&& *(t_op *)ps->moves->next->next->content == op_sb
			&& *(t_op *)ps->moves->next->next->next->content == op_rrb)
			pb(rrb(rrb(pa(rb(sb(rb(sb(ps))))))));
	}
}

static void	ft_lstadd3_move(t_ps *ps, t_op op)
{
	if (op == op_rrb && *(t_op *)(ps->moves->next->content) == op_rr)
		rr(rrb(rrr(rb(ps))));
	else if (ft_lstsize(ps->moves) > 2)
	{
		if (*(t_op *)ps->moves->content == op_pa
			&& *(t_op *)ps->moves->next->content == op_ra
			&& *(t_op *)ps->moves->next->next->content == op_pb)
			ra(sa(pa(rra(pb(ps)))));
		else if (*(t_op *)ps->moves->content == op_pa
			&& *(t_op *)ps->moves->next->content == op_rra
			&& *(t_op *)ps->moves->next->next->content == op_pb)
			sa(rra(pa(ra(pb(ps)))));
		else if (*(t_op *)ps->moves->content == op_pb
			&& *(t_op *)ps->moves->next->content == op_rb
			&& *(t_op *)ps->moves->next->next->content == op_pa)
			rb(sb(pb(rrb(pa(ps)))));
		else if (*(t_op *)ps->moves->content == op_pb
			&& *(t_op *)ps->moves->next->content == op_rrb
			&& *(t_op *)ps->moves->next->next->content == op_pa)
			sb(rrb(pb(rb(pa(ps)))));
		else
			ft_lstadd4_move(ps);
	}
}

static void	ft_lstadd2_move(t_ps *ps, t_op op)
{
	ft_malloc_and_add_move(&ps->moves, op, ps);
	if (op == op_ra && *(t_op *)(ps->moves->next->content) == op_rb)
		rr(rrb(rra(ps)));
	else if (op == op_rb && *(t_op *)(ps->moves->next->content) == op_ra)
		rr(rra(rrb(ps)));
	else if (op == op_rra && *(t_op *)(ps->moves->next->content) == op_rrb)
		rrr(rb(ra(ps)));
	else if (op == op_rrb && *(t_op *)(ps->moves->next->content) == op_rra)
		rrr(ra(rb(ps)));
	else if (op == op_ra && *(t_op *)(ps->moves->next->content) == op_rrr)
		rrr(ra(rr(rra(ps))));
	else if (op == op_rb && *(t_op *)(ps->moves->next->content) == op_rrr)
		rrr(rb(rr(rrb(ps))));
	else if (op == op_rra && *(t_op *)(ps->moves->next->content) == op_rrr)
		rrr(rra(rr(ra(ps))));
	else if (op == op_rrb && *(t_op *)(ps->moves->next->content) == op_rrr)
		rrr(rrb(rr(rb(ps))));
	else if (op == op_ra && *(t_op *)(ps->moves->next->content) == op_rr)
		rr(ra(rrr(rra(ps))));
	else if (op == op_rb && *(t_op *)(ps->moves->next->content) == op_rr)
		rr(rb(rrr(rrb(ps))));
	else if (op == op_rra && *(t_op *)(ps->moves->next->content) == op_rr)
		rr(rra(rrr(ra(ps))));
	else
		ft_lstadd3_move(ps, op);
}

static void	ft_lst_rotcheck(t_ps *ps)
{
	if (ft_lstcountop(ps->moves, op_ra) > ft_lstsize(ps->pile_a) / 2)
		ft_lstaddn_move(ps, op_rra, ft_lstsize(ps->pile_a));
	else if (ft_lstcountop(ps->moves, op_rra) > ft_lstsize(ps->pile_a) / 2)
		ft_lstaddn_move(ps, op_ra, ft_lstsize(ps->pile_a));
	else if (ft_lstcountop(ps->moves, op_rb) > ft_lstsize(ps->pile_b) / 2)
		ft_lstaddn_move(ps, op_rrb, ft_lstsize(ps->pile_b));
	else if (ft_lstcountop(ps->moves, op_rrb) > ft_lstsize(ps->pile_b) / 2)
		ft_lstaddn_move(ps, op_rb, ft_lstsize(ps->pile_b));
}

void	ft_lstadd_move(t_ps *ps, t_op op)
{
	if (!ps->moves)
		ft_malloc_and_add_move(&ps->moves, op, ps);
	else if (op == op_pa && *(t_op *)(ps->moves->content) == op_pb)
		ft_lstdelfirst(&ps->moves, &free);
	else if (op == op_pb && *(t_op *)(ps->moves->content) == op_pa)
		ft_lstdelfirst(&ps->moves, &free);
	else if (op == op_ra && *(t_op *)(ps->moves->content) == op_rra)
		ft_lstdelfirst(&ps->moves, &free);
	else if (op == op_rra && *(t_op *)(ps->moves->content) == op_ra)
		ft_lstdelfirst(&ps->moves, &free);
	else if (op == op_rrb && *(t_op *)(ps->moves->content) == op_rb)
		ft_lstdelfirst(&ps->moves, &free);
	else if (op == op_rb && *(t_op *)(ps->moves->content) == op_rrb)
		ft_lstdelfirst(&ps->moves, &free);
	else if (op == op_sa && *(t_op *)(ps->moves->content) == op_sa)
		ft_lstdelfirst(&ps->moves, &free);
	else if (op == op_sb && *(t_op *)(ps->moves->content) == op_sb)
		ft_lstdelfirst(&ps->moves, &free);
	else if (op == op_rrr && *(t_op *)(ps->moves->content) == op_rr)
		ft_lstdelfirst(&ps->moves, &free);
	else if (op == op_rr && *(t_op *)(ps->moves->content) == op_rrr)
		ft_lstdelfirst(&ps->moves, &free);
	else
		ft_lstadd2_move(ps, op);
	ft_lst_rotcheck(ps);
}
