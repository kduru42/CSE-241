all: hw4
	./hw4 >> test.txt

hw4: DayOfYear.o main.o
	g++ main.o DayOfYear.o -o hw4

DayOfYear.o: DayOfYear.cpp
	g++ -std=c++11 -c DayOfYear.cpp

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

clean:
	rm -rf DayOfYear.o
	rm -rf main.o

fclean: clean
	rm -rf hw4

re: fclean all