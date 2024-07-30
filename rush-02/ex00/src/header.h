/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:29:59 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/07/28 18:57:33 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	processar_linha(char *linha, t_dicionario *dicionario, size_t *g_index);
int	ft_strlen(char *str);
void	break_num(char *str, t_dicionario *dicionario, size_t *g_index);
void	ft_print_number(unsigned long long result, t_dicionario *dicionario, size_t *g_index);
void	ft_search(unsigned long long result, t_dicionario *dicionario, size_t *g_index);
void	dividir_linha(char *linha, unsigned long long *numero, char *extenso, char *number_ext);
int	ft_intlen(int nbr);
int	ft_atoi(const char *str);
void	error_argc(int argc, char *argv[], int fd);
void	read_line(int fd, char buffer[4098], ssize_t bytes_read, t_dicionario *dicionario);
void	error_dict(t_dicionario *dicionario, int fd);
unsigned long long	convert_break(unsigned long long num, char *str);
void	print_cent(unsigned long long result, t_dicionario *dicionario, size_t *g_index, unsigned long long num_f);
void	print_all_cent(unsigned long long result, unsigned long long num_f, t_dicionario *dicionario, size_t *g_index);
void	reduce_divisor(unsigned long long num, unsigned long long divisor);
void	while_break(unsigned long long result, unsigned long long num_f, unsigned long long num, unsigned long long divisor);
void	divisor_one(unsigned long long result, unsigned long long divisor, t_dicionario *dicionario, size_t g_index);

