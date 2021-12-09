CC		?= gcc
RM		= rm -f

CFLAGS	+= -pedantic -Werror -Wall -Wextra
ifneq ($(CC),tcc)
CFLAGS	+= -ansi
endif
LDFLAGS	+=

TARGETS = basename cat cksum dirname echo false head logname mkfifo pwd sleep \
			 touch true tty uname

all: $(TARGETS)

%: src/%.o
	$(CC) $(LDFLAGS) -o $@ $^

src/%.o: src/%.c
	$(CC) -o $@ -c $(CFLAGS) $<

clean:
	$(RM) **/*.o
	$(RM) $(TARGETS)

re: clean all

.PHONY:all clean re