# cpaint Makefile

CC ?=		cc
CFLAGS =	-O2 -pipe -w

PROG =	cpaint
OBJS =	cpaint.o

all: ${OBJS}
	${CC} ${LDFLAGS} -o ${PROG} ${OBJS} -lcurses

clean:
	rm -f ${PROG} ${OBJS} ${PROG}.core
