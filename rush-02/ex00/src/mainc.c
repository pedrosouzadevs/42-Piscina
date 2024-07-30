/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:24:32 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/07/28 18:56:03 by pedro-hm         ###   ########.fr       */
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

unsigned long long str_to_ull(char *str)
{
    unsigned long long num = 0;
    int i = 0;

    while (str[i] != '\0')
    {
        num = num * 10 + (str[i] - '0');
        i++;
    }
    return num;
}

void handle_zero(unsigned long long num, t_dicionario *dicionario, size_t *g_index)
{
    if (num == 0)
    {
        ft_print_number(num, dicionario, g_index);
    }
}

void reduce_divisor(unsigned long long *num, unsigned long long *divisor)
{
    while (*num / *divisor == 0)
    {
        *divisor /= 1000;
    }
}

void handle_hundreds(unsigned long long num_f, unsigned long long *result, t_dicionario *dicionario, size_t *g_index)
{
    if (ft_intlen(num_f) == 3)
    {
        *result = num_f / 100;
        ft_print_number(*result, dicionario, g_index);
        *result = 100;
        ft_print_number(*result, dicionario, g_index);
    }
}

void handle_tens_and_ones(unsigned long long num_f, unsigned long long *result, t_dicionario *dicionario, size_t *g_index)
{
    if (num_f < 20)
    {
        if (num_f != 0)
        {
            *result = num_f;
            ft_print_number(*result, dicionario, g_index);
        }
    }
    else
    {
        *result = (num_f / 10) * 10;
        ft_print_number(*result, dicionario, g_index);
        num_f = num_f % 10;
        if (num_f != 0)
        {
            *result = num_f;
            ft_print_number(*result, dicionario, g_index);
        }
    }
}

void handle_divisor(unsigned long long *divisor, unsigned long long *result, t_dicionario *dicionario, size_t *g_index)
{
    if (*divisor != 1)
    {
        *result = *divisor;
        ft_print_number(*result, dicionario, g_index);
        *divisor /= 1000;
    }
}

void break_num(char *str, t_dicionario *dicionario, size_t *g_index)
{
    unsigned long long num_f, num, result, divisor;

    divisor = 1000000000000000000ULL;
    num = str_to_ull(str);
    handle_zero(num, dicionario, g_index);
    if (num == 0) return;

    reduce_divisor(&num, &divisor);
    while (num != 0)
    {
        result = num / divisor;
        num = num % divisor;
        num_f = result;

        handle_hundreds(num_f, &result, dicionario, g_index);
        num_f = num_f % 100;
        handle_tens_and_ones(num_f, &result, dicionario, g_index);
        handle_divisor(&divisor, &result, dicionario, g_index);
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

