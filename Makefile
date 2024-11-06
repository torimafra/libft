# Nome do programa final                                                                                                                                                                                           
NAME = libft.a

# Compilador                                                                                                                                                                                                       
CC = gcc

# Flags de compilação                                                                                                                                                                                              
CFLAGS = -Wall -Wextra -Werror

# Arquivos fonte                                                                                                                                                                                                   
SRC = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_strjoin.c ft_strlen.c ft_substr.c ft_tolower.c ft_toupper.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_strdup.c ft_atoi.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_calloc.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_strtrim.c ft_split.c

# Arquivos objeto (substituindo .c por .o)                                                                                                                                                                         
OBJ = $(SRC:.c=.o)

# Regra padrão                                                                                                                                                                                                     
all: $(NAME)

# Compilação do programa                                                                                                                                                                                           
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

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


