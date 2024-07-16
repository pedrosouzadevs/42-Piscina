/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:26:43 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/07/16 17:46:19 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	
	i = 0;
	while(n > i && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while(n > i)
	{
		dest[i] = '\0';
		i++;
	}
	return dest;
}
