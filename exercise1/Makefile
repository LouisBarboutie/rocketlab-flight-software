TestBinarySearch: TestBinarySearch.o BinarySearch.o
	g++ build/TestBinarySearch.o build/BinarySearch.o -o TestBinarySearch

TestBinarySearch.o: TestBinarySearch.cpp
	g++ -c TestBinarySearch.cpp -o build/TestBinarySearch.o

BinarySearch.o: BinarySearch.cpp
	g++ -c BinarySearch.cpp -o build/BinarySearch.o 

TestInterpolate: TestInterpolate.o Interpolate.o
	g++ build/TestInterpolate.o build/Interpolate.o -o TestInterpolate

TestInterpolate.o: TestInterpolate.cpp
	g++ -c TestInterpolate.cpp -o build/TestInterpolate.o

Interpolate.o: Interpolate.cpp
	g++ -c Interpolate.cpp -o build/Interpolate.o 

clean :
	rm -rf build/*

