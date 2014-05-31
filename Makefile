
SRC = $(filter-out test.c, $(wildcard *.c))
CFLAGS += -std=c99 -Wall
OBJS = $(SRC:.c=.o)

b64: clean test

$(OBJS):
	$(CC) $(@:.o=.c) -c -o $(@)

test: $(OBJS)
	$(CC) test.c deps/ok/ok.c $(SRC) -Ideps $(CFLAGS) -o test
	./test

clean:
	rm -f test
	rm -f $(OBJS)
