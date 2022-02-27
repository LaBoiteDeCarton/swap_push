#include "push_swap.h"

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

