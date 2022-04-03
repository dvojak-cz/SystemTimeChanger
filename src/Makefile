C=gcc
CFLAGS= -Wall -pedantic -O2
LINKERFLAGS= -lcap
EXECUTABLE=ChangeTime
SHARED=WhiteListCaps.so

.PHONY: all clean ${EXECUTABLE} ${SHARED}

all: ${EXECUTABLE} ${SHARED}

${EXECUTABLE}: main.o WhiteListCaps.o
	${C} $^ ${LINKERFLAGS} -o $@

${SHARED}: WhiteListCaps.o
	${C} -shared $^ ${LINKERFLAGS} -o $@

main.o: main.c WhiteListCaps.h

WhiteListCaps.o: WhiteListCaps.c

%.o:
	${C} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${EXECUTABLE}
	rm -f ${SHARED}
	rm -f *.so
	rm -f *.o