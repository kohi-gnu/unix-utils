CC		?= gcc
RM		= rm -f

CFLAGS	+= -ansi -pedantic -Werror -Wall -Wextra
LDFLAGS	+=

all: true false echo basename dirname logname tty cat pwd sleep mkfifo uname \
		touch head cksum

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

logname: src/logname.o
	$(CC) $(LDFLAGS) -o $@ $^

tty: src/tty.o
	$(CC) $(LDFLAGS) -o $@ $^

cat: src/cat.o
	$(CC) $(LDFLAGS) -o $@ $^

pwd: src/pwd.o
	$(CC) $(LDFLAGS) -o $@ $^

sleep: src/sleep.o
	$(CC) $(LDFLAGS) -o $@ $^

mkfifo: src/mkfifo.o
	$(CC) $(LDFLAGS) -o $@ $^

uname: src/uname.o
	$(CC) $(LDFLAGS) -o $@ $^

touch: src/touch.o
	$(CC) $(LDFLAGS) -o $@ $^

head: src/head.o
	$(CC) $(LDFLAGS) -o $@ $^

cksum: src/cksum.o
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	$(RM) **/*.o

fclean: clean
	$(RM) true false echo

re: fclean all

.PHONY:all clean fclean re