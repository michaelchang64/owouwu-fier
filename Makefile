CC=gcc
CFLAGS=-Wall -pedantic -g3 -lm
PROGS=owouwu

all: $(PROGS)

test: $(PROGS)
	./$(PROGS) navyseal.txt

$(PROGS): owouwu.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) -rf *.o *~ *.dSYM a.out $(PROGS)
