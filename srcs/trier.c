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
	ps->pile_a = ft_lstmap(ps->pile_init, &nothing, &free);
	ps->pile_b = NULL;
	ft_lstclear(&(ps->moves), free);
	ps->moves = NULL;
	f(ps);
	if (f == &ft_trisimple)
		ft_lstswap(&(ps->moves), &(ps->b_moves));
	else if (ft_lstsize(ps->moves) < ft_lstsize(ps->b_moves))
		ft_lstswap(&(ps->moves), &(ps->b_moves));
}

void ft_trisimple(t_ps *ps)
{
	int n;

	n = ft_lstsize(ps->pile_a);
	while (!ft_pileissorted(ps->pile_a))
	{
		while (n-- > 1)
		{
			if (*(int *)ps->pile_a->content > *(int *)ps->pile_a->next->content)
				sa(ps);
			// if (ft_pileisordered(ps->pile_a))
			// 	break ;
			ra(ps);
		}
		n = ft_lstsize(ps->pile_a);
		// if (ft_pileisordered(ps->pile_a) > n / 2)
		// 	n_move(ps, rra, n - ft_pileisordered(ps->pile_a));
		// else if (ft_pileisordered(ps->pile_a) <=  n / 2)
		// 	n_move(ps, ra, ft_pileisordered(ps->pile_a));
		// if (ft_pileissorted(ps->pile_a))
		// 	break;
		ra(ps);
	}
}

void ft_rectrirapide(t_ps *ps, int n, int toleft)
{
	int i;
	int ls;
	int rs;

	printf("size = %d\ntoleft = %d\n", n, toleft);
	printfpile(ps->pile_a);
	printfpile(ps->pile_b);
	printf("\n");
	if (n > 1)
	{
		if (toleft)
		{
			n_move(ps, pb, n / 2);
			ft_rectrirapide(ps, n - n / 2, 0);
			ft_rectrirapide(ps, n / 2, 1);
		}	
		else
		{
			n_move(ps, pa, n / 2);
			ft_rectrirapide(ps, n / 2, 0);
			ft_rectrirapide(ps, n - n / 2, 1);
		}
		i = 0;
		if (toleft)
		{
			ls = n - n / 2;
			rs = n / 2;
		}
		else
		{
			ls = n / 2;
			rs = n - n / 2;
		}
		while (i < n)
		{
			printfpile(ps->pile_a);
			printfpile(ps->pile_b);
			printf("\n");
			if (!ls)
			{
				rs--;
				if (toleft)
					pa(ps);
			}
			else if (!rs)
			{
				ls--;
				if (!toleft)
					pb(ps);
			}
			else if (*(int *)ps->pile_a->content < *(int *)ps->pile_b->content)
			{
				ls--;
				if (!toleft)
					pb(ps);
			}
			else
			{
				rs--;
				if (toleft)
					pa(ps);
			}
			if (toleft)
				ra(ps);
			else
				rb(ps);
			i++;
		}
		if (toleft)
			n_move(ps, rra, n);
		else
			n_move(ps, rrb, n);
	}
}

void ft_trirapide(t_ps *ps)
{
	ft_rectrirapide(ps, ft_lstsize(ps->pile_a), 1);
}

void	trier(t_ps *ps)
{
	ft_do_tri(ps, &ft_trisimple);
	ft_do_tri(ps, &ft_trirapide);
}