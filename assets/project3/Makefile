CFLAGS = -Wall -g -std=c++17
INCLUDES = -I./b-tree -I./provided_code

default: all

all: test1 test2 test3 test4 test_bed

test1: simple_test.cpp
	$(CXX) $(CFLAGS) $(INCLUDES) -o test1 simple_test.cpp

test2: right_degenerate_test.cpp
	$(CXX) $(CFLAGS) $(INCLUDES) -o test2 right_degenerate_test.cpp

test3: left_degenerate_test.cpp
	$(CXX) $(CFLAGS) $(INCLUDES) -o test3 left_degenerate_test.cpp

test4: update_test.cpp
	$(CXX) $(CFLAGS) $(INCLUDES) -o test4 update_test.cpp

test_bed: test_bed.cpp
	$(CXX) $(CFLAGS) $(INCLUDES) -o test_bed test_bed.cpp


.PHONY: all clean

clean:
	-rm -rf *.o
	-rm -f test1
	-rm -f test2
	-rm -f test3
	-rm -f test4
	-rm -f test_bed
