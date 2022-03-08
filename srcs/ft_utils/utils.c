/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:46:01 by dmercadi          #+#    #+#             */
/*   Updated: 2022/03/08 13:46:02 by dmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printfps(t_ps *ps)
{
	ft_putendl_fd("Pile A :", STDOUT_FILENO);
	printfpile(ps->pile_a);
	ft_putendl_fd("Pile B :", STDOUT_FILENO);
	printfpile(ps->pile_b);
}

void	printfpile(t_list *lst)
{	
	ft_putstr_fd("[ ", STDOUT_FILENO);
	while (lst)
	{
		ft_putnbr_fd(*(int *)lst->content, STDOUT_FILENO);
		ft_putchar_fd(' ', STDOUT_FILENO);
		lst = lst->next;
	}
	ft_putendl_fd("]", STDOUT_FILENO);
}

static void	put_case(int n)
{
	ft_putchar_fd('|', STDOUT_FILENO);
	ft_putnbr_fd(n, STDOUT_FILENO);
	ft_putchar_fd('|', STDOUT_FILENO);
}

void	printfpsvert(t_ps *ps)
{
	t_list	*pile_a;
	t_list	*pile_b;

	pile_a = ps->pile_a;
	pile_b = ps->pile_b;
	ft_putstr_fd(" A   B\n", STDOUT_FILENO);
	while (pile_a || pile_b)
	{
		if (pile_a)
		{
			put_case(*(int *)pile_a->content);
			pile_a = pile_a->next;
		}
		else
			ft_putstr_fd("   ", STDOUT_FILENO);
		ft_putchar_fd(' ', STDOUT_FILENO);
		if (pile_b)
		{
			put_case(*(int *)pile_b->content);
			pile_b = pile_b->next;
		}
		ft_putendl_fd("", STDOUT_FILENO);
	}
}
