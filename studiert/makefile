CC ?= gcc
TARGET = prog.bin

all: clean
	$(CC) io_main.c io_1.c io_2.c -o $(TARGET) -lm

clean:
	rm -rf $(TARGET)

.PHONY: all clean

