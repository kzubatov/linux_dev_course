.RECIPEPREFIX=:
GENERATES = prog prog-a prog-so README test* liboutput*
TRASH = *.o *~ o.*
CFLAGS=-fPIC
ECHO_FAILED=echo -e "\033[31mFAILED\033[0m"
ECHO_PASSED=echo -e "\033[32mPASSED\033[0m"

all:    README prog prog-a prog-so clean distclean test

prog:   const.o fun.o prog.o

prog-a: prog.o liboutput_static.a
:       cc -L. $< -loutput_static  -o $@

prog-so: prog.o liboutput.so
:       cc -L. $< -loutput -o $@

liboutput_static.a: fun.o const.o
:       ar -rsc $@ $^

liboutput.so: fun.o const.o
:       cc -shared $^ -o $@

README: prog
:       ./$< 2> $@

fun.o:  outlib.h

clean:
:       rm -f $(TRASH)

distclean:      clean
:       rm -rf $(GENERATES)

test: test_empty test_one_arg test_three_args

test_empty: prog prog-a prog-so
:       @echo -n "Running empty test "
:       @./prog 2> $@_prog
:       @./prog-a 2> $@_prog_a
:       @LD_LIBRARY_PATH=. ./prog-so 2> $@_prog_so
:       @cmp $@_prog $@_prog_a && cmp $@_prog $@_prog_so && $(ECHO_PASSED) || $(ECHO_FAILED)

test_one_arg: prog prog-a prog-so
:       @echo -n "Running test with ARGUMENT "
:       @./prog > $@_prog ARGUMENT
:       @./prog-a > $@_prog_a ARGUMENT
:       @LD_LIBRARY_PATH=. ./prog-so > $@_prog_so ARGUMENT
:       @cmp $@_prog $@_prog_a && cmp $@_prog $@_prog_so && $(ECHO_PASSED) || $(ECHO_FAILED)

test_three_args: prog prog-a prog-so
:       @echo -n "Running test with ARGUMENT1 ARGUMENT2 ARGUMENT3 "
:       @./prog > $@_prog ARGUMENT1 ARGUMENT2 ARGUMENT3
:       @./prog-a > $@_prog_a ARGUMENT1 ARGUMENT2 ARGUMENT3
:       @LD_LIBRARY_PATH=. ./prog-so > $@_prog_so ARGUMENT1 ARGUMENT2 ARGUMENT3
:       @cmp $@_prog $@_prog_a && cmp $@_prog $@_prog_so && $(ECHO_PASSED) || $(ECHO_FAILED)
