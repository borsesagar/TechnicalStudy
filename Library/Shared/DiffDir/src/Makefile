CC = gcc
TARGET = Main
NAME = dynamically_linked
LIB = -lmean
DIR = -L../lib
RM = rm -rf

all: $(TARGET)
	

$(TARGET) : $(TARGET).c
	$(CC) $(DIR) -Wall $(TARGET).c -o $(NAME) $(LIB) 
	export LD_LIB_PATH=$(CURDIR)$(ENVVARIABLE)

clean:
	$(RM) $(TARGET).o $(NAME)
