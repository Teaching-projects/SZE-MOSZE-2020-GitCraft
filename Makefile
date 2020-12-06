SHELL:= /bin/bash

OBJS := main.o character.o JSON.o Hero.o Monster.o Map.o Game.o
CFLAGS := -Wall -std=c++17
CC := g++-9

build: $(OBJS)
	$(CC) $(CFLAGS) -o main $(OBJS)

main.o: main.cpp character.h JSON.h Hero.h Monster.h Game.h
	$(CC) $(CFLAGS) -c main.cpp

character.o: character.cpp character.h JSON.h
	$(CC) $(CFLAGS) -c character.cpp

JSON.o: JSON.cpp JSON.h
	$(CC) $(CFLAGS) -c JSON.cpp

Hero.o: Hero.cpp Hero.h character.h JSON.h Monster.h
	$(CC) $(CFLAGS) -c Hero.cpp

Monster.o: Monster.cpp Monster.h character.h JSON.h Hero.h
	$(CC) $(CFLAGS) -c Monster.cpp

Map.o: Map.cpp Map.h
	$(CC) $(CFLAGS) -c Map.cpp

Game.o: Game.cpp Game.h character.h Hero.h Monster.h Map.h
	$(CC) $(CFLAGS) -c Game.cpp

documentation:
	doxygen doxconfig

test:
	bash -c "chmod +x test.sh"
	bash -c "./test.sh main"

io-diff-tests:
	bash -c "diff output.txt testinput2.txt"

static-code-analysis:
	bash -c "chmod +x run_cppcheck.sh"
	bash -c "./run_cppcheck.sh"

memory-leak-check:
	bash -c "chmod +x run_valgrind_check.sh"
	bash -c "./run_valgrind_check.sh"

parser-tests:
	cd unit_test && cmake CMakeLists.txt
	cd unit_test && make
	cd unit_test && ./test_parser

clean:
	rm -rf *.o main ./html ./latex test_parser CMakeCache.txt cmake_install.cmake libtestCode.a
