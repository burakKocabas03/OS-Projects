# Programın adı
TARGET = simulator

# Derleyici ve derleme seçenekleri
CC = gcc
CFLAGS = -Wall -Wextra -Wno-unused-parameter

# Hedefler
all: $(TARGET)

# Ana programın derlenmesi
$(TARGET): main.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c

# Temizlik için hedef
clean:
	rm -f $(TARGET)
