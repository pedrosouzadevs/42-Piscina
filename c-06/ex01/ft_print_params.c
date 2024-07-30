/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:52:57 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/07/30 13:53:19 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putstr(char *str);

int main(int argc, char *argv[])
{
  int i;

  i = 1;
  while (i < argc)
  {
    ft_putstr(argv[i]);
    write(1, "\n", 1);
    i++;
  }
  return (0);
}

void ft_putstr(char *str)
{
  while (*str)
    write(1, str++, 1);
}
