CXX = g++
CXXFLAGS = -pedantic-errors -std=c++11

SOURCES = alien.cpp
EXEC = $(SOURCES:.c++)

all: $(EXEC)

%: %.o
	$(CXX) $(CXXFLAGS) $^ -o $@

alien.o: alien.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o alien

.PHONY:all clean
