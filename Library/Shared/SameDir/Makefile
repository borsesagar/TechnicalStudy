CC = gcc

CFLAGS = -c -Wall -Werror -fPIC 

LIBTARGET = CalcMean

TARGET = Main

LIBNAME = libmean

LIB = -lmean

NAME = dynamically_linked

ENVVAR = LD_LIBRARY_PATH

RM = rm -rf

all: $(LIBTARGET) $(TARGET)

$(LIBTARGET): $(LIBTARGET).c
	$(CC) $(CFLAGS) $(LIBTARGET).c
	$(CC) -shared -o $(LIBNAME).so $(LIBTARGET).o

$(TARGET): $(TARGET).c
	$(CC) -L. -Wall -o $(NAME) $(TARGET).c $(LIB)
	$(ENVVAR)=$(CURDIR):$$$(ENVVAR)
	export $(ENVVAR)=$(CURDIR):$$$(ENVVAR)


clean:
	$(RM) $(LIBNAME).so $(LIBTARGET).o $(TARGET).o $(NAME)


