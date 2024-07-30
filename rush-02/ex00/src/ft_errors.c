/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:16:04 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/07/28 18:16:54 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	error_dict(t_dicionario *dicionario, int fd)
{
	if (dicionario == NULL)
	{
		write(1, "Falha ao alocar memória\n", 25);
		close(fd);
		return ;
	}
}

void	error_argc(int argc, char *argv[], int fd)
{
	if (!argv[1] && argc == 2)
	{
		write(1, "Escreva um número\n", 20);
		return ;
	}
	else if (!(argv[1] || argv[2]) && argc == 3)
	{
		write(1, "Passe um dicionário e escreva um número\n", 43);
		return ;
	}
	if (argc == 2)
		fd = open("/nfs/homes/pedro-hm/rush-02/ex00/numbers.dict", O_RDONLY);
	else if (argc == 3)
		fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(1, "Não foi possível abrir o arquivo\n", 34);
		return ;
	}
}
