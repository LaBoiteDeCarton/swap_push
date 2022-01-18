#include "push_swap.h"

int		ft_pileissorted(t_list *pile)
{
	if (!pile)
		return (1);
	while (pile->next)
	{
		if (*(int *)pile->content > *(int *)pile->next->content)
			return (0);
		pile = pile->next;
	}
	return (1);
}

int		ft_pileisordered(t_list *pile)
{
	int count;

	if (!pile)
		return (1);
	count = 1;
	while (pile->next)
	{
		if (*(int *)pile->content > *(int *)pile->next->content)
			break;
		count++;
		pile = pile->next;
	}
	if (!ft_pileissorted(pile->next))
		return (0);
	return (count);
}

void	ft_lstswap(t_list **lst1, t_list **lst2)
{
	t_list *tmp;

	tmp = *lst1;
	*lst1 = *lst2;
	*lst2 = tmp;
}

void ft_lstdellast(t_list **alst, void (*del)(void *))
{
	t_list *tmp;

	if (*alst && !(*alst)->next)
	{
		ft_lstdelone(*alst, del);
		*alst = NULL;
	}
	else if (*alst)
	{
		tmp = *alst;
		while (tmp->next->next)
			tmp = tmp->next;
		ft_lstdelone(tmp->next, del);
		tmp->next = NULL;
	}
}

//TO DELETE

void	printfpile(t_list *lst)
{	
	printf("[ ");
	while (lst)
	{
		printf("%d ", *(int *)lst->content);
		lst = lst->next;
	}
	printf("]\n");
}

void	printfmove(t_list *lst)
{	
	char *str;

	str = malloc(sizeof(str) * 4);
	printf("[ ");
	while (lst)
	{
		if (*(t_op *)lst->content == op_sa)
			ft_strlcpy(str, "sa", 3);
		else if (*(t_op *)lst->content == op_sb)
			ft_strlcpy(str, "sb", 3);
		else if (*(t_op *)lst->content == op_ss)
			ft_strlcpy(str, "ss", 3);
		else if (*(t_op *)lst->content == op_pa)
			ft_strlcpy(str, "pa", 3);
		else if (*(t_op *)lst->content == op_pb)
			ft_strlcpy(str, "pb", 3);
		else if (*(t_op *)lst->content == op_ra)
			ft_strlcpy(str, "ra", 3);
		else if (*(t_op *)lst->content == op_rb)
			ft_strlcpy(str, "rb", 3);
		else if (*(t_op *)lst->content == op_rr)
			ft_strlcpy(str, "rr", 3);
		else if (*(t_op *)lst->content == op_rra)
			ft_strlcpy(str, "rra", 4);
		else if (*(t_op *)lst->content == op_rrb)
			ft_strlcpy(str, "rrb", 4);
		else if (*(t_op *)lst->content == op_rrr)
			ft_strlcpy(str, "rrr", 4);
		printf("%s ", str);
		lst = lst->next;
	}
	printf("]\n");
}
