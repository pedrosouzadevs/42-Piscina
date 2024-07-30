/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:53:38 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/07/30 13:53:48 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putstr(char *str);

int main(int argc, char *argv[])
{
  int i;

  i = argc;
  while (i > 1)
  {
    ft_putstr(argv[i - 1]);
    write(1, "\n", 1);
    i--;
  }
  return (0);
}

void ft_putstr(char *str)
{
  while (*str)
    write(1, str++, 1);
}
