/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:10:50 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/07/25 16:26:23 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	i;

	i = nb - 1;
	if (nb == 0 || nb == 1)
		return (1);
	else
	{
		while (i > 1)
		{
			nb = nb * i;
			i--;
		}
	}
	return (nb);
}

// int	main(void)
// {
// 	int	number;

// 	number = 5;
// 	printf("%d", ft_iterative_factorial(number));
// 	return (0);
// }
