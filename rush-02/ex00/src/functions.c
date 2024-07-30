/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:32:01 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/07/28 18:17:33 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

extern size_t g_index;

void ft_search(unsigned long long result, t_dicionario *dicionario, size_t *g_index)
{
	*g_index = 0;
	while (*g_index < 100 && dicionario[*g_index].numero != result)
	{
		(*g_index)++;
	}
}

void ft_print_number(unsigned long long result, t_dicionario *dicionario, size_t *g_index)
{
	ft_search(result, dicionario, g_index);
	if (*g_index < 100)
	{
		write(1, dicionario[*g_index].extenso, ft_strlen(dicionario[*g_index].extenso));
		write(1, " ", 1);
	}
}

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

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

int	ft_atoi(const char *str)
{
	int	res;

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
