CFLAGS=-Wall -Wshadow -Werror -Wextra -g
OPTLEVEL=-O3
COMPILER=cc
SHARED=-shared
ST=-fPIC
LIB_PATH=$(PWD)

all: prog liboutput_static.a prog-a liboutput.so prog-so

fun.o: fun.c outlib.h
	$(COMPILER) $(CFLAGS) $(OPTLEVEL) $(ST) -o $@ -c $<

const.o: const.c
	$(COMPILER) $(CFLAGS) $(OPTLEVEL) $(ST) -o $@ -c $<

prog.o: prog.c outlib.h
	$(COMPILER) $(CFLAGS) $(OPTLEVEL) -o $@ -c $<

prog: fun.o const.o prog.o
	$(COMPILER) $(CFLAGS) $(OPTLEVEL) $^ -o $@

liboutput_static.a: fun.o const.o
	ar -rcs liboutput_static.a fun.o const.o

prog-a: prog.o liboutput_static.a
	$(COMPILER) $(CFLAGS) $(OPTLEVEL) $^ -o $@

liboutput.so: fun.o const.o
	$(COMPILER) $(CFLAGS) $(OPTLEVEL) $(ST) $(SHARED) $^ -o $@

prog-so: prog.o liboutput.so
	$(COMPILER) $(CFLAGS) $(OPTLEVEL) $^ -o $@

test: cmp_tests

run_tests: prog prog-a prog-so
	./prog 1>file_prog_1_out 2>file_prog_1_err
	./prog one 1>file_prog_2_out 2>file_prog_2_err
	./prog one two three 1>file_prog_3_out 2>file_prog_3_err
	./prog-a 1>file_prog-a_1_out 2>file_prog-a_1_err
	./prog-a one 1>file_prog-a_2_out 2>file_prog-a_2_err
	./prog-a one two three 1>file_prog-a_3_out 2>file_prog-a_3_err
	LD_LIBRARY_PATH=$(LIB_PATH) ./prog-so 1>file_prog-so_1_out 2>file_prog-so_1_err
	LD_LIBRARY_PATH=$(LIB_PATH) ./prog-so one 1>file_prog-so_2_out 2>file_prog-so_2_err
	LD_LIBRARY_PATH=$(LIB_PATH) ./prog-so one two three 1>file_prog-so_3_out 2>file_prog-so_3_err

cmp_tests: run_tests
	cmp file_prog_1_out file_prog-a_1_out
	cmp file_prog_1_out file_prog-so_1_out
	cmp file_prog_2_out file_prog-a_2_out
	cmp file_prog_2_out file_prog-so_2_out
	cmp file_prog_3_out file_prog-a_3_out
	cmp file_prog_3_out file_prog-so_3_out
	cmp file_prog_1_err file_prog-a_1_err
	cmp file_prog_1_err file_prog-so_1_err
	cmp file_prog_2_err file_prog-a_2_err
	cmp file_prog_2_err file_prog-so_2_err
	cmp file_prog_3_err file_prog-a_3_err
	cmp file_prog_3_err file_prog-so_3_err

clean:
	rm -f prog prog-a prog-so *.a *.o *.so file_*