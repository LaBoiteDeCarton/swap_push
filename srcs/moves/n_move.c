#include "moves.h"

t_ps	*n_move(t_ps *ps, t_ps *(*f)(t_ps *), unsigned int n)
{
	while (n-- > 0)
		f(ps);
	return (ps);
}