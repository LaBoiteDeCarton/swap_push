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
	t_list *ordered;
	t_list *pile_a;
	t_list *pile_b;
	t_list *moves;
	t_list *b_moves;
	int		bm_size; //evite de recalculer la taille de bmoves a chaque fois
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
void	ft_malloc_and_add_move(t_list **moves, t_op op);
void	ft_lstadd_move(t_ps *ps, t_op move);
void	ft_lstaddn_move(t_ps *ps, t_op op, int n);

//algor de tri

void	ft_trisimple(t_ps *ps);
void	ft_trisimple_n(t_ps *ps, int n);
void	ft_trirapide(t_ps *ps);
void 	ft_rectrirapideleftn(t_ps *ps, int n);
void	ft_rectrirapiderightn(t_ps *ps, int n);
void	triradix(t_ps *ps);
void	ft_recpivotright(t_ps *ps, int n, int start);
void ft_recpivotleft(t_ps *ps, int n, int start);
void ft_tripivot(t_ps *ps);


void	tridoublepivot(t_ps *ps);
void	rec_tridoublepivotleft(t_ps *ps, int n, int start);
void	rec_tridoublepivotrightbot(t_ps *ps, int n, int start);
void	rec_tridoublepivotleftbot(t_ps *ps, int n, int start);
void	rec_tridoublepivotright(t_ps *ps, int n, int start);





//utils 

void	trier(t_ps *ps);
int		ft_pileissorted(t_list *pile);
int		ft_pileissorted_n(t_list *ps, int n);
int		ft_pileisordered(t_list *pile);
void	ft_lstswap(t_list **lst1, t_list **lst2);
void	ft_lstdellast(t_list **alst, void (*del)(void *)); //inutile
void	ft_lstdelfirst(t_list **alst, void (*del)(void *));
void	ft_lstdelnfirst(t_list **alst, int n, void (*del)(void *));
void	*ft_lstgetn(t_list *lst, int n);
int		ft_lstcmp(t_list *lst, int (*f)(void *, void *), void *x);
int		ft_cmporder(void *a, void *b);
int		ft_strtablen(char **s);
void	chartab_free(char **s);
void	ps_free(t_ps *ps);

//TO DELETE

void	printfpile(t_list *lst);
void	printfmove(t_list *lst);
void	printfps(t_ps *ps);
void	printfop(t_op op);

#endif