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

int		ft_strtablen(char **s)
{
	int size;

	size = 0;
	while (*s)
	{
		s++;
		size++;
	}
	return (size);
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
		printf("%s\n", str);
		lst = lst->next;
	}
}
