/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:33:24 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/07/27 14:45:00 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_dicionario
{
	int		numero;
	char	extenso[100];
}	t_dicionario;

void	processar_linha(char *linha, t_dicionario *dicionario, size_t *g_index);
void	dividir_linha(char *linha, int *numero, char *extenso);

size_t	g_index;

int	main(void)
{
	int				fd;
	ssize_t			bytes_read;
	char			buffer[1024];
	char			*linha;
	t_dicionario	*dicionario;

	fd = open("/nfs/homes/pedro-hm/rush-02/numbers.dict", O_RDONLY);
	if (fd == -1)
	{
		write(STDOUT_FILENO, "Não foi possível abrir o arquivo\n", 34);
		return (1);
	}
	dicionario = (t_dicionario *)malloc(100 * sizeof(t_dicionario));
	if (dicionario == NULL)
	{
		write(STDOUT_FILENO, "Falha ao alocar memória\n", 25);
		close(fd);
		return (1);
	}
	g_index = 0;
	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		linha = buffer;
		while (*linha != '\0' && g_index < 100)
		{
			processar_linha(linha, dicionario, &g_index);
			while (*linha != '\n' && *linha != '\0')
				linha++;
			if (*linha == '\n')
				linha++;
		}
	}
	if (bytes_read == -1)
		write(STDOUT_FILENO, "Erro ao ler o arquivo\n", 22);
	close(fd);
	for (size_t i = 0; i < g_index; i++)
	{
		char out_buffer[256];
		int len = snprintf(out_buffer, sizeof(out_buffer),
		"Número: %d, Extenso: %s\n", dicionario[i].numero,
		dicionario[i].extenso);
		if (len > 0)
			write(STDOUT_FILENO, out_buffer, len);
	}
	free(dicionario);
	return (0);
}

void	processar_linha(char *linha, t_dicionario *dicionario, size_t *g_index)
{
    char extenso[100];
    int numero;

    dividir_linha(linha, &numero, extenso);
    dicionario[*g_index].numero = numero;
    int j = 0;
    while (extenso[j] != '\0')
    {
        dicionario[*g_index].extenso[j] = extenso[j];
        j++;
    }
    dicionario[*g_index].extenso[j] = '\0';
    (*g_index)++;
}

void dividir_linha(char *linha, int *numero, char *extenso)
{
    int i = 0;

    *numero = 0;
    while (linha[i] != ':' && linha[i] != '\0')
    {
        *numero = *numero * 10 + (linha[i] - '0');
        i++;
    }
    if (linha[i] == ':')
        i++;
    int j = 0;
    while (linha[i] != '\0')
    {
        extenso[j++] = linha[i++];
    }
    extenso[j] = '\0';
}
