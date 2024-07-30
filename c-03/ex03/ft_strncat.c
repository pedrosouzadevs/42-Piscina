/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:50:06 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/07/24 11:55:06 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*ptr;

	ptr = dest;
	while (*ptr)
	{
		ptr++;
	}
	while (*src && nb > 0)
	{
		*ptr++ = *src++;
		nb--;
	}
	*ptr = '\0';
	return (dest);
}
