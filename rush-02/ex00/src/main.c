/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:24:32 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/07/28 18:51:19 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

size_t g_index;

int main(int argc, char *argv[])
{
	int fd;
	ssize_t bytes_read;
	char buffer[4098];
	t_dicionario *dicionario;

	fd = 0;
	error_argc(argc, argv, fd);
	dicionario = (t_dicionario *)malloc(100 * sizeof(t_dicionario));
	error_dict(dicionario, fd);
	g_index = 0;
	bytes_read = 0;
	read_line(fd, &buffer[4098], bytes_read, dicionario);
	if (bytes_read == -1)
		write(1, "Erro ao ler o arquivo\n", 22);
	close(fd);
	if (argc == 2)
		break_num(argv[1], dicionario, &g_index);
	if (argc == 3)
		break_num(argv[2], dicionario, &g_index);
	free(dicionario);
	// write(1, "\n", 1);
	return (0);
}

void break_num(char *str, t_dicionario *dicionario, size_t *g_index)
{
	unsigned long long num_f;
	unsigned long long num;
	unsigned long long result;
	unsigned long long divisor;

	divisor = 1000000000000000000ULL;
	num = 0ULL;
	num_f = 1ULL;
	result = convert_break(num, str);
	num = result;
	result = 0ULL;
	printf("%s", str);
	printf("%llu", result);

	if (num == 0)
	{
		result = num;
		ft_print_number(result, dicionario, g_index);
		return ;
	}
	reduce_divisor(num, divisor);
	while (num != 0)
	{
		while_break(result, num_f, num, divisor);
		print_all_cent(result, num_f, dicionario, g_index);
		divisor_one(result, divisor, dicionario, *g_index);
	}
}

void	read_line(int fd, char buffer[4098], ssize_t bytes_read, t_dicionario *dicionario)
{
	char *linha;
	char *linha_inicio;

	while ((bytes_read = read(fd, buffer, sizeof(buffer[4098]) - 1)) > 0)
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
}


void processar_linha(char *linha, t_dicionario *dicionario, size_t *g_index)
{
	char extenso[100];
	unsigned long long numero;
	char number_ext[100];
	int j;
	int k;

	dividir_linha(linha, &numero, extenso, number_ext);
	dicionario[*g_index].numero = numero;
	j = 0;
	k = 0;
	while (extenso[j] != '\0')
	{
		dicionario[*g_index].extenso[j] = extenso[j];
		j++;
	}
	while (number_ext[k] != '\0')
	{
		dicionario[*g_index].number_ext[k] = number_ext[k];
		k++;
	}
	dicionario[*g_index].extenso[j] = '\0';
	dicionario[*g_index].number_ext[k] = '\0';
	(*g_index)++;
}

void	dividir_linha(char *linha, unsigned long long *numero,
	char *extenso, char *number_ext)
{
	int i;
	int k;
	int j = 0;

	*numero = 0;
	i = 0;
	k = 0;
	while (linha[i] != ':' && linha[i] != '\0')
	{
		*numero = *numero * 10 + (linha[i] - '0');
		number_ext[k++] = linha[i];
		i++;
	}
	number_ext[k] = '\0';
	if (linha[i] == ':')
		i++;
	j = 0;
	while (linha[i] != '\0')
	{
		if (linha[i] == 32)
			i++;
		extenso[j++] = linha[i++];
	}
	extenso[j] = '\0';
}

