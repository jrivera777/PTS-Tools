CC = g++
CFLAGS = -Wall -Werror -std=c++11

# PLIST_GEN_SRC = partner-list-generator.cpp generate.cpp
# PLIST_GEN_OUT = partner-list-generator.o
# ONERD_GEN_SRC = one-round-assignment.cpp
# ONERD_GEN_OUT = one-round-assignment.o
MPSETS_SRC = make-partner-sets.cpp main-make-partners.cpp generate.cpp
MPSETS_OUT = make-partner-sets.o

build: ${MPSETS_SRC}
	${CC} ${CFLAGS} -o ${MPSETS_OUT} ${MPSETS_SRC}

.PHONY: clean

clean:
	rm ./*.o
