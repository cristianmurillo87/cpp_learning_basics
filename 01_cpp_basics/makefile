math: multi_compilation.o math_utils.o
	g++ multi_compilation.o math_utils.o -o math

multi_compilation.o: 22_multiple_file_compilation.cpp
	g++ -c 22_multiple_file_compilation.cpp -o multi_compilation.o

math_utils.o: 22_multiple_compilation/math_utils.cpp
	g++ -c 22_multiple_compilation/math_utils.cpp

clean:
	rm *.o math