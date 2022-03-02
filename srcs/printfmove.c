#include "push_swap.h"
#include "moves.h"

static void	printfop(t_op op)
{
	if (op == op_sa)
		ft_putendl_fd("sa", 1);
	else if (op == op_sb)
		ft_putendl_fd("sb", 1);
	else if (op == op_ss)
		ft_putendl_fd("ss", 1);
	else if (op == op_pa)
		ft_putendl_fd("pa", 1);
	else if (op == op_pb)
		ft_putendl_fd("pb", 1);
	else if (op == op_ra)
		ft_putendl_fd("ra", 1);
	else if (op == op_rb)
		ft_putendl_fd("rb", 1);
	else if (op == op_rr)
		ft_putendl_fd("rr", 1);
	else if (op == op_rra)
		ft_putendl_fd("rra", 1);
	else if (op == op_rrb)
		ft_putendl_fd("rrb", 1);
	else if (op == op_rrr)
		ft_putendl_fd("rrr", 1);
}

void	printfmove(t_list *lst)
{	
	if (lst)
	{
		printfmove(lst->next);
		printfop(*(t_op *)lst->content);
	}
}
