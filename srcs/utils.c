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

int		ft_pileissorted_n(t_list *pile, int n)
{
	if (!pile)
		return (1);
	while (pile->next && n--)
	{
		if (*(int *)pile->content > *(int *)pile->next->content)
			return (0);
		pile = pile->next;
	}
	return (1);
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

void ft_lstdelfirst(t_list **alst, void (*del)(void *))
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
		*alst = (*alst)->next;
		ft_lstdelone(tmp, del);
	}
}

void ft_lstdelnfirst(t_list **alst, int n, void (*del)(void *))
{
	t_list *tmp;

	if (n && *alst && !(*alst)->next)
	{
		ft_lstdelone(*alst, del);
		*alst = NULL;
	}
	else if (*alst && n)
	{
		tmp = *alst;
		*alst = (*alst)->next;
		ft_lstdelone(tmp, del);
		ft_lstdelnfirst(alst, n - 1, del);
	}
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

void	*ft_lstgetn(t_list *lst, int n)
{
	while (lst && n-- > 0)
		lst = lst->next;
	if (!lst)
		return (NULL);
	return (lst->content);
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
void	printfps(t_ps *ps)
{
	printf("Pile A :\n");
	printfpile(ps->pile_a);
	printf("Pile B :\n");
	printfpile(ps->pile_b);
}

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

void	printfop(t_op op)
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

int		ft_cmporder(void *a, void *b)
{
	return(*(int *)a < *(int *)b);
}

int		ft_lstcmp(t_list *lst, int (*f)(void *, void *), void *x)
{
	if (!lst)
		return (0);
	return (f(lst->content, x));
}