#include "push_swap.h"
#include "moves.h"

static void	printfop(t_op op)
{
	char *str;

	str = malloc(sizeof(str) * 4);
	if (!str)
		exit(0); //ici faire un handle error pour free ps correctement;
	if (op == op_sa)
		ft_strlcpy(str, "sa", 3);
	else if (op == op_sb)
		ft_strlcpy(str, "sb", 3);
	else if (op == op_ss)
		ft_strlcpy(str, "ss", 3);
	else if (op == op_pa)
		ft_strlcpy(str, "pa", 3);
	else if (op == op_pb)
		ft_strlcpy(str, "pb", 3);
	else if (op == op_ra)
		ft_strlcpy(str, "ra", 3);
	else if (op == op_rb)
		ft_strlcpy(str, "rb", 3);
	else if (op == op_rr)
		ft_strlcpy(str, "rr", 3);
	else if (op == op_rra)
		ft_strlcpy(str, "rra", 4);
	else if (op == op_rrb)
		ft_strlcpy(str, "rrb", 4);
	else if (op == op_rrr)
		ft_strlcpy(str, "rrr", 4);
	printf("%s\n", str); //utiliser ft_putstr, voir si printf est autorisé
	free(str);
}

void	printfmove(t_list *lst)
{	
	if (lst)
	{
		printfmove(lst->next);
		printfop(*(t_op *)lst->content);
	}
}
