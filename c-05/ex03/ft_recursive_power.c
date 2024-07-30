/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdro <pdro@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-30 19:46:57 by pdro              #+#    #+#             */
/*   Updated: 2024-07-30 19:46:57 by pdro             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

// int main(void)
// {
//   int number;
//   int power;

//   number = 3;
//   power = 5;
//   printf("%d\n", ft_recursive_power(number, power));
//   return (0);
// }
