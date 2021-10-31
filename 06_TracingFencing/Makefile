CFLAGS=-Wall -Wshadow -Werror -Wextra -g
OPTLEVEL=-O0
COMPILER=cc
SHARED=-shared
DYN=-Wl,--no-as-needed -ldl

FILE=./testfile.txt
PROTECTED_FILE=./testfilePROTECT.txt
TEST_NAME=./move_test.test
HELPER_NAME=./move_helper.test
HELPER_PROTECTED_NAME=./move_helperPROTECT.test

all: protect.so move tests

protect.so: protect.c
	$(COMPILER) $(CFLAGS) $(OPTLEVEL) $(SHARED) $(DYN) $^ -o $@

move: move.c
	$(COMPILER) $(CFLAGS) $(OPTLEVEL) $^ -o $@

tests: test_1 test_2 test_protect_1 test_protect_2

test_1: move # (standard): ./move infile [outfile]
	@echo "----- standard test 1 -----"
	cp $(FILE) $(HELPER_NAME)
	./move $(HELPER_NAME) $(TEST_NAME)
	@if [ ! -f $(TEST_NAME) ]; then exit 1; fi
	@if [ -f $(HELPER_NAME) ]; then exit 1; fi
	cmp $(FILE) $(TEST_NAME)
	@echo "----- standard test 1 PASSED -----"
	@rm -rf *.test

test_2: move # (standard): ./move infile [outfile] + strace
	@echo "----- standard test 2 -----"
	cp $(FILE) $(HELPER_NAME)
	./move $(HELPER_NAME) $(TEST_NAME)
	@if [ ! -f $(TEST_NAME) ]; then exit 1; fi
	@if [ -f $(HELPER_NAME) ]; then exit 1; fi
	cmp $(FILE) $(TEST_NAME)
	@echo "----- standard test 2 PASSED -----"
	@rm -rf *.test

test_protect_1: move protect.so # (protect): LD_PRELOAD=./protect.so standard: ./move infile [outfile]
	@echo "----- protected test 1 -----"
	cp $(PROTECTED_FILE) $(HELPER_NAME)
	LD_PRELOAD=./protect.so ./move $(HELPER_NAME) $(TEST_NAME)
	@if [ ! -f $(TEST_NAME) ]; then exit 1; fi
	@if [ -f $(HELPER_NAME) ]; then exit 1; fi
	cmp $(PROTECTED_FILE) $(TEST_NAME)
	@echo "----- protected test 1 PASSED -----"
	@rm -rf *.test

test_protect_2: move protect.so # (protect): LD_PRELOAD=./protect.so standard: ./move PROTECT_infile [outfile]
	@echo "----- protected test 2 -----"
	cp $(PROTECTED_FILE) $(HELPER_PROTECTED_NAME)
	LD_PRELOAD=./protect.so ./move $(HELPER_PROTECTED_NAME) $(TEST_NAME)
	@if [ ! -f $(TEST_NAME) ]; then exit 1; fi
	@if [ ! -f $(HELPER_PROTECTED_NAME) ]; then exit 1; fi
	cmp $(PROTECTED_FILE) $(TEST_NAME)
	@echo "----- protected test 2 PASSED -----"
	@rm -rf *.test

clean:
	rm -r move protect.so