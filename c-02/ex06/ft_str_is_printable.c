/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:14:27 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/07/16 18:16:39 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable.c(char *str)
{
	int	i;
	
	i = 0;
	while(str[i] != '\0')
	{
		if (!(str[i] > 32 ')) 
		{
			return (0);
		}
		i++;
	}	
	return (1);
}
