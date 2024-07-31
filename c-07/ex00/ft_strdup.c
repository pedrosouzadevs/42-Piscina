/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdro <pdro@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-30 22:53:58 by pdro              #+#    #+#             */
/*   Updated: 2024-07-30 22:53:58 by pdro             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_strlen(char *str);

char *ft_strdup(char *src)
{
    int len;
    char *dest;
    int i;

    len = ft_strlen(src);
    dest = malloc((len + 1) * sizeof(char));
    i = 0;
    while (src[i] != '\0' && i < len)
    {
        dest[i] = src[i];
        i++;
    }
    dest[len] = '\0';
    return (dest);

}


int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

// int main()
// {
//     char *src = "Hello World!";
//     char *dest = ft_strdup(src);
//     printf("%s\n", dest);
//     return 0;
// }
