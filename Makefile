all:
	g++ -g main.cpp -Wall -ansi -pedantic -std=c++20 -o project1 && ./project1

clean:
	rm project1