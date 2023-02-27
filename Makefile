main: main.o
	g++ -o main main.o

main.o: main.cpp

clean:
	rm -f *.o
