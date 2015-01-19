CC =  gcc
CD = cd
LIBPATH = lib
SRCPATH = src
DYNAMICLIBTARGET = libdynamic
DYNAMICSRCTARGET = srcdynamic
TARGET = $(DYNAMICLIBTARGET) $(DYNAMICSRCTARGET)

all: $(TARGET)

$(DYNAMICLIBTARGET):
	$(CD) $(LIBPATH); make

$(DYNAMICSRCTARGET):
	$(CD) $(SRCPATH); make


clean:
	$(CD) $(LIBPATH); make clean
	$(CD) $(SRCPATH); make clean
