#include "push_swap.h"

static void	ps_error()
{
	ft_putendl_fd("Error", 1);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_ps ps;
	char **toparse;

	ps.pile_init = NULL;
	ps.pile_a = NULL;
	ps.pile_b = NULL;
	ps.moves = NULL;
	ps.b_moves = NULL;
	ps.bm_size = INT32_MAX;
	toparse = av + 1;
	if (ac == 2)
		toparse = ft_split(av[1], ' ');
	if (ac > 1)
	{
		ps.pile_init = parse_arg(ft_strtablen(toparse), toparse);
		if (ac ==  2)
			chartab_free(toparse);
		if (!ps.pile_init)
			ps_error();
	}
	
	trier(&ps);
	printfmove(ps.b_moves);
	ps_free(&ps);
	return (0);
}