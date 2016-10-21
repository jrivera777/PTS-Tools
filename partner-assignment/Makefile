CC = g++
CFLAGS = -Wall -Werror -std=c++11

MPSETS_SRC = make-partner-sets.cpp main-make-partners.cpp generate.cpp
MPSETS_OUT = make-partner-sets.o

build: ${MPSETS_SRC}
	${CC} ${CFLAGS} -o ${MPSETS_OUT} ${MPSETS_SRC}

.PHONY: clean

clean:
	rm ./*.o
