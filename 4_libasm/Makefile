NA = nasm
NA_FLAG = -f macho64

NAME = libasm.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard *.s)

OBJS = $(SRCS:.s=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	ar cr $@ $^

%.o: %.s $(INCS)
		$(NA) $(NA_FLAG) -s $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all