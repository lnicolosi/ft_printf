NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
PROJECT_NAME = ft_libft
SRC = ft_printf.c
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re
