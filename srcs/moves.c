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
	t_op	*move;

	if (ps->pile_a && ps->pile_a->next) //en mettant la condition ici on enleve les mouveemnt inutiles pour racocurcir notre code de correction
	{
		move = malloc(sizeof(t_op));
		if (!move)
			exit(EXIT_FAILURE); //faire du free toutoutout
		*move = op_sa;
		s_pile(&(ps->pile_a));
		ft_lstadd_move(ps, ft_lstnew(move));
	}
}

void	sb(t_ps *ps)
{
	t_op	*move;

	if (ps->pile_a && ps->pile_a->next)
	{
		move = malloc(sizeof(t_op));
		if (!move)
			exit(EXIT_FAILURE); //faire du free toutoutout
		*move = op_sb;
		s_pile(&(ps->pile_b));
		ft_lstadd_move(ps, ft_lstnew(move));
	}	
}

void	ss(t_ps *ps)
{
	t_op	*move;

	move = malloc(sizeof(t_op));
	if (!move)
		exit(EXIT_FAILURE); //faire du free toutoutout
	*move = op_ss;
	s_pile(&(ps->pile_a));
	s_pile(&(ps->pile_b));
	ft_lstadd_move(ps, ft_lstnew(move));
}

void	pa(t_ps *ps)
{
	t_op	*move;

	if (ps->pile_b)
	{
		move = malloc(sizeof(t_op));
		if (!move)
			exit(EXIT_FAILURE); //faire du free toutoutout
		*move = op_pa;
		p_pile(&(ps->pile_b), &(ps->pile_a));
		ft_lstadd_move(ps, ft_lstnew(move));
	}
}

void	pb(t_ps *ps)
{
	t_op	*move;

	if(ps->pile_a)
	{
		move = malloc(sizeof(t_op));
		if (!move)
			exit(EXIT_FAILURE); //faire du free toutoutout
		*move = op_pb;
		p_pile(&(ps->pile_a), &(ps->pile_b));
		ft_lstadd_move(ps, ft_lstnew(move));
	}
}

void	ra(t_ps *ps)
{
	t_op	*move;

	if (ps->pile_a && ps->pile_a->next)
	{
		move = malloc(sizeof(t_op));
		if (!move)
			exit(EXIT_FAILURE); //faire du free toutoutout
		*move = op_ra;
		r_pile(&(ps->pile_a));
		ft_lstadd_move(ps, ft_lstnew(move));
	}
}

void	rb(t_ps *ps)
{
	t_op	*move;

	if (ps->pile_b && ps->pile_b->next)
	{
		move = malloc(sizeof(t_op));
		if (!move)
			exit(EXIT_FAILURE); //faire du free toutoutout
		*move = op_rb;
		r_pile(&(ps->pile_b));
		ft_lstadd_move(ps, ft_lstnew(move));
	}
}

void	rr(t_ps *ps)
{
	t_op	*move;

	move = malloc(sizeof(t_op));
	if (!move)
		exit(EXIT_FAILURE); //faire du free toutoutout
	*move = op_rr;
	r_pile(&(ps->pile_a));
	r_pile(&(ps->pile_b));
	ft_lstadd_move(ps, ft_lstnew(move));
}

void	rra(t_ps *ps)
{
	t_op	*move;

	if (ps->pile_a && ps->pile_a->next)
	{
		move = malloc(sizeof(t_op));
		if (!move)
			exit(EXIT_FAILURE); //faire du free toutoutout
		*move = op_rra;
		rr_pile(&(ps->pile_a));
		ft_lstadd_move(ps, ft_lstnew(move));
	}
}

void	rrb(t_ps *ps)
{
	t_op	*move;

	if (ps->pile_a && ps->pile_a->next)
	{
		move = malloc(sizeof(t_op));
		if (!move)
			exit(EXIT_FAILURE); //faire du free toutoutout
		*move = op_rrb;
		rr_pile(&(ps->pile_b));
		ft_lstadd_move(ps, ft_lstnew(move));
	}
}

void rrr(t_ps *ps)
{
	t_op	*move;

	move = malloc(sizeof(t_op));
	if (!move)
		exit(EXIT_FAILURE); //faire du free toutoutout
	*move = op_rrr;
	rr_pile(&(ps->pile_a));
	rr_pile(&(ps->pile_b));
	ft_lstadd_move(ps, ft_lstnew(move));
}

int		ft_lstcountlast(t_list *lst, t_op op)
{
	int count;

	if (!lst)
		return (0);
	count = ft_lstcountlast(lst->next, op);
	if (count == ft_lstsize(lst->next) && *(t_op *)lst->content == op)
		count++;
	return (count);

}

void	ft_lstadd_move(t_ps *ps, t_list *move)
{
	if (!ps->moves)
		ft_lstadd_back(&ps->moves, move);
	else if (*(t_op *)(move->content) == op_pa && *(t_op *)(ft_lstlast(ps->moves)->content) == op_pb)
		ft_lstdellast(&ps->moves, &free);
	else if (*(t_op *)move->content == op_pb && *(t_op *)(ft_lstlast(ps->moves)->content) == op_pa)
		ft_lstdellast(&ps->moves, &free);
	else if (*(t_op *)move->content == op_ra && *(t_op *)(ft_lstlast(ps->moves)->content) == op_rra)
		ft_lstdellast(&ps->moves, &free);
	else if (*(t_op *)move->content == op_rra && *(t_op *)(ft_lstlast(ps->moves)->content) == op_ra)
		ft_lstdellast(&ps->moves, &free);
	else if (*(t_op *)move->content == op_rrb && *(t_op *)(ft_lstlast(ps->moves)->content) == op_rb)
		ft_lstdellast(&ps->moves, &free);
	else if (*(t_op *)move->content == op_rb && *(t_op *)(ft_lstlast(ps->moves)->content) == op_rrb)
		ft_lstdellast(&ps->moves, &free);
	else
		ft_lstadd_back(&ps->moves, move);
	if (ft_lstcountlast(ps->moves, op_ra) > ft_lstsize(ps->pile_a) / 2) //trop de rota d'un côté
		n_move(ps, rra, ft_lstsize(ps->pile_a));
	else if (ft_lstcountlast(ps->moves, op_rra) > ft_lstsize(ps->pile_a) / 2) //trop de rota d'un côté
		n_move(ps, ra, ft_lstsize(ps->pile_a));
	else if (ft_lstcountlast(ps->moves, op_rb) > ft_lstsize(ps->pile_b) / 2) //trop de rota d'un côté
		n_move(ps, rrb, ft_lstsize(ps->pile_b));
	else if (ft_lstcountlast(ps->moves, op_rrb) > ft_lstsize(ps->pile_b) / 2) //trop de rota d'un côté
		n_move(ps, rb, ft_lstsize(ps->pile_b));
}

void	n_move(t_ps *ps, void(*f)(t_ps *), unsigned int n)
{
	while (n-- > 0)
		f(ps);
}