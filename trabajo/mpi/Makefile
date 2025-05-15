CC := mpicc
CFLAGS := -g
MPI_FLAGS := -lm

SRC := ./src
BIN := ./bin

SERIAL_SRCS = $(SRC)/pi_serie.c $(SRC)/mcpi_serial.c
SERIAL_BINS = $(SERIAL_SRCS:$(SRC)/%.c=%)

PAR_SRCS = $(SRC)/pi_par.c $(SRC)/mcpi_par.c
PAR_BINS = $(PAR_SRCS:$(SRC)/%.c=%)

BINS = $(SERIAL_BINS) $(PAR_BINS)

all: $(BIN) $(BINS)

$(SERIAL_BINS):
	$(CC) $(CFLAGS) -o $(BIN)/$@ $(SRC)/$@.c

$(PAR_BINS):
	$(CC) $(CFLAGS) $(OPENMP_FLAGS) -o $(BIN)/$@ $(SRC)/$@.c

$(BIN): 
	mkdir ./bin

clean:
	$(RM) -rf $(BIN)
bear:
	bear -- make
