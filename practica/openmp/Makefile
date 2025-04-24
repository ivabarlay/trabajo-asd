CC := gcc
CFLAGS := -g
OPENMP_FLAGS := -o0 -fopenmp

SRC := ./src
BIN := ./bin

SERIAL_SRCS = $(SRC)/pi_serie.c $(SRC)/mcpiserial.c
SERIAL_BINS = $(SERIAL_SRCS:$(SRC)/%.c=%)

BINS = $(SERIAL_BINS)

all: $(BIN) $(BINS)

$(SERIAL_BINS):
	$(CC) $(CFLAGS) -o $(BIN)/$@ $(SRC)/$@.c

$(BIN): 
	mkdir ./bin

clean:
	$(RM) -rf $(BIN)
bear:
	bear -- make
