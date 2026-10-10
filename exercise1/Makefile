TestBinarySearch: TestBinarySearch.o BinarySearch.o
	g++ build/TestBinarySearch.o build/BinarySearch.o -o build/TestBinarySearch

TestBinarySearch.o: TestBinarySearch.cpp
	g++ -c TestBinarySearch.cpp -o build/TestBinarySearch.o

BinarySearch.o: BinarySearch.cpp
	g++ -c BinarySearch.cpp -o build/BinarySearch.o 

TestInterpolate: TestInterpolate.o Interpolate.o
	g++ build/TestInterpolate.o build/Interpolate.o -o build/TestInterpolate

TestInterpolate.o: TestInterpolate.cpp
	g++ -c TestInterpolate.cpp -o build/TestInterpolate.o

Interpolate.o: Interpolate.cpp
	g++ -c Interpolate.cpp -o build/Interpolate.o 

TestCalculatePressure: TestCalculatePressure.o CalculatePressure.o Interpolate.o BinarySearch.o
	g++ build/TestCalculatePressure.o build/CalculatePressure.o build/Interpolate.o build/BinarySearch.o -o build/TestCalculatePressure

TestCalculatePressure.o: TestCalculatePressure.cpp
	g++ -c TestCalculatePressure.cpp -o build/TestCalculatePressure.o

CalculatePressure.o: CalculatePressure.cpp
	g++  -c CalculatePressure.cpp -o build/CalculatePressure.o
clean :
	rm -rf build/*

