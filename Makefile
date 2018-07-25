make:
	g++ -c algorithm.cpp -o algorithm.o -std=c++11 -O3 -Wall -Wextra
	g++ -c piece.cpp -o piece.o -std=c++11 -O3 -Wall -Wextra
	g++ -c board.cpp -o board.o -std=c++11 -O3 -Wall -Wextra
	g++ -c main.cpp -o main.o -std=c++11 -O3 -Wall -Wextra
	g++ algorithm.o piece.o board.o main.o -o main -std=c++11 -O3 -Wall -Wextra