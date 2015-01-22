CC = gcc
TARGET = Main
NAME = dynamically_linked
LIB = -lmean
DIR = -L../lib
RM = rm -rf
ENVVAR = LD_LIB_PATH

all: $(TARGET)
	

$(TARGET) : $(TARGET).c
	$(CC) $(DIR) -Wall $(TARGET).c -o $(NAME) $(LIB) 
	$(ENVVAR)=$(CURDIR):$$$(ENVVAR)
	export $(ENVVAR)=$(CURDIR):$$$(ENVVAR)

clean:
	$(RM) $(TARGET).o $(NAME)
