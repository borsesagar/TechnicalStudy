CC = gcc
LIBTARGET = StaticLib
LIBNAME = libstaticlib.a
AR = ar rcs


all:$(LIBTARGET)

$(LIBTARGET) : $(LIBTARGET).c
	$(CC) -c $(LIBTARGET).c -o $(LIBTARGET).o
	$(AR) $(LIBNAME) $(LIBTARGET).o

clean:
	rm -rf $(LIBTARGET).o $(LIBNAME)
