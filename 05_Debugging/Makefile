CFLAGS=-Wall -Wshadow -Werror -Wextra -g
OPTLEVEL=-O3
COMPILER=cc

all: range test

range: range.c
	$(COMPILER) $(CFLAGS) $(OPTLEVEL) $^ -o $@

test: range
	gdb --quiet --batch -x mod5.gdb --args ./range 1 12 | grep "info" 1>mod5_gen
	gdb --quiet --batch -x range.gdb --args ./range -100 100 3 | grep "info" 1>range_gen
	cmp mod5_gen mod5_model
	cmp range_gen range_model

clean:
	rm -f range *_gen