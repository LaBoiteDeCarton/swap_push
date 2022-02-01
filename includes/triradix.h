#ifndef TRIRADIX_H
# define TRIRADIX_H

#include "push_swap.h"

void	rec_triradixright(t_ps *ps, int n, int start);
void	rec_triradixleft(t_ps *ps, int n, int start);
void	rec_triradixleftbot(t_ps *ps, int n, int start);
void	rec_triradixrightbot(t_ps *ps, int n, int start);

#endif