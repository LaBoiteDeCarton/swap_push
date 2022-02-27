#include "moves.h"

void	ft_lstaddn_move(t_ps *ps, t_op op, int n)
{
	while (n-- > 0)
		ft_lstadd_move(ps, op);
}