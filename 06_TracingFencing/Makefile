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

test_1: move
	@echo "----- test 1 -----"
	cp $(FILE) $(HELPER_NAME)
	./move $(HELPER_NAME) $(TEST_NAME)
	@if [ ! -f $(TEST_NAME) ]; then exit 1; fi
	@if [ -f $(HELPER_NAME) ]; then exit 1; fi
	cmp $(FILE) $(TEST_NAME)
	@echo "----- test 1 PASSED -----"
	@rm -rf *.test

test_2: move
	echo "test 2"
	@rm -rf *.test

test_protect_1: move protect.so
	@echo "----- test_protect 1 -----"
	cp $(PROTECTED_FILE) $(HELPER_NAME)
	LD_PRELOAD=./protect.so ./move $(HELPER_NAME) $(TEST_NAME)
	@if [ ! -f $(TEST_NAME) ]; then exit 1; fi
	@if [ -f $(HELPER_NAME) ]; then exit 1; fi
	cmp $(PROTECTED_FILE) $(TEST_NAME)
	@echo "----- test_protect 1 PASSED -----"
	@rm -rf *.test

test_protect_2: move protect.so
	@echo "----- test_protect 2 -----"
	cp $(PROTECTED_FILE) $(HELPER_PROTECTED_NAME)
	LD_PRELOAD=./protect.so ./move $(HELPER_PROTECTED_NAME) $(TEST_NAME)
	@if [ ! -f $(TEST_NAME) ]; then exit 1; fi
	@if [ ! -f $(HELPER_PROTECTED_NAME) ]; then exit 1; fi
	cmp $(PROTECTED_FILE) $(TEST_NAME)
	@echo "----- test_protect 2 PASSED -----"
	@rm -rf *.test

clean:
	rm -r move protect.so *.test