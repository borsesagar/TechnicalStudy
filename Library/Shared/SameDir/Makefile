CC = gcc

CFLAGS = -c -Wall -Werror -fPIC 

LIBTARGET = CalcMean

TARGET = Main

LIBNAME = libmean

LIB = -lmean

NAME = dynamically_linked

RM = rm -rf

all: $(LIBTARGET) $(TARGET)

$(LIBTARGET): $(LIBTARGET).c
	$(CC) $(CFLAGS) $(LIBTARGET).c
	$(CC) -shared -o $(LIBNAME).so $(LIBTARGET).o

$(TARGET): $(TARGET).c
	$(CC) -L. -Wall $(TARGET).c -o $(NAME) $(LIB)
	export LD_LIB_PATH =L.:$LD_LIB_PATH

clean:
	$(RM) $(LIBNAME).so $(LIBTARGET).o $(TARGET).o $(NAME)


