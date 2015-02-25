
CFLAGS = -std=c99 -Wall
TEST_CFLAGS = -Ideps

default: test
	./$<

test: CFLAGS+=$(TEST_CFLAGS)
test: test.o encode.o decode.o deps/ok/ok.o

clean:
	rm -f *.o test deps/ok/ok.o

.PHONY: default clean
