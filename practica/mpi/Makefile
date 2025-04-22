CC := mpicc
CFLAGS := -lm

SRC := ./src
BIN := ./bin

SRCS=$(wildcard $(SRC)/*.c)
BINS=$(SRCS:$(SRC)/%.c=%)

all: $(BINS)

%: $(SRC)/%.c $(BIN)
	$(CC) -o $(BIN)/$@ $< $(CFLAGS)

$(BIN): 
	mkdir ./bin

clean:
	$(RM) $(BIN)/*
bear:
	bear -- make
