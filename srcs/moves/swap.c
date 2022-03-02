#include "moves.h"

static void	s_pile(t_list **alst)
{
	t_list	*tmp;

	if ((*alst) && (*alst)->next)
	{
		tmp = (*alst)->next;
		(*alst)->next = tmp->next;
		tmp->next = (*alst);
		(*alst) = tmp;
	}
}

t_ps	*sa(t_ps *ps)
{
	t_op	move;

	if (ps->pile_a && ps->pile_a->next)
	{
		move = op_sa;
		s_pile(&(ps->pile_a));
		ft_lstadd_move(ps, move);
	}
	return (ps);
}

t_ps	*sb(t_ps *ps)
{
	t_op	move;

	if (ps->pile_b && ps->pile_b->next)
	{
		move = op_sb;
		s_pile(&(ps->pile_b));
		ft_lstadd_move(ps, move);
	}
	return (ps);
}

t_ps	*ss(t_ps *ps)
{
	t_op	move;

	move = op_ss;
	s_pile(&(ps->pile_a));
	s_pile(&(ps->pile_b));
	ft_lstadd_move(ps, move);
	return (ps);
}
