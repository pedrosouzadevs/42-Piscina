/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:54:00 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/07/24 11:56:31 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*start;
	char	*target;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		start = str;
		target = to_find;
		while (*str && *target && *str == *target)
		{
			str++;
			target++;
		}
		if (*target == '\0')
			return (start);
		str = start + 1;
	}
	return (0);
}
