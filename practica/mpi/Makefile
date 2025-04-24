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
	$(RM) -rf $(BIN)
bear:
	bear -- make
