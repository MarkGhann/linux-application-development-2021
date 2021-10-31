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

tests: test_1 test_2 test_3 test_4 test_5 test_protect_1 test_protect_2

test_1: move # (standard): ./move infile [outfile]
	@echo "----- standard test 1 -----"
	cp $(FILE) $(HELPER_NAME)
	./move $(HELPER_NAME) $(TEST_NAME)
	@if [ ! -f $(TEST_NAME) ]; then exit 1; fi
	@if [ -f $(HELPER_NAME) ]; then exit 1; fi
	cmp $(FILE) $(TEST_NAME)
	@echo "----- standard test 1 PASSED -----"
	@rm -rf *.test

test_2: move # (standard): ./move infile [outfile] + strace (in main: open)
	@echo "----- standard test 2 (open) -----"
	cp $(FILE) $(HELPER_NAME)
	strace -foo -e fault=openat:error=ETXTBSY:when=3 ./move $(HELPER_NAME) $(TEST_NAME)
	@if [ -f $(TEST_NAME) ]; then exit 1; fi
	@if [ ! -f $(HELPER_NAME) ]; then exit 1; fi
	cmp $(FILE) $(HELPER_NAME)
	strace -foo -e fault=openat:error=ETXTBSY:when=4 ./move $(HELPER_NAME) $(TEST_NAME)
	@if [ -f $(TEST_NAME) ]; then exit 1; fi
	@if [ ! -f $(HELPER_NAME) ]; then exit 1; fi
	cmp $(FILE) $(HELPER_NAME)
	strace -foo -e fault=openat:error=EFAULT:when=3 ./move $(HELPER_NAME) $(TEST_NAME)
	@if [ -f $(TEST_NAME) ]; then exit 1; fi
	@if [ ! -f $(HELPER_NAME) ]; then exit 1; fi
	cmp $(FILE) $(HELPER_NAME)
	strace -foo -e fault=openat:error=EFAULT:when=4 ./move $(HELPER_NAME) $(TEST_NAME)
	@if [ -f $(TEST_NAME) ]; then exit 1; fi
	@if [ ! -f $(HELPER_NAME) ]; then exit 1; fi
	cmp $(FILE) $(HELPER_NAME)
	@echo "----- standard test 2 (open) PASSED -----"
	@rm -rf *.test

test_3: move # (standard): ./move infile [outfile] + strace (in main: close)
	@echo "----- standard test 3 (close) -----"
	cp $(FILE) $(HELPER_NAME)
	strace -foo -e fault=openat:error=ETXTBSY:when=3 ./move $(HELPER_NAME) $(TEST_NAME)
	@if [ ! -f $(HELPER_NAME) ]; then exit 1; fi
	@if [ -f $(TEST_NAME) ]; then exit 1; fi
	cmp $(FILE) $(HELPER_NAME)
	strace -foo -e fault=openat:error=ETXTBSY:when=4 ./move $(HELPER_NAME) $(TEST_NAME)
	@if [ ! -f $(HELPER_NAME) ]; then exit 1; fi
	@if [ -f $(TEST_NAME) ]; then exit 1; fi
	cmp $(FILE) $(HELPER_NAME)
	strace -foo -e fault=openat:error=EFAULT:when=3 ./move $(HELPER_NAME) $(TEST_NAME)
	@if [ ! -f $(HELPER_NAME) ]; then exit 1; fi
	@if [ -f $(TEST_NAME) ]; then exit 1; fi
	cmp $(FILE) $(HELPER_NAME)
	strace -foo -e fault=openat:error=EFAULT:when=4 ./move $(HELPER_NAME) $(TEST_NAME)
	@if [ ! -f $(HELPER_NAME) ]; then exit 1; fi
	@if [ -f $(TEST_NAME) ]; then exit 1; fi
	cmp $(FILE) $(HELPER_NAME)
	@echo "----- standard test 3 (close) PASSED -----"
	@rm -rf *.test

test_4: move # (standard): ./move infile [outfile] + strace (in main: "others")
	@echo "----- standard test 4 -----"
	cp $(FILE) $(HELPER_NAME)
	strace -foo -e fault=openat:error=ETXTBSY:when=3 ./move $(HELPER_NAME) $(TEST_NAME)
	@if [ ! -f $(HELPER_NAME) ]; then exit 1; fi
	@if [ -f $(TEST_NAME) ]; then exit 1; fi
	cmp $(FILE) $(HELPER_NAME)
	strace -foo -e fault=openat:error=ETXTBSY:when=4 ./move $(HELPER_NAME) $(TEST_NAME)
	@if [ ! -f $(HELPER_NAME) ]; then exit 1; fi
	@if [ -f $(TEST_NAME) ]; then exit 1; fi
	cmp $(FILE) $(HELPER_NAME)
	strace -foo -e fault=openat:error=EFAULT:when=3 ./move $(HELPER_NAME) $(TEST_NAME)
	@if [ ! -f $(HELPER_NAME) ]; then exit 1; fi
	@if [ -f $(TEST_NAME) ]; then exit 1; fi
	cmp $(FILE) $(HELPER_NAME)
	strace -foo -e fault=openat:error=EFAULT:when=4 ./move $(HELPER_NAME) $(TEST_NAME)
	@if [ ! -f $(HELPER_NAME) ]; then exit 1; fi
	@if [ -f $(TEST_NAME) ]; then exit 1; fi
	cmp $(FILE) $(HELPER_NAME)
	@echo "----- standard test 4 PASSED -----"
	@rm -rf *.test

test_5: move # (standard): ./move infile [outfile (does not exist)]
	@echo "----- standard test 5 -----"
	cp $(FILE) $(HELPER_NAME)
	strace -foo -e fault=fstat:error=EACCES:when=3 ./move $(HELPER_NAME) $(TEST_NAME)
	@if [ ! -f $(HELPER_NAME) ]; then exit 1; fi
	@if [ -f $(TEST_NAME) ]; then exit 1; fi
	cmp $(FILE) $(HELPER_NAME)
	strace -foo -e fault=fstat:error=ELOOP:when=4 ./move $(HELPER_NAME) $(TEST_NAME)
	@if [ ! -f $(HELPER_NAME) ]; then exit 1; fi
	@if [ -f $(TEST_NAME) ]; then exit 1; fi
	cmp $(FILE) $(HELPER_NAME)
	strace -foo -e fault=read:error=EINVAL:when=2 ./move $(HELPER_NAME) $(TEST_NAME)
	@if [ ! -f $(HELPER_NAME) ]; then exit 1; fi
	@if [ -f $(TEST_NAME) ]; then exit 1; fi
	cmp $(FILE) $(HELPER_NAME)
	strace -foo -e fault=read:error=ETXTBSY:when=3 ./move $(HELPER_NAME) $(TEST_NAME)
	@if [ ! -f $(HELPER_NAME) ]; then exit 1; fi
	@if [ -f $(TEST_NAME) ]; then exit 1; fi
	cmp $(FILE) $(HELPER_NAME)
	strace -foo -e fault=write:error=ENOMEM:when=1 ./move $(HELPER_NAME) $(TEST_NAME)
	@if [ ! -f $(HELPER_NAME) ]; then exit 1; fi
	@if [ -f $(TEST_NAME) ]; then exit 1; fi
	cmp $(FILE) $(HELPER_NAME)
	strace -foo -e fault=unlink:error=ENOMEM:when=1 ./move $(HELPER_NAME) $(TEST_NAME)
	@if [ ! -f $(HELPER_NAME) ]; then exit 1; fi
	@if [ ! -f $(TEST_NAME) ]; then exit 1; fi
	cmp $(FILE) $(HELPER_NAME)
	@echo "----- standard test 5 PASSED -----"
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
	cmp $(PROTECTED_FILE) $(HELPER_PROTECTED_NAME)
	@echo "----- protected test 2 PASSED -----"
	@rm -rf *.test

clean:
	rm -r move protect.so