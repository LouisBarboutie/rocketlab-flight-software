TestBinarySearch: TestBinarySearch.o BinarySearch.o
	g++ build/TestBinarySearch.o build/BinarySearch.o -o TestBinarySearch

TestBinarySearch.o: TestBinarySearch.cpp
	g++ -c TestBinarySearch.cpp -o build/TestBinarySearch.o

BinarySearch.o: BinarySearch.cpp
	g++ -c BinarySearch.cpp -o build/BinarySearch.o 

clean :
	rm -rf build/

