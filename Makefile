Base360: Base360.o test.o
	g++ Base360.o test.o -o Base360

Base360.o: Base360.cpp
	g++ -c Base360.cpp

test.o: test.cpp
	g++ -c test.cpp

clean:
	rm *.o
	rm base360.exe