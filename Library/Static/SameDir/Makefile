# C compiler
CC = gcc

# Variable
AR = ar rcs
LIBNAME = libstaticlib.a
LIBTARGET = StaticLib
TARGET = Main
NAME = statically_linked
LIBS = -lstaticlib


# Creating a static library. A static library is a basically a set of object files 
# that were copied into a single file. This single file is the static library.
# The static library is created with archiver (ar).
# Then the archiver (ar) is invoked to produce a static library (named libstaticlib.a)
# out of the object file StaticLib.o
# Note:- the library must start with the three letters "lib" and have a suffix .a
all: $(LIBTARGET) $(TARGET)

$(LIBTARGET): $(LIBTARGET).c
	$(CC) -c $(LIBTARGET).c -o $(LIBTARGET).o
	$(AR) $(LIBNAME) $(LIBTARGET).o

#Compiling the Main.c and linking against static library
$(TARGET): $(TARGET).c
	$(CC) -c $(TARGET).c -o $(TARGET).o
	$(CC) -o $(NAME) $(TARGET).o -L. $(LIBS)

clean:
	rm -rf $(TARGET).o $(LIBTARGET).o $(LIBNAME) $(NAME)
	

