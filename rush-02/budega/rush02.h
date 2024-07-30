/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 19:18:18 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/07/29 13:32:08 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
#define RUSH02_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_dicionario
{
	unsigned long long numero;
	char extenso[100];
	char number_ext[100];
} t_dicionario;

extern size_t g_index;

// Funções de main.c
int main(int argc, char *argv[]);

// Funções de ft_break_num.c
void break_num(char *str, t_dicionario *dicionario, size_t *g_index);

// Funções de functions.c
void processar_linha(char *linha, t_dicionario *dicionario, size_t *g_index);
void dividir_linha(char *linha, unsigned long long *numero, char *extenso, char *number_ext);
void ft_search(unsigned long long result, t_dicionario *dicionario, size_t *g_index);
void ft_print_number(unsigned long long result, t_dicionario *dicionario, size_t *g_index);
int ft_strlen(char *str);

// Funções de ft_errors.c
int ft_intlen(int nbr);
int ft_atoi(const char *str);

#endif
