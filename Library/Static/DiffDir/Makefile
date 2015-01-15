CC = gcc
CD = cd
LIBPATH = lib
SRCPATH = src
STATICLIBTARGET = libstatic
STATICSRCTARGET = srcstatic

TARGET = $(STATICLIBTARGET) $(STATICSRCTARGET)
all : $(TARGET)

$(STATICLIBTARGET):
	$(CD) $(LIBPATH); make

$(STATICSRCTARGET):
	$(CD) $(SRCPATH); make

clean:
	$(CD) $(LIBPATH); make clean
	$(CD) $(SRCPATH); make clean
