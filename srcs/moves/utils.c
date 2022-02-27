#include "moves.h"

int		ft_lstcountop(t_list *lst, t_op op)
{
	int count;

	if (!lst)
		return (0);
	count = 0;
	while (lst)
	{
		if (*(t_op *)lst->content != op)
			break ;
		count++;
		lst = lst->next;
	}
	return (count);
}

int		op_is_rot(t_op op)
{
	return ((op == op_ra || op == op_rb ||
		op == op_rra || op == op_rrb));
}

void	ft_malloc_and_add_move(t_list **moves, t_op op)
{
	t_op *p_op;
	t_list *move;

	p_op = (t_op *)malloc(sizeof(t_op));
	if (!p_op)
		exit(EXIT_FAILURE); //handleerror ici pour free comme il faut
	*p_op = op;
	move = ft_lstnew(p_op);
	if (!move)
	{
		free(p_op);
		exit(EXIT_FAILURE); //handle_error
	}
	ft_lstadd_front(moves, move);
}
