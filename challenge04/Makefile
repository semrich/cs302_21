CXX=		g++
CXXFLAGS=	-g -Wall -std=gnu++11
SHELL=		bash

all:		solution

solution:	solution.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f solution

.PHONY:		test

test:	solution
	@echo Testing output...
	@diff --suppress-common-lines -y <(./solution < input) output

