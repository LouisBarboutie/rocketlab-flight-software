COMPILE_FLAGS = -Wall -Wextra -Wpedantic -Wconversion

TestBinarySearch: TestBinarySearch.o BinarySearch.o
	g++ $(COMPILE_FLAGS) build/TestBinarySearch.o build/BinarySearch.o -o build/TestBinarySearch

TestBinarySearch.o: TestBinarySearch.cpp
	g++ $(COMPILE_FLAGS) -c TestBinarySearch.cpp -o build/TestBinarySearch.o

BinarySearch.o: BinarySearch.cpp
	g++ $(COMPILE_FLAGS) -c BinarySearch.cpp -o build/BinarySearch.o 

TestInterpolate: TestInterpolate.o Interpolate.o
	g++ $(COMPILE_FLAGS) build/TestInterpolate.o build/Interpolate.o -o build/TestInterpolate

TestInterpolate.o: TestInterpolate.cpp
	g++ $(COMPILE_FLAGS) -c TestInterpolate.cpp -o build/TestInterpolate.o

Interpolate.o: Interpolate.cpp
	g++ $(COMPILE_FLAGS) -c Interpolate.cpp -o build/Interpolate.o 

TestCalculatePressure: TestCalculatePressure.o CalculatePressure.o Interpolate.o BinarySearch.o
	g++ $(COMPILE_FLAGS) build/TestCalculatePressure.o build/CalculatePressure.o build/Interpolate.o build/BinarySearch.o -o build/TestCalculatePressure

TestCalculatePressure.o: TestCalculatePressure.cpp
	g++ $(COMPILE_FLAGS) -c TestCalculatePressure.cpp -o build/TestCalculatePressure.o

CalculatePressure.o: CalculatePressure.cpp
	g++ $(COMPILE_FLAGS) -c CalculatePressure.cpp -o build/CalculatePressure.o
clean :
	rm -rf build/*

