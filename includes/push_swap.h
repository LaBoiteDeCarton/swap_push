/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:28:15 by dmercadi          #+#    #+#             */
/*   Updated: 2022/03/08 13:28:16 by dmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define ERR_MALLOC "Unable to malloc"

# include "libft.h"

typedef struct s_ps	t_ps;

struct s_ps
{
	t_list	*pile_init;
	t_list	*ordered;
	t_list	*pile_a;
	t_list	*pile_b;
	t_list	*moves;
	t_list	*b_moves;
	int		bm_size;
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
void	ft_lstdelfirst(t_list **alst, void (*del)(void *));
int		ft_lstcmp(t_list *lst, int (*f)(void *, void *), void *x);
int		ft_cmporder(void *a, void *b);
int		ft_strtablen(char **s);
void	chartab_free(char **s);
void	ps_free(t_ps *ps);
void	printfpile(t_list *lst);
void	printfps(t_ps *ps);
void	printfpsvert(t_ps *ps);
void	put_error(char *str);

#endif
