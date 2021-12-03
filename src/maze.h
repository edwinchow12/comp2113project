#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <stack>
#include <vector>
#include <fstream>

class Cell;
class Maze;

#define MAZE_SIZE 10
#define TIME 10000
#define WALL_CHAR "●"
#define BLANK_CHAR " "
#define PLAYER_CHAR "@"
#define DESTINATION_CHAR "D"
#define destination_x (MAZE_SIZE * 2 - 1)
#define destination_y (MAZE_SIZE * 2 - 1)

class Maze;

struct rowGroup
{
    bool rowHorizontal[MAZE_SIZE];
    bool rowVertical[MAZE_SIZE + 1];
};

struct Walls
{
    rowGroup rows[MAZE_SIZE];
    bool rowFinal[MAZE_SIZE];
};

class Cell
{
private:
    Maze *m; //Maze pointer object to point to the current maze game

public:
    int x, y; //Coordinates of the cell
    bool top_wall, bottom_wall, left_wall, right_wall; //Walls of the cell
    void cell_init(int, int, Maze *); //Initialisation of the cell
    bool isAllWallsUp(); //Return true if all the walls of the cell are up
    void update(); //Update current cell walls status to the maze walls variable 
};

class Maze
{
private:
    std::stack<Cell> Stack; //Stack object for storing cells in DFS
    Cell cells[MAZE_SIZE][MAZE_SIZE]; //Cell plain
    std::vector<std::vector<bool> > gamePlain;
    void walls_init(); //Initialisation of the walls
    void maze_init(); //Initialisation of the maze
    void DFS(Cell &); //Recurring function for implementing Depth-First Search for generating the maze
    void print(); //Prints the game plain 
    void generate(); //Starting function of DFS
    void init(); //Overall initialisation of maze
    void play();
    void printGamePlain(int, int);
public:
    std::ofstream log; //Game logs
    Walls walls; //Walls variable
    void writeToPlain();

    void run(); //Running the maze
};

#endif