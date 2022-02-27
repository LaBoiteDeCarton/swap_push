#include "moves.h"

void	rr_pile(t_list **alst)
{
	t_list *tmp;

	if (*alst && (*alst)->next)
	{
		tmp = *alst;
		while (tmp->next->next)
			tmp = tmp->next;
		ft_lstadd_front(alst, tmp->next);
		tmp->next = NULL;
	}
}

void	rra(t_ps *ps)
{
	t_op	move;

	if (ps->pile_a && ps->pile_a->next)
	{
		move = op_rra;
		rr_pile(&(ps->pile_a));
		ft_lstadd_move(ps, move);
	}
}

void	rrb(t_ps *ps)
{
	t_op	move;

	if (ps->pile_a && ps->pile_a->next)
	{
		move = op_rrb;
		rr_pile(&(ps->pile_b));
		ft_lstadd_move(ps, move);
	}
}

void rrr(t_ps *ps)
{
	t_op	move;

	move = op_rrr;
	rr_pile(&(ps->pile_a));
	rr_pile(&(ps->pile_b));
	ft_lstadd_move(ps, move);
}
