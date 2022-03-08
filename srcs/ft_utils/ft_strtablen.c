/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtablen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:45:57 by dmercadi          #+#    #+#             */
/*   Updated: 2022/03/08 13:45:58 by dmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strtablen(char **s)
{
	int	size;

	size = 0;
	while (*s)
	{
		s++;
		size++;
	}
	return (size);
}
