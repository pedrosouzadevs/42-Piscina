/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:45:26 by vimafra-          #+#    #+#             */
/*   Updated: 2024/07/14 19:35:28 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char s);
void	top_bot(int i, int x);
void	mid(int i, int x);

void	rush(int x, int y)
{
	int	j;
	int	i;

	j = 1;
	i = 1;
	while (y >= j)
	{
		if (j == 1)
			top_bot(i, x);
		if (j > 1 && j < y)
			mid(i, x);
		if (j == y && y != 1)
			top_bot(i, x);
		i = 1;
		ft_putchar('\n');
		j++;
	}
}

void	top_bot(int i, int x)
{
	while (x >= i)
	{
		if (i == 1)
		{
			ft_putchar('A');
		}
		else if (i > 1 && i < x)
		{
			ft_putchar('B');
		}
		else if (i == x)
		{
			ft_putchar('C');
		}
		i++;
	}
}

void	mid(int i, int x)
{
	while (x >= i)
	{
		if (i == 1 || i == x)
			ft_putchar('B');
		else
			ft_putchar(' ');
		i++;
	}
}
