#include "push_swap.h"

void	printfps(t_ps *ps)
{
	ft_putendl_fd("Pile A :", 1);
	printfpile(ps->pile_a);
	ft_putendl_fd("Pile B :", 1);
	printfpile(ps->pile_b);
}

void	printfpile(t_list *lst)
{	
	ft_putstr_fd("[ ", 1);
	while (lst)
	{
		ft_putnbr_fd(*(int *)lst->content, 1);
		ft_putchar_fd(' ', 1);
		lst = lst->next;
	}
	ft_putendl_fd("]", 1);
}

