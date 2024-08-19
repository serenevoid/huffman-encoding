CC=clang
CFLAGS=-Wall -g

SRC=src
OBJ=obj
SRCS=$(shell find . -name '*.c')
OBJS=$(patsubst $(SRC)/*.c, $(OBJ)/*.o, $(SRCS))
BIN=bin/hostcomp

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) ${CFLAGS) -c $< -o $@

run:
	./$(BIN)

clean:
	rm $(BIN) $(OBJ)/*
