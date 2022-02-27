#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include <stdio.h> // TO DELETE

typedef struct s_ps t_ps;

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

/* parse : parsing arguments creating a t_list called
	pile_init in ps structure.
	return values :
		(1) if parsing was successful
		(0) if arguments are not eligible
		(-1) if there were some malloc issues
*/
int		parse(int ac, char **av, t_list **pile);

void	printfmove(t_list *lst);

//utils 

int		ft_pileissorted(t_list *pile);
int		ft_pileissorted_n(t_list *ps, int n);
void	ft_lstswap(t_list **lst1, t_list **lst2);
void	*ft_lstgetn(t_list *lst, int n);
void 	ft_lstdelfirst(t_list **alst, void (*del)(void *));
int		ft_lstcmp(t_list *lst, int (*f)(void *, void *), void *x);
int		ft_cmporder(void *a, void *b);
int		ft_strtablen(char **s);
void	chartab_free(char **s);
void	ps_free(t_ps *ps);


//TO DELETE

void	printfpile(t_list *lst);
void	printfps(t_ps *ps);

#endif