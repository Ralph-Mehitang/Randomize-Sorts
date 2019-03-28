all:main.o

main.o:main.cpp

	g++ -std=c++17 -Wall -g	main.cpp

clean:
	rm -rf *o
