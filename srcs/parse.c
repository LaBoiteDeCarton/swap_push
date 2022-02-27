#include "push_swap.h"

static int	ft_isint(char *c)
{
	if (*c == '-' || *c == '+')
		c++;
	if (!*c)
		return(0);
	while (*c)
	{
		if (!ft_isdigit(*(c++)))
			return (0);
	}
	return (1);
}

static int		ft_cont_isinlst(t_list *lst, void *cont)
{
	if (!lst)
		return (0);
	if (*((int *)lst->content) == *(int *)cont)
		return (1);
	return (ft_cont_isinlst(lst->next, cont)); 
}

static t_list	*create_case(char *arg)
{
	int		*val;
	t_list	*new_case;

	val = malloc(sizeof(int));
	if (!val)
		return (NULL);
	*val = ft_atoi(arg);
	new_case = ft_lstnew(val);
	if (!new_case)
	{
		free(val);
		return (NULL);
	}
	return (new_case);
}

int	parse(int ac, char **av, t_list **pile)
{
	t_list *new_case;

	while (ac--)
	{
		if (!ft_isint(av[ac]))
			return (0);
		new_case = create_case(av[ac]);
		if (!new_case)
			return (-1);
		if (ft_cont_isinlst(*pile, new_case->content))
		{
			ft_lstclear(&new_case, &free);
			return (0);
		}
		ft_lstadd_front(pile, new_case);
	}
	return (1);
}