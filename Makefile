NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra

SOURCES =	main.c error_handling.c list_handling.c \
			operations_ps.c operations_rot.c parsing_numbers.c \
			sorting.c node_handling.c utils.c choosing_moves_1.c \
			choosing_moves_2.c doing_operations.c
OBJECTS = $(SOURCES:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

push_swap: $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJECTS) 

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re