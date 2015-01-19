CC = gcc
CFLAGS = -c -Wall -Werror -fPIC
LIBTARGET = CalcMean
LIBNAME = libmean
RM = rm -rf

all: $(LIBTARGET)

$(LIBTARGET): $(LIBTARGET).c 
	$(CC) $(CFLAGS) $(LIBTARGET).c
	$(CC) -shared -o $(LIBNAME).so $(LIBTARGET).o

clean:
	$(RM) $(LIBNAME).so $(LIBTARGET).o 
