/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:53:36 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/07/18 13:48:34 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_if(char *str);  // Corrigido para aceitar um ponteiro char *
int ft_str_is_alpha(char *str);

int main() {
    char str1[] = "HelloWorld";
    char str2[] = "Hello, World!";

    printf("String 1: %s\n", str1);
    if (ft_str_is_alpha(str1)) {
        printf("String 1 contém apenas letras.\n");
    } else {
        printf("String 1 não contém apenas letras.\n");
    }

    printf("\nString 2: %s\n", str2);
    if (ft_str_is_alpha(str2)) {
        printf("String 2 contém apenas letras.\n");
    } else {
        printf("String 2 não contém apenas letras.\n");
    }

    return 0;
}
int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_if(str, i);
	}
	return (1);
}

void	ft_if(char *str, int i)
{
	if (!((str[i] >= 'A' && str[i] <= 'Z') ||
	      (str[i] >= 'a' && str[i] <= 'z')))
	{
		return (0);
	}
	i++;
}
