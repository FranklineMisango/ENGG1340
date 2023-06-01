CXX = g++
CXXFLAGS = -pedantic-errors -std=c++11

all: alien

alien: alien.o
	$(CXX) $(CXXFLAGS) $^ -o $@

alien.o: alien.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o alien
