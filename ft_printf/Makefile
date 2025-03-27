NAME = libftprintf.a

SRCS = ft_printf.c ft_operations.c


OBJS = $(SRCS:.c=.o)

RM = rm -f
CC = cc
LIBC = ar -rc
CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJS)
		$(LIBC) $(NAME)  $(OBJS)

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME) 

re: fclean all

.PHONY : all  clean fclean re