#ifndef MOVES_H
# define MOVES_H

#include "push_swap.h"

typedef enum s_op
{
	op_sa,
	op_sb,
	op_ss,
	op_pa,
	op_pb,
	op_ra,
	op_rb,
	op_rr,
	op_rra,
	op_rrb,
	op_rrr	
} t_op;

void	sa(t_ps *ps);
void	sb(t_ps *ps);
void	ss(t_ps *ps);
void	pa(t_ps *ps);
void	pb(t_ps *ps);
void	ra(t_ps *ps);
void	rb(t_ps *ps);
void	rr(t_ps *ps);
void	rra(t_ps *ps);
void	rrb(t_ps *ps);
void	rrr(t_ps *ps);
void	n_move(t_ps *ps, void(*f)(t_ps *), unsigned int n);
void	ft_lstadd_move(t_ps *ps, t_op op);
void	ft_lstaddn_move(t_ps *ps, t_op op, int n);

//Utils

void	ft_malloc_and_add_move(t_list **moves, t_op op);
int		op_is_rot(t_op op);
int		ft_lstcountop(t_list *lst, t_op op);

#endif