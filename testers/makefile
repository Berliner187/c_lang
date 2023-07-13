TARGET = soft-x86.bin
CC ?= gcc

all: clean
	$(CC) quadro.c -o $(TARGET) -lm
clean:
	rm -rf $(TARGET)

.PHONY: all clean

