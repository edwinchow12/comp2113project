FLAGS = -pedantic-errors -std=c++11

mathematics.o: ./src/mathematics.cpp ./src/mathematics.h
	g++ $(FLAGS) $< -c

pacman.o: ./src/pacman.cpp ./src/pacman.h
	g++ $(FLAGS) $< -c

maze.o: ./src/maze.cpp ./src/maze.h
	g++ $(FLAGS) $< -c 

filehandler.o: ./src/filehandler.cpp ./src/filehandler.h
	g++ $(FLAGS) $< -c

main.o: ./src/main.cpp
	g++ $(FLAGS) $< -c

main: ./src/main.o ./src/filehandler.o ./src/mathematics.o ./src/pacman.o ./src/maze.o  
	g++ $(FLAGS) $^ -o ./bin/main

clean:
	rm ./src/main.o ./src/mathematics.o ./src/pacman.o ./src/maze.o ./src/filehandler.o ./bin/main

.PHONY: clean
