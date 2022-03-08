/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:06:34 by dmercadi          #+#    #+#             */
/*   Updated: 2022/03/08 15:06:35 by dmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	*copy(void *arg)
{
	int	*n;

	n = malloc(sizeof(int));
	if (!n)
		return (NULL);
	*n = *(int *)arg;
	return ((void *)n);
}

static int	str_to_move(char *str, t_ps *ps)
{
	if (!ft_strncmp("sa", str, 3))
		sa(ps);
	else if (!ft_strncmp("sb", str, 3))
		sb(ps);
	else if (!ft_strncmp("ss", str, 3))
		ss(ps);
	else if (!ft_strncmp("pa", str, 3))
		pa(ps);
	else if (!ft_strncmp("pb", str, 3))
		pb(ps);
	else if (!ft_strncmp("ra", str, 3))
		ra(ps);
	else if (!ft_strncmp("rb", str, 3))
		rb(ps);
	else if (!ft_strncmp("rr", str, 3))
		rr(ps);
	else if (!ft_strncmp("rra", str, 4))
		rra(ps);
	else if (!ft_strncmp("rrb", str, 4))
		rrb(ps);
	else if (!ft_strncmp("rrr", str, 4))
		rrr(ps);
	else
		return (0);
	return (1);
}

static void	tri_fail(t_ps *ps)
{
	ft_putendl_fd("KO", STDOUT_FILENO);
	ps_free(ps);
	exit(EXIT_SUCCESS);
}

static void	tri_success(t_ps *ps)
{
	ft_putendl_fd("OK", STDOUT_FILENO);
	ps_free(ps);
	exit(EXIT_SUCCESS);
}

void	checkmove(t_ps *ps)
{
	char	*line;
	int		show_pile;

	ps->pile_a = ft_lstmap(ps->pile_init, &copy, &free);
	show_pile = 0;
	while (get_next_line(STDIN_FILENO, &line))
	{
		if (!line || !ft_strncmp(line, "", 1))
			break ;
		if (!ft_strncmp(line, "SHOW", 5))
			show_pile = 1;
		else if (!str_to_move(line, ps))
		{
			free(line);
			tri_fail(ps);
		}
		if (show_pile)
			printfps(ps);
		free(line);
	}
	free(line);
	if (ps->pile_b || !ft_pileissorted(ps->pile_a))
		tri_fail(ps);
	tri_success(ps);
}
