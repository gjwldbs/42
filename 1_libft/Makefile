NAME = libft.a
INCS = libft.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = $(filter-out $(BSRCS), $(wildcard *.c))
OBJS = $(SRCS:.c=.o)
BSRCS = $(wildcard *lst*.c)
BOBJCS = $(BSRCS:.c=.o)

all: $(NAME)
	
$(NAME): $(OBJS)
	ar cr $@ $^

bonus: $(BOBJCS)
	ar cr $(NAME) $^

%.o: %.c $(INCS)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BOBJCS)

fclean: clean
	rm -f $(NAME)

re: fclean all