CC = gcc
TARGET = Main
NAME = dynamically_linked
LIB = -lmean
DIR = -L../lib
RM = rm -rf
ENVVARIABLE = :$LD_LIB_PATH

all: $(TARGET)
	

$(TARGET) : $(TARGET).c
	$(CC) $(DIR) -Wall $(TARGET).c -o $(NAME) $(LIB) 
	export LD_LIB_PATH=$(CURDIR)$(ENVVARIABLE)

clean:
	$(RM) $(TARGET).o $(NAME)
