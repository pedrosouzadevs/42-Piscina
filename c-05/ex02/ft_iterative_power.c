/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdro <pdro@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-30 19:29:33 by pdro              #+#    #+#             */
/*   Updated: 2024-07-30 19:29:33 by pdro             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 1)
	{
		result = result * nb;
		power--;
	}
	return (result);
}

// int main(void)
// {
//   int number;
//   int power;

//   number = 2;
//   power = 10;
//   printf("%d\n", ft_iterative_power(number, power));
//   return (0);
// }
