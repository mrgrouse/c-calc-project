.DEFAULT_GOAL = calc

CC = clang
CFLAGS = -std=c11 -pipe
LDFLAGS =

DEBUG_CFLAGS = $(CFLAGS) -O0 -Werror -Wall -Wextra -g
LDFLAGS =

SRC = calc-simple.c
OBJ = $(SRC:.c=.o)
BIN = calc

calc:
	$(CC) $(CFLAGS) $(SRC) -o $(BIN) $(LDFLAGS)

debug:
	$(CC) $(DEBUG_CFLAGS) $(SRC) -o $(BIN) $(DEBUG_LDFLAGS)

clean:
	rm -f $(BIN) a.out $(OBJ)
