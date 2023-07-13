TARGET = exe.bin
CC ?= gcc

all: clean
	$(CC) main.c create_line_data.c linkedlist.c -o $(TARGET) -lm

clean:
	rm -rf $(TARGET)

.PHONY: all clean

