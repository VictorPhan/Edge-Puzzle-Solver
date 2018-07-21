make:
	g++ -c piece.cpp -o piece.o -std=c++11 -O3 -Wall -Wextra -Werror
	g++ -c main.cpp -o main.o -std=c++11 -O3 -Wall -Wextra -Werror
	g++ piece.o main.o -o main -std=c++11 -O3 -Wall -Wextra -Werror