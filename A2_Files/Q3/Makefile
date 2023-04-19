compiler = g++
flags = -pedantic-errors -std=c++11

all: main3

d2boh.o: d2boh.cpp d2boh.h
	$(compiler) $(flags) -c d2boh.cpp -o d2boh.o

main3.o: main3.cpp d2boh.h
	$(compiler) $(flags) -c main3.cpp -o main3.o

main3: d2boh.o main3.o
	$(compiler) $(flags) d2boh.o main3.o -o main3

clean:
	rm -f main3 main3.o d2boh.o
