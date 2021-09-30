LDLIBS=-lncurses
CFLAGS=-Wall -Wshadow -Werror -Wextra -g
OPTLEVEL=-O3
COMPILER=gcc

renderer:renderer.c
	${COMPILER} $(CFLAGS) ${OPTLEVEL} renderer.c $(LDLIBS) -o renderer
