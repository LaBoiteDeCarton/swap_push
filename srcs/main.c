#include "push_swap.h"

static void	ps_error()
{
	ft_putendl_fd("Error", 1);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_list *pile_init;
	// t_list *pile_b;

	if (!arg_check(ac - 1, av + 1))
		ps_error();
	pile_init = arg_to_lst(ac - 1, av + 1);
	return (0);
}