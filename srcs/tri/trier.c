#include "tri.h"

static void *copy(void *arg)
{
	int *n;

	n = malloc(sizeof(int));
	if (!n)
		return (NULL);
	*n = *(int *)arg;
	return ((void *)n);
}

static void	ft_do_tri(t_ps *ps, void (*f)(t_ps *ps))
{
	ft_lstclear(&(ps->pile_a), free);
	ft_lstclear(&(ps->pile_b), free);
	ps->pile_a = ft_lstmap(ps->pile_init, &copy, &free);
	ps->pile_b = NULL;
	ft_lstclear(&(ps->moves), free);
	ps->moves = NULL;
	f(ps);
	if (!ps->ordered)
		ps->ordered = ft_lstmap(ps->pile_a, &copy, &free);
	if (ft_lstsize(ps->moves) < ps->bm_size)
		ft_lstswap(&(ps->moves), &(ps->b_moves));
	ps->bm_size = ft_lstsize(ps->b_moves);
}

void	trier(t_ps *ps)
{
	int size;

	size = ft_lstsize(ps->pile_init);
	ft_do_tri(ps, &trirapide);
	if (size < 51)
		ft_do_tri(ps, &trisimple);
	// if (ps->ordered)
	// 	ft_do_tri(ps, &triradix);
	if (ps->ordered)
		ft_do_tri(ps, &tripivot);
	if(ps->ordered)
		ft_do_tri(ps, &tridoublepivot);
	if (ps->ordered && size < 51)
		ft_do_tri(ps, &ft_triinsert);
}