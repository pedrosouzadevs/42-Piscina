/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 19:15:29 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/07/29 13:32:02 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

size_t g_index;

int main(int argc, char *argv[])
{
	int fd;
	ssize_t bytes_read;
	char buffer[4098];
	char *linha;
	t_dicionario *dicionario;
	char *linha_inicio;

	fd = 0;
	if (!argv[1] && argc == 2)
	{
		write(1, "Escreva um número\n", 20);
		return (1);
	}
	else if (!(argv[1] || argv[2]) && argc == 3)
	{
		write(1, "Passe um dicionário e escreva um número\n", 43);
		return (1);
	}

	if (argc == 2)
		fd = open("/nfs/homes/pedro-hm/rush-02/budega/numbers.dict", O_RDONLY);
	else if (argc == 3)
		fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(1, "Não foi possível abrir o arquivo\n", 34);
		return (1);
	}
	dicionario = (t_dicionario *)malloc(100 * sizeof(t_dicionario));
	if (dicionario == NULL)
	{
		write(1, "Falha ao alocar memória\n", 25);
		close(fd);
		return (1);
	}
	g_index = 0;
	while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0)
	{
		buffer[bytes_read] = '\0';
		linha = buffer;
		while (*linha != '\0' && g_index < 100)
		{
			linha_inicio = linha;
			while (*linha != '\n' && *linha != '\0')
				linha++;
			if (*linha == '\n')
				*linha++ = '\0';

			processar_linha(linha_inicio, dicionario, &g_index);
		}
	}
	if (bytes_read == -1)
		write(1, "Erro ao ler o arquivo\n", 22);

	close(fd);
	if (argc == 2)
		break_num(argv[1], dicionario, &g_index);
	if (argc == 3)
		break_num(argv[2], dicionario, &g_index);

	free(dicionario);
	write(1, "\n", 1);
	return (0);
}
