#include "push_swap.h"
#include "tri.h"

static void	put_error(char *str)
{
	ft_putendl_fd(str, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static void init_arg(t_ps *ps)
{
	ps->pile_init = NULL;
	ps->ordered = NULL;
	ps->pile_a = NULL;
	ps->pile_b = NULL;
	ps->moves = NULL;
	ps->b_moves = NULL;
	ps->bm_size = INT32_MAX - 20000;
}

int	main(int ac, char **av)
{
	t_ps	ps;
	int		parsing_success;

	init_arg(&ps);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		ac = ft_strtablen(av);
		parsing_success = parse(ac, av, &(ps.pile_init));
		chartab_free(av);
	}
	else
		parsing_success = parse(ac - 1, av + 1, &(ps.pile_init));
	if (parsing_success != 1)
		ps_free(&ps);
	if (parsing_success == 0)
		put_error("Error");
	if (parsing_success == -1)
		put_error("Error: Unable to malloc");
	trier(&ps);
	printfmove(ps.b_moves);
	ps_free(&ps);
	return (0);
}