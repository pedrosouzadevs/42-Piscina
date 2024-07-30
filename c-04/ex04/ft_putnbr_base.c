/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:34:27 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/07/25 14:03:15 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);
void	ft_putchar(char c);
void	ft_putnbr_base_recursive(long nbr, char *base, int base_len);
int		ft_strlen(char *str);

int	is_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) <= 1)
	{
		return (0);
	}
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base_recursive(long nbr, char *base, int base_len)
{
	if (nbr >= base_len)
		ft_putnbr_base_recursive(nbr / base_len, base, base_len);
	ft_putchar(base[nbr % base_len]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	long	nb;

	base_len = ft_strlen(base);
	if (!is_valid(base))
		return ;
	nb = nbr;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	ft_putnbr_base_recursive(nb, base, base_len);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// int	main(void)
// {
// 	ft_putnbr_base(42, "0123456789");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(42, "01");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(42, "0123456789ABCDEF");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(42, "poneyvif");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(-42, "0123456789");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(0, "0123456789");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(42, "");
// 	ft_putnbr_base(42, "0");
// 	ft_putnbr_base(42, "0123456789+");
// 	ft_putnbr_base(42, "01234567899");
// 	return (0);
// }
