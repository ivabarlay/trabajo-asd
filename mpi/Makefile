CC := mpicc
CFLAGS := -lm

SRC := ./src
BIN := ./bin

SRCS=$(wildcard $(SRC)/*.c)
BINS=$(SRCS:$(SRC)/%.c=%)

all: $(BINS)

%: $(SRC)/%.c
	$(CC) -o $(BIN)/$@ $< $(CFLAGS)

clean:
	$(RM) $(BIN)/*
bear:
	bear -- make
