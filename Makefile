CC		?= gcc
RM		= rm -f

CFLAGS	+= -ansi -Werror -Wall -Wextra
LDFLAGS	+=

all: true false

true: src/true.o
	$(CC) $(LDFLAGS) -o $@ $^

false: src/false.o
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	$(RM) **/*.o

fclean: clean
	$(RM) true false

re: fclean all

.PHONY:all clean fclean re