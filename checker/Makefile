NAME = checker

CC = cc
CFLAGS = -Wall -Werror -Wextra

SOURCES	=	doing_operations.c error_handling.c list_handling.c \
			main.c operations_ps.c operations_rot.c \
			parsing_numbers.c utils.c checking.c
OBJECTS	=	$(SOURCES:.c=.o)

LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJECTS) 

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re