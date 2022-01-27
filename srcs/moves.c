#include "push_swap.h"

void	s_pile(t_list **alst)
{
	t_list	*tmp;

	if ((*alst) && (*alst)->next)
	{
		tmp = (*alst)->next;
		(*alst)->next = tmp->next;
		tmp->next = (*alst); //== ft_lstaddfront
		(*alst) = tmp;
	}
}

void	p_pile(t_list **alstfrom, t_list **alstto)
{
	t_list *tmp;

	if ((*alstfrom))
	{
		tmp = *alstfrom;
		*alstfrom = tmp->next;
		tmp->next = *alstto;
		*alstto = tmp;
	}
}

void	r_pile(t_list **alst)
{
	t_list *tmp;

	if (*alst && (*alst)->next)
	{
		tmp = *alst;
		*alst = tmp->next;
		tmp->next = NULL;
		ft_lstadd_back(alst, tmp);
	}
}

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

void	sa(t_ps *ps)
{
	t_op	move;

	if (ps->pile_a && ps->pile_a->next) //en mettant la condition ici on enleve les mouveemnt inutiles pour racocurcir notre code de correction
	{
		move = op_sa;
		s_pile(&(ps->pile_a));
		ft_lstadd_move(ps, move);
	}
}

void	sb(t_ps *ps)
{
	t_op	move;

	if (ps->pile_a && ps->pile_a->next)
	{
		move = op_sb;
		s_pile(&(ps->pile_b));
		ft_lstadd_move(ps, move);
	}	
}

void	ss(t_ps *ps)
{
	t_op	move;

	move = op_ss;
	s_pile(&(ps->pile_a));
	s_pile(&(ps->pile_b));
	ft_lstadd_move(ps, move);
}

void	pa(t_ps *ps)
{
	t_op	move;

	if (ps->pile_b)
	{
		move = op_pa;
		p_pile(&(ps->pile_b), &(ps->pile_a));
		ft_lstadd_move(ps, move);
	}
}

void	pb(t_ps *ps)
{
	t_op	move;

	if(ps->pile_a)
	{
		move = op_pb;
		p_pile(&(ps->pile_a), &(ps->pile_b));
		ft_lstadd_move(ps, move);
	}
}

void	ra(t_ps *ps)
{
	t_op	move;

	if (ps->pile_a && ps->pile_a->next)
	{
		move = op_ra;
		r_pile(&(ps->pile_a));
		ft_lstadd_move(ps, move);
	}
}

void	rb(t_ps *ps)
{
	t_op	move;

	if (ps->pile_b && ps->pile_b->next)
	{
		move = op_rb;
		r_pile(&(ps->pile_b));
		ft_lstadd_move(ps, move);
	}
}

void	rr(t_ps *ps)
{
	t_op	move;

	move = op_rr;
	r_pile(&(ps->pile_a));
	r_pile(&(ps->pile_b));
	ft_lstadd_move(ps, move);
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

int		ft_lstcountop(t_list *lst, t_op op)
{
	int count;

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

void	ft_lstaddn_move(t_ps *ps, t_op op, int n)
{
	while (n-- > 0)
		ft_lstadd_move(ps, op);
}

void	ft_malloc_and_add_move(t_list **moves, t_op op)
{
	t_op *p_op;
	t_list *move;

	p_op = (t_op *)malloc(sizeof(t_op));
	if (!p_op)
		exit(EXIT_FAILURE); //handleerror ici pour free comme il faut
	*p_op = op;
	move = ft_lstnew(p_op);
	if (!move)
	{
		free(p_op);
		exit(EXIT_FAILURE); //handle_error
	}
	ft_lstadd_front(moves, move);
}

void	ft_lstadd3_move(t_ps *ps, t_op op)
{
	if (ft_lstsize(ps->moves) < 3)
		ft_malloc_and_add_move(&ps->moves, op);
	else if (op == op_ra &&
				*(t_op *)ps->moves->content == op_sa &&
				*(t_op *)ps->moves->next->content == op_ra &&
				*(t_op *)ps->moves->next->next->content == op_sa)
	{
		ft_lstdelnfirst(&ps->moves, 3, &free);
		ft_lstadd_move(ps, op_pb);
		ft_lstadd_move(ps, op_ra);
		ft_lstadd_move(ps, op_ra);
		ft_lstadd_move(ps, op_pa);
	}
	else if (op == op_rra &&
				*(t_op *)ps->moves->content == op_sa &&
				*(t_op *)ps->moves->next->content == op_rra &&
				*(t_op *)ps->moves->next->next->content == op_sa)
	{
		ft_lstdelnfirst(&ps->moves, 3, &free);
		ft_lstadd_move(ps, op_pb);
		ft_lstadd_move(ps, op_rra);
		ft_lstadd_move(ps, op_rra);
		ft_lstadd_move(ps, op_pa);
	}
	else if (op == op_rb &&
				*(t_op *)ps->moves->content == op_sb &&
				*(t_op *)ps->moves->next->content == op_rb &&
				*(t_op *)ps->moves->next->next->content == op_sb)
	{
		ft_lstdelnfirst(&ps->moves, 3, &free);
		ft_lstadd_move(ps, op_pa);
		ft_lstadd_move(ps, op_rb);
		ft_lstadd_move(ps, op_rb);
		ft_lstadd_move(ps, op_pb);
	}
	else if (op == op_rrb &&
				*(t_op *)ps->moves->content == op_sb &&
				*(t_op *)ps->moves->next->content == op_rrb &&
				*(t_op *)ps->moves->next->next->content == op_sb)
	{
		ft_lstdelnfirst(&ps->moves, 3, &free);
		ft_lstadd_move(ps, op_pa);
		ft_lstadd_move(ps, op_rrb);
		ft_lstadd_move(ps, op_rrb);
		ft_lstadd_move(ps, op_pb);
	}
	else
		ft_malloc_and_add_move(&ps->moves, op);
}

void	ft_lstadd2_move(t_ps *ps, t_op op)
{
	if (!ps->moves || !ps->moves->next)
		ft_malloc_and_add_move(&ps->moves, op);
	else if (op == op_pa &&
				*(t_op *)ps->moves->content == op_ra &&
				*(t_op *)ps->moves->next->content == op_pb)
	{
		ft_lstdelnfirst(&ps->moves, 2, &free);
		ft_lstadd_move(ps, op_sa);
		ft_lstadd_move(ps, op_ra);
	}
	else if (op == op_pa &&
				*(t_op *)ps->moves->content == op_rra &&
				*(t_op *)ps->moves->next->content == op_pb)
	{
		ft_lstdelnfirst(&ps->moves, 2, &free);
		ft_lstadd_move(ps, op_rra);
		ft_lstadd_move(ps, op_sa);
	}
	else if (op == op_pb &&
				*(t_op *)ps->moves->content == op_rb &&
				*(t_op *)ps->moves->next->content == op_pa)
	{
		ft_lstdelnfirst(&ps->moves, 2, &free);
		ft_lstadd_move(ps, op_sb);
		ft_lstadd_move(ps, op_rb);
	}
	else if (op == op_pb &&
				*(t_op *)ps->moves->content == op_rrb &&
				*(t_op *)ps->moves->next->content == op_pa)
	{
		ft_lstdelnfirst(&ps->moves, 2, &free);
		ft_lstadd_move(ps, op_rrb);
		ft_lstadd_move(ps, op_sb);
	}
	else
		ft_lstadd3_move(ps, op);
}

void	ft_lstadd_move(t_ps *ps, t_op op) // attention de free le move car on ne l'utilise pas dans certains cas
{
	printfpile(ps->pile_a);
	printfpile(ps->pile_b);
	printf("\n");
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

void	n_move(t_ps *ps, void(*f)(t_ps *), unsigned int n)
{
	while (n-- > 0)
		f(ps);
}