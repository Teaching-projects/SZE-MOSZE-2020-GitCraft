SHELL:= /bin/bash

OBJS := main.o player.o parser.o
CFLAGS := -Wall
CC := g++

build: $(OBJS)
	$(CC) $(CFLAGS) -o main $(OBJS)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

player.o: player.cpp
	$(CC) $(CFLAGS) -c player.cpp

parser.o: parser.cpp
	$(CC) $(CFLAGS) -c parser.cpp

documentation:
	doxygen doxconfig

test:
	bash -c "chmod +x test.sh"
	bash -c "./test.sh main output.txt"

io-diff-tests:
	bash -c "diff output.txt good_output.txt"

static-code-analysis:
	bash -c "chmod +x run_cppcheck.sh"
	bash -c "./run_cppcheck.sh"

memory-leak-check:
	bash -c "chmod +x run_valgrind_check.sh"
	bash -c "./run_valgrind_check.sh"

parser-tests:
	bash -c "cd /usr/src/gtest && sudo cmake CMakeLists.txt && sudo make"
	bash -c "sudo ln -st /usr/lib/ /usr/src/gtest/libgtest.a && sudo ln -st /usr/lib/ /usr/src/gtest/libgtest_main.a"
	bash -c "cd unit_test && cmake CMakeLists.txt"
	bash -c "cd unit_test && make"
	bash -c "cd unit_test && ./test_parser"

clean:
	rm -fr *.o main ./html ./latex
