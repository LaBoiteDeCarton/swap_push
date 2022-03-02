#include "tri.h"

//on met la moitié de pileA dans pileB en faisant des insertions de façon a etre trié déjà
//on insere dans la pile B dans l'ordre inverse et on remet dans A

static int		ft_cmpequal(void *a, void*b)
{
	return(*(int *)a == *(int *)b);
}

// static int	findn_min(t_ps *ps, int n)
// {
// 	t_list	*curr_min;
// 	t_list	*curr_ptr;

// 	curr_min = ps->pile_a;
// 	curr_ptr = ps->pile_a;
// 	while (n-- > 0)
// 	{
// 		if (*(int *)curr_ptr->content < *(int *)curr_min->content)
// 			curr_min = curr_ptr;
// 		curr_ptr = curr_ptr->next;
// 	}
// 	return (*(int *)curr_min->content);
// }

static int	findn_max(t_ps *ps, int n)
{
	t_list	*curr_max;
	t_list	*curr_ptr;

	curr_max = ps->pile_b;
	curr_ptr = ps->pile_b;
	while (n-- > 0)
	{
		if (*(int *)curr_ptr->content > *(int *)curr_max->content)
			curr_max = curr_ptr;
		curr_ptr = curr_ptr->next;
	}
	return (*(int *)curr_max->content);
}

// void insertrightnormal_n(t_ps *ps, int n)
// {
// 	int	i;
// 	int j;
// 	int	max;

// 	i = 0;
// 	while (i < n)
// 	{
// 		max = findn_max(ps, n - i);
// 		j = 0;
// 		while (*(int *)ps->pile_a->content < max)
// 		{
// 			ra(ps);
// 			j++;
// 		}
// 		pb(ps);
// 		n_move(ps, &rra, j);
// 		i++;
// 	}
// }

void insertleft_n(t_ps *ps, int n)
{
	int	i;
	int j;
	int	max;

	i = 0;
	while (i < n)
	{
		max = findn_max(ps, n - i);
		j = 0;
		while (*(int *)ps->pile_b->content < max)
		{
			rb(ps);
			j++;
		}
		pa(ps);
		n_move(ps, &rrb, j);
		i++;
	}
}

// void insertright_n(t_ps *ps, int n)
// {
// 	int	i;
// 	int j;
// 	int	min;

// 	i = 0;
// 	while (i < n)
// 	{
// 		min = findn_min(ps, n - i);
// 		j = 0;
// 		while (*(int *)ps->pile_a->content > min)
// 		{
// 			ra(ps);
// 			j++;
// 		}
// 		pb(ps);
// 		n_move(ps, &rra, j);

// 		i++;
// 	}
// }

// void	ft_triinsert(t_ps *ps)
// {
// 	insertright_n(ps, ft_lstsize(ps->pile_a));
// 	n_move(ps, &pa, ft_lstsize(ps->pile_b));
// }

void ft_triinsert(t_ps *ps)
{
	t_list	*lst_curr_min;

	lst_curr_min =  ps->ordered;
	while (ps->pile_a)
	{
		while (!ft_lstcmp(ps->pile_a, &ft_cmpequal, lst_curr_min->content))
			ra(ps);
		pb(ps);
		lst_curr_min = lst_curr_min->next;
	}
	n_move(ps, &pa, ft_lstsize(ps->pile_b));
}