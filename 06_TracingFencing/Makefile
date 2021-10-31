CFLAGS=-Wall -Wshadow -Werror -Wextra -g
OPTLEVEL=-O0
COMPILER=cc
SHARED=-shared
DYN=-Wl,--no-as-needed -ldl

all: protect.so move tests

protect.so: protect.c
	$(COMPILER) $(CFLAGS) $(OPTLEVEL) $(SHARED) $(DYN) $^ -o $@

move: move.c
	$(COMPILER) $(CFLAGS) $(OPTLEVEL) $^ -o $@

tests: test_1

test_1:
	echo "test 1"

clean:
	rm -r move protect.so *.test