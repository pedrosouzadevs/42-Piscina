/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:43:37 by vimafra-          #+#    #+#             */
/*   Updated: 2024/07/14 20:45:32 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);
int	str_to_int(const char *str);

int	main(int argc, char *argv[])
{	
	if (argc != 3)
	{
		write(1, "Escreva dois argumentos:\n", 26);
		return (1);
	}
	else if (str_to_int(argv[1]) <= 0 || str_to_int(argv[2]) <= 0)
	{
		if (argc != 3)
			write(1, "Escreva dois argumentos:\n", 26);
		else
			write(1, "Digite dois valores inteiros positivos:\n", 41);
		return (1);
	}
	else
	{
		rush(str_to_int(argv[1]), str_to_int(argv[2]));
		return (0);
	}
}

int	str_to_int(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			sign = -1;
		else
			result = result * 10 + (*str - '0');
			str++;
	}
	return (result * sign);
}
