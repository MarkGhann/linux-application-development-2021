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

tests: test_1 test_2 test_3 test_4 test_5 test_protect_1 test_protect_2

test_1: move
	echo "test 1"

test_2: move
	echo "test 2"

test_3: move
	echo "test 3"

test_4: move
	echo "test 4"

test_5: move
	echo "test 5"

test_protect_1: move protect.so
	echo "test protect 1"

test_protect_2: move protect.so
	echo "test protect 2"

clean:
	rm -r move protect.so *.test