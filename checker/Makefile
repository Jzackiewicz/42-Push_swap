NAME = checker

CC = cc
CFLAGS = -Wall -Werror -Wextra

SOURCES	=	doing_operations.c error_handling.c list_handling.c \
			main.c operations_ps.c operations_rot.c \
			parsing_numbers.c utils.c
OBJECTS	=	$(SOURCES:.c=.o)

PRINTF_DIR	=	../ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(NAME): $(OBJECTS) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(PRINTF)

clean:
	make -C $(PRINTF_DIR) clean
	rm -f $(OBJECTS) 

fclean: clean
	make -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re