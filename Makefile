SRCS = ./_printf.c pr_adr.c pr_char.c pr_dec.c pr_hex.c pr_str.c pr_uns_nbr.c
OBJS = $(SRCS:.c=.o)
NAME = lib.a

all : $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

%.o: %.c main.h
	cc -Wall -Wextra -Werror -c $<

all: $(NAME)

$(NAME): $(OBJS)
	ar rsc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
