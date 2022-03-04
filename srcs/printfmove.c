#include "push_swap.h"
#include "moves.h"

static void	printfop(t_op op)
{
	if (op == op_sa)
		ft_putendl_fd("sa", STDOUT_FILENO);
	else if (op == op_sb)
		ft_putendl_fd("sb", STDOUT_FILENO);
	else if (op == op_ss)
		ft_putendl_fd("ss", STDOUT_FILENO);
	else if (op == op_pa)
		ft_putendl_fd("pa", STDOUT_FILENO);
	else if (op == op_pb)
		ft_putendl_fd("pb", STDOUT_FILENO);
	else if (op == op_ra)
		ft_putendl_fd("ra", STDOUT_FILENO);
	else if (op == op_rb)
		ft_putendl_fd("rb", STDOUT_FILENO);
	else if (op == op_rr)
		ft_putendl_fd("rr", STDOUT_FILENO);
	else if (op == op_rra)
		ft_putendl_fd("rra", STDOUT_FILENO);
	else if (op == op_rrb)
		ft_putendl_fd("rrb", STDOUT_FILENO);
	else if (op == op_rrr)
		ft_putendl_fd("rrr", STDOUT_FILENO);
}

void	printfmove(t_list *lst)
{	
	if (lst)
	{
		printfmove(lst->next);
		printfop(*(t_op *)lst->content);
	}
}
