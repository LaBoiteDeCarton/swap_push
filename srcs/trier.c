#include "push_swap.h"

void *nothing(void *arg)
{
	//deep copy :
	int *n;

	n = malloc(sizeof(int));
	if (!n)
		return (NULL);
	*n = *(int *)arg;
	return ((void *)n);
}

void	ft_do_tri(t_ps *ps, void (*f)(t_ps *ps))
{
	ft_lstclear(&(ps->pile_a), free);
	ft_lstclear(&(ps->pile_b), free);
	ps->pile_a = ft_lstmap(ps->pile_init, &nothing, &free);
	ps->pile_b = NULL;
	ft_lstclear(&(ps->moves), free);
	ps->moves = NULL;
	f(ps);
	printfpile(ps->pile_a);
	printf("\n\nNEXT TRI\n");
	if (!ps->ordered)
		ps->ordered = ft_lstmap(ps->pile_a, &nothing, &free);
	if (ft_lstsize(ps->moves) < ps->bm_size)
		ft_lstswap(&(ps->moves), &(ps->b_moves));
	ps->bm_size = ft_lstsize(ps->b_moves); //on reclacule quand meme, utiliser min de deux valeurs
}

void	trier(t_ps *ps)
{
	ft_do_tri(ps, &ft_trirapide);
	ft_do_tri(ps, &ft_trisimple);
}