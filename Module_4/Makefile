CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=calc.cpp gcd.cpp lcm.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=calc

.PHONY: clean

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)