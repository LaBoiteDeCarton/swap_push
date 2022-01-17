#include "push_swap.h"

static void	ps_error()
{
	ft_putendl_fd("Error", 1);
	exit(EXIT_FAILURE);
}

void	printflst(t_list *lst)
{
	if (lst)
	{
		printf("%d ", *(int *)lst->content);
		printflst(lst->next);
	}
}

int	main(int ac, char **av)
{
	t_list *pile_init;
	// t_list *pile_b;

	//checker si n = 1
	pile_init = parse_arg(ac - 1, av + 1);
	if (!pile_init)
		ps_error();
	printflst(pile_init);
	return (0);
}