CC=gcc
.RECIPEPREFIX=:
BUILDROOT ?= /usr
BIN ?= bin

.PHONY: clean install

Show: Show.c
:   $(CC) Show.c -Wall -Wextra -O0 -o Show -lncursesw

clean:
:		rm -f *~ *.o Show

install: Show
:               install -D Show $(BUILDROOT)/$(BIN)/Show

