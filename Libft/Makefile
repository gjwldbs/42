.SUFFIXES : .c .o

NAME = libft.a
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c

all: $(NAME)
	
$(NAME): $(OBJECTS)
	ar cr $@ $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all