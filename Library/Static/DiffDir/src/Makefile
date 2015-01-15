CC = gcc
TARGET = Main
NAME = statically_linked
LIBS = -lstaticlib
DIR = -L../lib

all: $(TARGET)

$(TARGET) : $(TARGET).c
	$(CC) -c $(TARGET).c -o $(TARGET).o
	$(CC) -o $(NAME) $(TARGET).o $(DIR) $(LIBS)

clean:
	rm -rf $(TARGET).o $(NAME)
	
