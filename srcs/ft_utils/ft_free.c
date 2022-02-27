#include "push_swap.h"

void	ps_free(t_ps *ps)
{
	if (ps->pile_init)
		ft_lstclear(&ps->pile_init, &free);
	if (ps->pile_a)
		ft_lstclear(&ps->pile_a, &free);
	if (ps->pile_b)
		ft_lstclear(&ps->pile_b, &free);
	if (ps->moves)
		ft_lstclear(&ps->moves, &free);
	if (ps->b_moves)
		ft_lstclear(&ps->b_moves, &free);
}

void	chartab_free(char **s)
{
	int i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}
