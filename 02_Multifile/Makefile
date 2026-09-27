.RECIPEPREFIX=:
GENERATES = prog README
TRASH = *.o *~ o.*

%.o:    %.c
:       cc $< -c -o $@

all:    README prog

prog:   const.o fun.o prog.o
:       cc $^ -o $@

fun.o:  outlib.h

README: prog
:       ./$< 2> $@

clean:
:       rm -f $(TRASH)

distclean:      clean
:       rm -rf $(GENERATES)
