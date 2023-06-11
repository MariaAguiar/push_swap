NAME := push_swap
INCLUDE = include
LIBFT = libft
CC := cc
CFLAGS := -Wall -Wextra -Werror -g
SRCS := push_swap.c push_swap_valids.c push_swap_finds.c\
        push_swap_sort3.c push_swap_sort5.c partial_sort.c\

all: $(NAME)

$(NAME) :
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS) -Ilibft/ -Llibft/ -lft -o push_swap

clean:
	@make clean -C $(LIBFT)

fclean: clean
	rm -rf push_swap
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
