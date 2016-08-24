
GTEST_DIR=../thirdparty/gtest

CXXFLAGS=-std=c++14 -I../thirdparty -I../firmware -I$(GTEST_DIR)
LDFLAGS=-pthread

SRC = $(shell find . -name '*.cpp') $(GTEST_DIR)/gmock-gtest-all.cpp $(GTEST_DIR)/gtest-main.cpp
OBJ=$(SRC:%.cpp=%.o)


%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $< -c -o $@

one: $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJ) -o test.app

run: one
	./test.app

all: clean
all: run


.PHONY: clean

clean:
	$(RM) $(GTEST_DIR)/*.o */*.o *.o *~ test.app

