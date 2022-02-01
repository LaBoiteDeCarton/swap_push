#include "triradix.h"

void	rec_triradixright(t_ps *ps, int n, int start)
{
	void	*pivot1;
	void	*pivot2;
	int i;

	if (n == 2)
	{
		if (*(int *)ps->pile_b->content < *(int *)ps->pile_b->next->content)
			sb(ps);
	}
	else if (n > 2)
	{
		pivot1 = ft_lstgetn(ps->ordered, start + n / 3); // 1 / 2 lst[1] lst[2] pivot1 inclus dans moyen pivot2 inclus dans grand
		pivot2 = ft_lstgetn(ps->ordered, start + 2 * n / 3);
		printf("pivot1 = %d\n", *(int *)pivot1);
		printf("pivot2 = %d\n", *(int *)pivot2);
		i = 0;
		while (i++ < n)
		{
			if (ft_lstcmp(ps->pile_b, &ft_cmporder, pivot1))
				rb(ps);	//rajouter comme quoi ra + rb == rr
			else if (ft_lstcmp(ps->pile_b, &ft_cmporder, pivot2))
				pa(ps);
			else
			{
				pa(ps); //inverse l'emplacement du moyen et grand...y reflechir
				ra(ps);
			}
		}
		rec_triradixleft(ps, 2 * n / 3 - n / 3, start + n / 3);
		rec_triradixleftbot(ps, n - 2 * n / 3, start + 2 * n / 3);
		rec_triradixrightbot(ps, n / 3, start);
		printf("PIVOTS FAIT\nPILE A : \n");
		printfpile(ps->pile_a);
		printf("PILE B : \n");
		printfpile(ps->pile_b);
		printf("on remet B bot en haut : \n");
		n_move(ps, &rrb, n / 3);
		printf("on remet A up en B : \n");
		n_move(ps, &pb, n * 2 / 3 - n / 3);
		printf("on remet A bot en B : \n");
		n_move(ps, &rra, n - n * 2 / 3); //ou bien rrr pour faire a et b en meme temps pour les recurences intermediaires
		n_move(ps, &pb, n - n * 2 / 3);
	}
}

void	rec_triradixleft(t_ps *ps, int n, int start)
{
	void	*pivot1;
	void	*pivot2;
	int i;

	if (n == 2)
	{
		if (*(int *)ps->pile_a->content > *(int *)ps->pile_a->next->content)
			sa(ps);
	}
	else if (n > 2)
	{
		pivot1 = ft_lstgetn(ps->ordered, start + n / 3); // 1 / 2 lst[1] lst[2] pivot1 inclus dans moyen pivot2 inclus dans grand
		pivot2 = ft_lstgetn(ps->ordered, start + 2 * n / 3);
		printf("n / 3 = %d\n", n / 3);
		printf("2 * n / 3 = %d\n", 2 * n / 3);
		printf("pivot1 = %d\n", *(int *)pivot1);
		printf("pivot2 = %d\n", *(int *)pivot2);
		i = 0;
		while (i++ < n)
		{
			if (ft_lstcmp(ps->pile_a, &ft_cmporder, pivot1))
			{
				pb(ps); //inverse l'emplacement du moyen et grand...y reflechir
				rb(ps);
			} //rajouter comme quoi ra + rb == rr
			else if (ft_lstcmp(ps->pile_a, &ft_cmporder, pivot2))
				pb(ps);
			else
				ra(ps);
		}
		printf("PIVOTS FAIT\nPILE A : \n");
		printfpile(ps->pile_a);
		printf("PILE B : \n");
		printfpile(ps->pile_b);
		printf("\n");
		rec_triradixright(ps, 2 * n / 3 - n / 3, start + n / 3);
		rec_triradixrightbot(ps, n - 2 * n / 3, start + 2 * n / 3);
		rec_triradixleftbot(ps, n / 3, start);
		printf("on remet A bot en haut : \n");
		n_move(ps, &rra, n / 3); //on devrait plutot supposer que le tri fini au dessus
		printf("on remet B up en A : \n");
		n_move(ps, &pa, n * 2 / 3 - n / 3);
		printf("on remet B bot en A : \n");
		n_move(ps, &rrb, n - n * 2 / 3); //ou bien rrr pour faire a et b en meme temps pour les recurences intermediaires
		n_move(ps, &pa, n - n * 2 / 3);
	}
}

void	rec_triradixleftbot(t_ps *ps, int n, int start)
{
	n_move(ps, &rra, n);
	rec_triradixleft(ps, n , start);
	n_move(ps, &ra, n);
}

void	rec_triradixrightbot(t_ps *ps, int n, int start)
{
	printf("on bouge B bot en B up pour trier : \n");
	n_move(ps, &rrb, n);
	rec_triradixright(ps, n , start);
	printf("on remet B up en B bot fin de tri : \n");
	n_move(ps, &rb, n);
}

//on utilise un indice sur la list ordered afin de ne pas retrier les "sous segments" car c'est deja fait de base.

void	triradix(t_ps *ps)
{
	rec_triradixleft(ps, ft_lstsize(ps->pile_a), 0);
	printf("RADIX TERMINE\nPILE A : \n");
	printfpile(ps->pile_a);
	printf("PILE B : \n");
	printfpile(ps->pile_b);
}