/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 19:17:43 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/07/29 13:32:07 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int ft_intlen(int nbr)
{
	int i = 0;

	if (nbr == 0)
		return 1;

	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

int ft_atoi(const char *str)
{
	int res;

	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
					*str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-' || *str == '+')
	{
		write(STDOUT_FILENO, "Escreva um número positivo\n", 20);
		return (0);
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		++str;
	}
	return (res);
}
