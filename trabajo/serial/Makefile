CC := gcc
CFLAGS := -g
MPI_FLAGS := -lm

SRC := ./src
BIN := ./bin

SERIAL_SRCS = $(SRC)/pi_serie.c $(SRC)/mcpi_serial.c
SERIAL_BINS = $(SERIAL_SRCS:$(SRC)/%.c=%)

BINS = $(SERIAL_BINS)

all: $(BIN) $(BINS)

$(SERIAL_BINS):
	$(CC) $(CFLAGS) -o $(BIN)/$@ $(SRC)/$@.c

$(BIN): 
	mkdir ./bin

clean:
	$(RM) -rf $(BIN) compile_commands.json
bear:
	bear -- make
