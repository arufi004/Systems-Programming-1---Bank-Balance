CC=gcc
CFLAGS=-I. -g -w
DEPS= balance.h
OBJ = balance_checker.o pair.o check.o
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
balance: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)