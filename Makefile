VERSION=0.0.5
DISTNAME=omfsprogs-$(VERSION)
DISTFILES=*.[ch] Makefile README COPYING

COMMON_SRCS=crc.c omfs.c dirscan.c stack.c io.c
COMMON_OBJS=$(COMMON_SRCS:.c=.o)

OMFSCK_SRCS=omfsck.c fix.c check.c
OMFSCK_OBJS=$(OMFSCK_SRCS:.c=.o) $(COMMON_OBJS)

MKOMFS_SRCS=mkomfs.c create_fs.c disksize.c
MKOMFS_OBJS=$(MKOMFS_SRCS:.c=.o) $(COMMON_OBJS)

CFLAGS=-g -Wall -Wpadded

all: omfsck mkomfs

omfsck: $(OMFSCK_OBJS)
	gcc -o omfsck $(OMFSCK_OBJS)

mkomfs: $(MKOMFS_OBJS)
	gcc -o mkomfs $(MKOMFS_OBJS)

clean:
	$(RM) omfsck mkomfs *.o

dist: clean
	mkdir $(DISTNAME)
	cp $(DISTFILES) $(DISTNAME)
	tar czvf $(DISTNAME).tar.gz $(DISTNAME)
	$(RM) -r $(DISTNAME)

distcheck: dist
	mkdir build
	cd build && tar xzvf ../$(DISTNAME).tar.gz && \
	cd $(DISTNAME) && $(MAKE) modules
	$(RM) -r build
