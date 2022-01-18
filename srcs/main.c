#include "push_swap.h"

static void	ps_error()
{
	ft_putendl_fd("Error", 1);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_ps ps;
	// t_list *pile_b;

	//checker si n = 1
	ps.pile_init = NULL;
	ps.pile_a = NULL;
	ps.pile_b = NULL;
	ps.moves = NULL;
	ps.b_moves = NULL;
	if (ac > 1)
	{
		ps.pile_init = parse_arg(ac - 1, av + 1);
		if (!ps.pile_init)
			ps_error();
	}
	
	trier(&ps);
	printf("After using moves :\nPile A : ");
	printfpile(ps.pile_a);
	printf("Pile B : ");
	printfpile(ps.pile_b);
	printf("Moves : ");
	printfmove(ps.b_moves);
	return (0);
}