CC = mpicc
CFLAGS = -g
OBJECTS = saludos.o hola_mundo_avanzado.o
TARGET = saludos hola_mundo_avanzado

SRC_DIR = ./src

all: $(TARGET)

$(TARGET): % : %.o

%.o : $(SRC_DIR)/%.c
		$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

clean: 
	rm -f $(OBJECTS) $(TARGET)

bear: clean
	bear -- make

.PHONY : all clean bear
