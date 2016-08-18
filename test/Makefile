
GTEST_DIR=../thirdparty/gtest

CC=g++
CFLAGS=-std=c++14 -I../thirdparty -I../fw
LDFLAGS=-pthread

SRC = $(shell find . -name '*.cpp') $(GTEST_DIR)/gtest-all.cpp $(GTEST_DIR)/gtest-main.cpp
OBJ=$(SRC:%.cpp=%.o)


%.o: %.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) $< -c -o $@

all: $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o test.app

run: all
	./test.app


.PHONY: clean

clean:
	rm -f $(GTEST_DIR)/*.o */*.o *.o *~ test.app

