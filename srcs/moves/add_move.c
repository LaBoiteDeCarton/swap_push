#include "moves.h"

static void	ft_lstadd4_move(t_ps *ps)
{
	if (ft_lstsize(ps->moves) > 3)
	{
		if (*(t_op *)ps->moves->content == op_ra &&
				*(t_op *)ps->moves->next->content == op_sa &&
				*(t_op *)ps->moves->next->next->content == op_ra &&
				*(t_op *)ps->moves->next->next->next->content == op_sa)
		{
			rra(ps);
			sa(ps);
			rra(ps);
			sa(ps);
			pb(ps);
			ra(ps);
			ra(ps);
			pa(ps);
		}
		else if (*(t_op *)ps->moves->content == op_sa &&
					*(t_op *)ps->moves->next->content == op_rra &&
					*(t_op *)ps->moves->next->next->content == op_sa &&
					*(t_op *)ps->moves->next->next->next->content == op_rra)
		{
			sa(ps);
			ra(ps);
			sa(ps);
			ra(ps);
			pb(ps);
			rra(ps);
			rra(ps);
			pa(ps);
		}
		else if (*(t_op *)ps->moves->content == op_rb &&
					*(t_op *)ps->moves->next->content == op_sb &&
					*(t_op *)ps->moves->next->next->content == op_rb &&
					*(t_op *)ps->moves->next->next->next->content == op_sb)
		{
			rrb(ps);
			sb(ps);
			rrb(ps);
			sb(ps);
			pa(ps);
			rb(ps);
			rb(ps);
			pb(ps);
		}
		else if (*(t_op *)ps->moves->content == op_rrb &&
					*(t_op *)ps->moves->next->content == op_sb &&
					*(t_op *)ps->moves->next->next->content == op_rrb &&
					*(t_op *)ps->moves->next->next->next->content == op_sb)
		{
			rb(ps);
			sb(ps);
			rb(ps);
			sb(ps);
			pa(ps);
			rrb(ps);
			rrb(ps);
			pb(ps);
		}
	}
}



static void	ft_lstadd3_move(t_ps *ps, t_op op)
{
	ft_malloc_and_add_move(&ps->moves, op);
	if (ps->moves->next)
	{
		if (op == op_pa &&
					*(t_op *)ps->moves->content == op_ra &&
					*(t_op *)ps->moves->next->content == op_pb)
		{
			pb(ps);
			rra(ps);
			pa(ps);
			sa(ps);
			ra(ps);
		}
		else if (op == op_pa &&
					*(t_op *)ps->moves->content == op_rra &&
					*(t_op *)ps->moves->next->content == op_pb)
		{
			pb(ps);
			ra(ps);
			pa(ps);
			rra(ps);
			sa(ps);
		}
		else if (op == op_pb &&
					*(t_op *)ps->moves->content == op_rb &&
					*(t_op *)ps->moves->next->content == op_pa)
		{
			pa(ps);
			rrb(ps);
			pb(ps);
			sb(ps);
			rb(ps);
		}
		else if (op == op_pb &&
					*(t_op *)ps->moves->content == op_rrb &&
					*(t_op *)ps->moves->next->content == op_pa)
		{
			pa(ps);
			rb(ps);
			pb(ps);
			rrb(ps);
			sb(ps);
		}
		else
			ft_lstadd4_move(ps);
	}
}

static void	ft_lstadd2_move(t_ps *ps, t_op op)
{
	if (op == op_ra && *(t_op *)(ps->moves->content) == op_rb)
	{
		ft_lstdelfirst(&ps->moves, &free);
		ft_lstadd_move(ps, op_rr);
	}
	else if (op == op_rb && *(t_op *)(ps->moves->content) == op_ra)
	{
		ft_lstdelfirst(&ps->moves, &free);
		ft_lstadd_move(ps, op_rr);
	}
	else if (op == op_rra && *(t_op *)(ps->moves->content) == op_rrb)
	{
		ft_lstdelfirst(&ps->moves, &free);
		ft_lstadd_move(ps, op_rrr);
	}
	else if (op == op_rrb && *(t_op *)(ps->moves->content) == op_rra)
	{
		ft_lstdelfirst(&ps->moves, &free);
		ft_lstadd_move(ps, op_rrr);
	}
	else if (op_is_rot(op) && *(t_op *)(ps->moves->content) == op_rrr)
	{
		ft_lstadd_move(ps, op_rr);
		ft_lstadd_move(ps, op);
		ft_lstadd_move(ps, op_rrr);	
	}
	else if (op_is_rot(op) && *(t_op *)(ps->moves->content) == op_rr)
	{
		ft_lstadd_move(ps, op_rrr);
		ft_lstadd_move(ps, op);
		ft_lstadd_move(ps, op_rr);	
	}
	else
		ft_lstadd3_move(ps, op);
}

void	ft_lstadd_move(t_ps *ps, t_op op)
{
	if (!ps->moves)
		ft_malloc_and_add_move(&ps->moves, op);
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
	if (ft_lstcountop(ps->moves, op_ra) > ft_lstsize(ps->pile_a) / 2) //trop de rota d'un côté
		ft_lstaddn_move(ps, op_rra, ft_lstsize(ps->pile_a));
	else if (ft_lstcountop(ps->moves, op_rra) > ft_lstsize(ps->pile_a) / 2) //trop de rota d'un côté
		ft_lstaddn_move(ps, op_ra, ft_lstsize(ps->pile_a));
	else if (ft_lstcountop(ps->moves, op_rb) > ft_lstsize(ps->pile_b) / 2) //trop de rota d'un côté
		ft_lstaddn_move(ps, op_rrb, ft_lstsize(ps->pile_b));
	else if (ft_lstcountop(ps->moves, op_rrb) > ft_lstsize(ps->pile_b) / 2) //trop de rota d'un côté
		ft_lstaddn_move(ps, op_rb, ft_lstsize(ps->pile_b));
}
