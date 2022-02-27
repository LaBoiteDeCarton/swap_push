#include "moves.h"

void	n_move(t_ps *ps, void(*f)(t_ps *), unsigned int n)
{
	while (n-- > 0)
		f(ps);
}