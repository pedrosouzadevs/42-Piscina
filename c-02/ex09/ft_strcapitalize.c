/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:04:17 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/07/22 18:05:18 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char c);
int	ft_str_is_numeric(char c);

char	*ft_strcapitalize(char *str)
{
	int	next;
	int	i;

	next = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (next && ft_str_is_alpha(str[i]))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
			next = 0;
		}
		else if (!next && ft_str_is_alpha(str[i]))
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 32;
		}
		else if (ft_str_is_numeric(str[i]))
			next = 1;
		else
			next = 0;
		i++;
	}
	return (str);
}

int	ft_str_is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

int	ft_str_is_numeric(char c)
{
	if (!(c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}
