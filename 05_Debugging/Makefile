CC=gcc
CFLAGS=-O0 -g -Wall -Wextra -Werror
.RECIPEPREFIX=:
DESTDIR ?= /usr
BIN ?= bin

.PHONY: clean install

all: clean range

range: range.o

clean:
:		rm -f *~ *.o range

install: range
:               install -D range $(DESTDIR)/$(BIN)/range

TEST_TEMPLATE=gdb --batch --quiet -x $(1) ./range 2>/dev/null | grep -oP "@@@\K.*" > $(2); \
	      cmp $(2) $(3) && echo "SUCCESS" || echo "FAILED"; \
	      rm $(2)

test:
:             $(call TEST_TEMPLATE,task1.gdb,task1_test.txt,task1_answer.txt)
:             $(call TEST_TEMPLATE,task2.gdb,task2_test.txt,task2_answer.txt)
