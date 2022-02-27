#include "push_swap.h"

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

void	*ft_lstgetn(t_list *lst, int n)
{
	while (lst && n-- > 0)
		lst = lst->next;
	if (!lst)
		return (NULL);
	return (lst->content);
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
