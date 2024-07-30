/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 19:17:07 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/07/29 13:32:09 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void processar_linha(char *linha, t_dicionario *dicionario, size_t *g_index)
{
	char extenso[100];
	unsigned long long numero;
	char number_ext[100];

	dividir_linha(linha, &numero, extenso, number_ext);
	dicionario[*g_index].numero = numero;
	int j = 0;
	int k = 0;
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

void dividir_linha(char *linha, unsigned long long *numero, char *extenso, char *number_ext)
{
	int i = 0;
	int k = 0;

	*numero = 0;
	while (linha[i] != ':' && linha[i] != '\0')
	{
		*numero = *numero * 10 + (linha[i] - '0');
		number_ext[k++] = linha[i];
		i++;
	}
	number_ext[k] = '\0';
	if (linha[i] == ':')
		i++;
	int j = 0;
	while (linha[i] != '\0')
	{
		extenso[j++] = linha[i++];
	}
	extenso[j] = '\0';
}

void ft_search(unsigned long long result, t_dicionario *dicionario, size_t *g_index)
{
	*g_index = 0;
	while (*g_index < 100 && dicionario[*g_index].numero != result)
	{
		(*g_index)++;
	}
}

void ft_print_number(unsigned long long result, t_dicionario *dicionario, size_t *g_index)
{
	ft_search(result, dicionario, g_index);
	if (*g_index < 100)
	{
		write(1, dicionario[*g_index].extenso, ft_strlen(dicionario[*g_index].extenso));
	}
}

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
