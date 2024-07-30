/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_break_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 19:16:37 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/07/29 13:32:11 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void break_num(char *str, t_dicionario *dicionario, size_t *g_index)
{
	unsigned long long num_f = 1ULL;
	unsigned long long num = 0ULL;
	unsigned long long result = 0ULL;
	unsigned long long divisor = 1000000000000000000ULL;
	int i = 0;

	while (str[i] != '\0')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (num == 0)
	{
		result = num;
		ft_print_number(result, dicionario, g_index);
		return;
	}

	while (num / divisor == 0)
	{
		divisor /= 1000;
	}
	while (num != 0)
	{
		result = num / divisor;
		num = num % divisor;
		num_f = result;

		if (ft_intlen(num_f) == 3)
		{
			result = num_f / 100;
			ft_print_number(result, dicionario, g_index);
			result = 100;
			ft_print_number(result, dicionario, g_index);
			num_f = num_f % 100;
		}

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

		if (divisor != 1)
		{
			result = divisor;
			ft_print_number(result, dicionario, g_index);
			divisor /= 1000;
		}
	}
}
