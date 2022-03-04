#include "push_swap.h"

void	printfps(t_ps *ps)
{
	ft_putendl_fd("Pile A :", STDOUT_FILENO);
	printfpile(ps->pile_a);
	ft_putendl_fd("Pile B :", STDOUT_FILENO);
	printfpile(ps->pile_b);
}

void	printfpile(t_list *lst)
{	
	ft_putstr_fd("[ ", STDOUT_FILENO);
	while (lst)
	{
		ft_putnbr_fd(*(int *)lst->content, STDOUT_FILENO);
		ft_putchar_fd(' ', STDOUT_FILENO);
		lst = lst->next;
	}
	ft_putendl_fd("]", STDOUT_FILENO);
}

