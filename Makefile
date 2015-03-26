# System = i686-pc-linux-gnu

CC      = gcc
CFLAGS  = -I../
CFLAGS += -g -O2 -D_REENTRANT -Wall
LIBS    = -lrt -lpthread 

CLEANFILES = core core.* *.core *.o temp.* *.out

PROGS =	getifaddr getip getip_manpage

all:	${PROGS}

EXECUTE = ${CC} ${CFLAGS} -o $@ $^ ${LIBS}

getifaddr: getifaddr_main.o getifaddr.o 
	${EXECUTE}

getip: getip.o
	${EXECUTE}

getip_manpage: getip_manpage.o
	${EXECUTE}

clean:
	rm -f ${PROGS} ${CLEANFILES}
