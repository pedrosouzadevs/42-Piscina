/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:44:43 by vimafra-          #+#    #+#             */
/*   Updated: 2024/07/14 19:34:50 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char s);
void	top(int i, int x);
void	bot(int i, int x);
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
			top(i, x);
		if (j > 1 && j < y)
			mid(i, x);
		if (j == y && y != 1)
			bot(i, x);
		i = 1;
		ft_putchar('\n');
		j++;
	}
}

void	top(int i, int x)
{
	while (x >= i)
	{
		if (i == 1)
		{
			ft_putchar('/');
		}
		else if (i > 1 && i < x)
		{
			ft_putchar('*');
		}
		else if (i == x)
		{
			ft_putchar('\\');
		}
		i++;
	}
}

void	bot(int i, int x)
{
	while (x >= i)
	{
		if (i == 1)
		{
			ft_putchar('\\');
		}
		else if (i > 1 && i < x)
		{
			ft_putchar('*');
		}
		else if (i == x)
		{
			ft_putchar('/');
		}
		i++;
	}
}

void	mid(int i, int x)
{
	while (x >= i)
	{
		if (i == 1 || i == x)
			ft_putchar('*');
		else
			ft_putchar(' ');
		i++;
	}
}
