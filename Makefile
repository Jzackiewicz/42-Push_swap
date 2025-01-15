NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

SOURCES =	main.c error_handling.c list_handling.c \
			operations_ps.c operations_rot.c loading_numbers.c \
			sorting.c
OBJECTS = $(SOURCES:.c=.o)

PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(PRINTF):
	make -C $(PRINTF_DIR)

push_swap: $(OBJECTS) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(PRINTF)

clean:
	make -C $(PRINTF_DIR) clean
	rm -f $(OBJECTS) 

fclean: clean
	make -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re