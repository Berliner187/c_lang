CC = gcc
TARGET = enc256.bin

all:
	$(CC) main.c enc.c dec.c -o $(TARGET) -lm -lssl -lcrypto -Wno-deprecated-declarations

clean:
	rm -rf $(TARGET)

.PHONY: all clean

