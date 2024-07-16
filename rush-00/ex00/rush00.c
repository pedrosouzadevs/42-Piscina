/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:44:11 by vimafra-          #+#    #+#             */
/*   Updated: 2024/07/14 19:34:29 by vimafra-         ###   ########.fr       */
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
		if (i == 1 || i == x)
		{
			ft_putchar('o');
		}
		else if (i > 1 && i < x)
		{
			ft_putchar('-');
		}
		i++;
	}
}

void	mid(int i, int x)
{
	while (x >= i)
	{
		if (i == 1 || i == x)
			ft_putchar('|');
		else
			ft_putchar(' ');
		i++;
	}
}
