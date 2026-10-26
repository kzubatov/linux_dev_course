CC=gcc
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

