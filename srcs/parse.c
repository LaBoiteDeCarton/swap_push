#include "push_swap.h"

int	ft_isint(char *c)
{
	if (*c == '-' || *c == '+')
		c++;
	while (*c)
	{
		if (!ft_isdigit(*(c++)))
			return (0);
	}
	return (1);
}

int		ft_cont_isinlst(t_list *lst, void *cont)
{
	if (!lst)
		return (0);
	if (*((int *)lst->content) == *(int *)cont)
		return (1);
	return (ft_cont_isinlst(lst->next, cont)); 
}

t_list	*parse_arg(int n, char **arg)
{
	t_list	*res;
	t_list	*next;
	int		*val;

	if (n == 0)
		return (NULL);
	if (!ft_isint(*arg))
		return (NULL);
	val = malloc(sizeof(int));
	if (!n)
		return (NULL);
	*val = ft_atoi(*arg); // on ne verifie pas si le int est plus grand que INT_MAX, a faire
	res = ft_lstnew(val);
	if (!res)
	{
		free(val);
		return (NULL);
	}
	next = parse_arg(n - 1, arg + 1);
	if (ft_cont_isinlst(next, res->content) || ft_lstsize(next) != n - 1)
	{
		ft_lstclear(&next, &free);
		ft_lstclear(&res, &free);
		return (NULL);
	}
	ft_lstadd_front(&next, res);
	return (res);
}