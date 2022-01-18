#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include <stdio.h> // TO DELETE

typedef struct s_ps t_ps;

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

struct s_ps
{
	t_list *pile_init;
	t_list *pile_a;
	t_list *pile_b;
	t_list *moves;
	t_list *b_moves;
};

t_list	*parse_arg(int n, char **arg);

//move functions
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
void	ft_lstadd_move(t_ps *ps, t_list *move);

void	trier(t_ps *ps);
int		ft_pileissorted(t_list *pile);
int		ft_pileisordered(t_list *pile);
void	ft_lstswap(t_list **lst1, t_list **lst2);
void	ft_lstdellast(t_list **alst, void (*del)(void *));

//TO DELETE

void	printfpile(t_list *lst);
void	printfmove(t_list *lst);

#endif