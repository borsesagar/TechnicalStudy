CC = gcc
CFLAGS = -pthread -o
TARGET = threads
RM = rm -rf


all: $(TARGET)

$(TARGET) : $(TARGET).c
	$(CC) $(CFLAGS) $(TARGET) $(TARGET).c

clean:
	$(RM) $(TARGET) 	
