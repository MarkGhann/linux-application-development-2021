LDLIBS=-lncurses
CFLAGS=-Wall -Wshadow -Werror -Wextra -g
OPTLEVEL=-O3
COMPILER=gcc

all: renderer

renderer:renderer.cc
	${COMPILER} $(CFLAGS) ${OPTLEVEL} renderer.cc $(LDLIBS) -o renderer
