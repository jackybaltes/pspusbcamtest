TARGET = pspusbcamserver
OBJS = pspusbcamserver.o pspusbcamserverexports.o

# Use the kernel's small inbuilt libc
USE_KERNEL_LIBC = 1
# Use only kernel libraries
USE_KERNEL_LIBS = 1

INCDIR = ../include/
CFLAGS = -O2 -G0 -Wall -Werror -fno-builtin-printf
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

LDFLAGS += -mno-crt0 -nostartfiles
LIBDIR =
LIBS = -lpspusbcam -lpsputility -lpspusb

PRX_EXPORTS=pspusbcamserverexports.exp

BUILD_PRX=1

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak
