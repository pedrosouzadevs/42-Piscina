/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:52:37 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/07/25 13:46:01 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_min_neg(void);
void	ft_print(char result[11], int i);

void	ft_putnbr(int nb)
{
	char	result[11];
	int		i;
	int		wres;

	wres = nb;
	i = 0;
	if (nb == -2147483648)
		ft_min_neg();
	else if (nb == 0)
		ft_putchar('0');
	else
	{
		if (wres < 0)
		{
			ft_putchar('-');
			wres = wres * -1;
		}
		while (wres != 0)
		{
			result[i] = (wres % 10) + '0';
			wres = wres / 10;
			i++;
		}
		ft_print(result, i);
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_min_neg(void)
{
	write(1, "-", 1);
	write(1, "2", 1);
	write(1, "1", 1);
	write(1, "4", 1);
	write(1, "7", 1);
	write(1, "4", 1);
	write(1, "8", 1);
	write(1, "3", 1);
	write(1, "6", 1);
	write(1, "4", 1);
	write(1, "8", 1);
}

void	ft_print(char result[11], int i)
{
	while (i > 0)
	{
		ft_putchar(result[i - 1]);
		i--;
	}
}

// int	main(void)
// {
// 	int	number;

// 	number = 10;
// 	ft_putnbr(number);
// 	return (0);
// }
