#include "push_swap.h"



// t_list	*arg_to_lst(int ac, char **av)
// {
// 	t_list	*res;
// 	t_list	*block;
// 	int		*content;
	
// 	if (!ac)
// 		return (NULL);
// 	content = (int *)malloc(sizeof(int));
// 	if (!content)
// 		return (NULL);
// 	*content = ft_atoi(av[0]);
// 	block = ft_lstnew(content);
// 	res = arg_to_lst(ac - 1, av + 1)
// 	ft_lstadd_front(&res, block);
// 	return (res);
// }



// int	arg_check(int ac, char **av)
// {
// 	if (!ac)
// 		return (1);
// 	if (!ft_isint(av[ac - 1]))
// 			return (0);
// 	return(arg_check(ac - 1, av));
// }