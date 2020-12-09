CC		?= gcc
RM		= rm -f

CFLAGS	+= -ansi -Werror -Wall -Wextra
LDFLAGS	+=

all: true false echo

true: src/true.o
	$(CC) $(LDFLAGS) -o $@ $^

false: src/false.o
	$(CC) $(LDFLAGS) -o $@ $^

echo: src/echo.o
	$(CC) $(LDFLAGS) -o $@ $^

basename: src/basename.o
	$(CC) $(LDFLAGS) -o $@ $^

dirname: src/dirname.o
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	$(RM) **/*.o

fclean: clean
	$(RM) true false echo

re: fclean all

.PHONY:all clean fclean re