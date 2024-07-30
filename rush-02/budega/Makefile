# Nome do programa final
NAME = rush_02

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -Werror -g

# Arquivos fonte
SRC = main.c ft_break_num.c functions.c ft_errors.c

# Arquivos objeto (substituindo .c por .o)
OBJ = $(SRC:.c=.o)

# Regra padrão
all: $(NAME)

# Compilação do programa
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

# Regra para arquivos objeto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpa arquivos objeto
clean:
	rm -f $(OBJ)

# Limpa arquivos objeto e o executável
fclean: clean
	rm -f $(NAME)

# Reconstrói o projeto do zero
re: fclean all

# Declara que estes alvos não são arquivos
.PHONY: all clean fclean re
