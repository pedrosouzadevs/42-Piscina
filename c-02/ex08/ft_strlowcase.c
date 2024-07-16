/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:23:25 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/07/16 18:25:11 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
