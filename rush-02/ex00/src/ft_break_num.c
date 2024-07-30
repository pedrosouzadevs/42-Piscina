/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_break_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:27:32 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/07/28 18:51:52 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned long long	convert_break(unsigned long long num, char *str)
{
	int	i = 0;

	i = 0;
	while (str[i] != '\0')
	{
		num = num * 10 + (str[i] - '0');
		i++;
    }
	return (num);
}

void	divisor_one(unsigned long long result, unsigned long long divisor, t_dicionario *dicionario, size_t g_index)
{
	if (divisor != 1)
	{
		result = divisor;
		ft_print_number(result, dicionario, &g_index);
		divisor /= 1000;
	}
}

void	reduce_divisor(unsigned long long num, unsigned long long divisor)
{
	while (num / divisor == 0)
	{
		divisor /= 1000;
	}
}
void	while_break(unsigned long long result, unsigned long long num_f, unsigned long long num, unsigned long long divisor)
{
	result = num / divisor;
	num = num % divisor;
	num_f = result;
}

void	print_all_cent(unsigned long long result, unsigned long long num_f, t_dicionario *dicionario, size_t *g_index)
{
	if (ft_intlen(num_f) == 3)
		print_cent(result, dicionario, g_index, num_f);
	if (num_f < 20)
	{
		if (num_f != 0)
		{
			result = num_f;
			ft_print_number(result, dicionario, g_index);
		}
	}
	else
	{
		result = (num_f / 10) * 10;
		ft_print_number(result, dicionario, g_index);
		num_f = num_f % 10;
		if (num_f != 0)
		{
			result = num_f;
			ft_print_number(result, dicionario, g_index);
		}
	}
}

void print_cent(unsigned long long result, t_dicionario *dicionario, size_t *g_index, unsigned long long num_f)
{
	result = num_f / 100;
	ft_print_number(result, dicionario, g_index);
	result = 100;
	ft_print_number(result, dicionario, g_index);
	num_f = num_f % 100;
}
