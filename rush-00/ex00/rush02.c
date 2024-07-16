/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:45:03 by vimafra-          #+#    #+#             */
/*   Updated: 2024/07/14 19:35:09 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char s);
void	top_bot(int i, int x, char s);
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
			top_bot(i, x, 'A');
		if (j > 1 && j < y)
			mid(i, x);
		if (j == y && y != 1)
			top_bot(i, x, 'C');
		i = 1;
		ft_putchar('\n');
		j++;
	}
}

void	top_bot(int i, int x, char s)
{
	while (x >= i)
	{
		if (i == 1 || i == x)
		{
			ft_putchar(s);
		}
		else if (i > 1 && i < x)
		{
			ft_putchar('B');
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
