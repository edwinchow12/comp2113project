#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <stack>

class Cell;
class Maze;

#define MAZE_SIZE 30
#define TIME 50000


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
public:
    int x, y;
    bool top_wall, bottom_wall, left_wall, right_wall;
    void cell_init(int, int);
    bool isAllWallsUp();
    void update();
};

class Maze
{
private:
    std::stack<Cell> Stack;
    
    void walls_init();
    void maze_init();
    void DFS(Cell&);

public:
    Walls walls;
    Cell cells[MAZE_SIZE][MAZE_SIZE];
    void print(int, int, bool);
    void generate();
    void init();
    void run();
};

#endif