CC=gcc
CFLAGS=-O0 -g -Wall -Wextra -Werror
.RECIPEPREFIX=:
DESTDIR ?= /usr
BIN ?= bin
ECHO_FAILED=echo -e "\033[31mFAILED\033[0m"
ECHO_PASSED=echo -e "\033[32mPASSED\033[0m"

.PHONY: clean install

all: clean range

range: range.o

clean:
:		rm -f *~ *.o range

install: range
:               install -D range $(DESTDIR)/$(BIN)/range

TEST_TEMPLATE=@echo -n "Running $(4)... "; \
              gdb --batch --quiet -x $(1) ./range 2>/dev/null | grep -oP "@@@\K.*" > $(2); \
	      cmp $(2) $(3) && $(ECHO_PASSED) || $(ECHO_FAILED); \
	      rm $(2)

test:
:             $(call TEST_TEMPLATE,task1.gdb,task1_test.txt,task1_answer.txt,test1)
:             $(call TEST_TEMPLATE,task2.gdb,task2_test.txt,task2_answer.txt,test2)
