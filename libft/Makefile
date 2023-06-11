NAME := libft.a
CC := cc
CFLAGS := -Wall -Wextra -Werror
SRCS := ft_strlen.c ft_atoi.c ft_itoa.c\
        ft_printf.c ft_putnbr_base.c ft_split.c\

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
