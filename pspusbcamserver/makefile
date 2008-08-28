TARGET = pspusbcamserver
OBJS = pspusbcamserver.o pspusbcamserverexports.o

INCDIR = ../include/
CFLAGS = -O2 -G0 -Wall -Werror -fno-pic
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

LDFLAGS =
LDFLAGS += -mno-crt0 -nostartfiles
LIBDIR =
LIBS = -lpspusbcam -lpsputility -lpspusb

PRX_EXPORTS=pspusbcamserverexports.exp

BUILD_PRX=1

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak
