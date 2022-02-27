#ifndef CHECKER_H
# define CHECKER_H

#include "push_swap.h"
#include "moves.h"
#include "libft.h"

/*	checker : check if mouvements of STDIN sort the list of the arguments
		Ordinary use :
			ARG="2 3 4 1"
			./push_swap $ARG | ./checker $ARG
		It's possible to do this :
			./checker 2 3 4 1
		in this case 'checker' read from STDIN and we can enter move values
		on the same principle as Heredoc. The STOP value is "\n".
		If you enter "SHOW" on STDIN, the checker will show the actual state
		of piles A and B.
	return values :
		("Error") on STDERR if values of the arguments are illigible
		("Error: Unable to malloc") on STDERR if malloc failed when creating
			the t_list out of arguments.
		("KO") on STDOUT if movements dont sort the list properly
		("OK") STDOUT if movements do the right thing
*/

void	checkmove(t_ps *ps);

#endif