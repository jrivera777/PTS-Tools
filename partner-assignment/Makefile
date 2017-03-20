CC = g++-5
CFLAGS = -Wall -Werror -std=c++11

MPSETS_SRC = make-partner-sets.cpp main.cpp generate.cpp algo-x.cpp
MPSETS_OUT = make-partner-sets.out

build: ${MPSETS_SRC}
	${CC} ${CFLAGS} -o ${MPSETS_OUT} ${MPSETS_SRC}

.PHONY: clean

clean:
	rm ./*.out
