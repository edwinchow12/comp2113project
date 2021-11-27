#include <iostream>
#include <stack>
#include <stdio.h>
#include "maze.h"
#include <fstream>
#include <random>
#include <unistd.h>


std::ofstream file; //Game logs
Maze *maze = new Maze;
void Cell::cell_init(int _x, int _y)
{
    x = _x;
    y = _y;
    top_wall = true;
    bottom_wall = true;
    left_wall = true;
    right_wall = true;
}

bool Cell::isAllWallsUp()
{
    if (!top_wall || !bottom_wall || !left_wall || !right_wall){
        return false;
    } 
    else return true;
}

//Update cells to the correspoding walls variable 
void Cell::update()
{
    maze->walls.rows[y].rowHorizontal[x] = top_wall;
    maze->walls.rows[y+ 1].rowHorizontal[x]= bottom_wall;
    maze->walls.rows[y].rowVertical[x] = left_wall;
    maze->walls.rows[y].rowVertical[x + 1] = right_wall;
}

void Maze::walls_init()
{
    for (int i = 0; i < MAZE_SIZE; i++)
    {
        for (int j = 0; j < MAZE_SIZE; j++)
        {
            walls.rows[i].rowHorizontal[j] = true;
            walls.rows[i].rowVertical[j] = true;
        }
        walls.rows[i].rowVertical[MAZE_SIZE] = true;
    }
    for (int i = 0; i < MAZE_SIZE; i++){
        walls.rowFinal[i] = true;
    }
    
}
//Cell cells[MAZE_SIZE][MAZE_SIZE];
void Maze::maze_init()
{
    for (int i = 0; i < MAZE_SIZE; i++)
    {
        for (int j = 0; j < MAZE_SIZE; j++)
        {
            cells[i][j].cell_init(i, j);
            file << "Cell " << i << " " << j << " initialised " << cells[i][j].x << cells[i][j].y << std::endl;
        }
    }
}

std::random_device randomNum; //Random Number Device Declaration
int rdNum;
//std::stack<Cell> Stack;
void Maze::DFS(Cell &current)
{
    //Check if there is neighbour cells with all walls up
    if (Stack.empty())
    {
        return;
    }
    if (
        /*
        Detect if there are neighbour cells with all walls up
        if the cell is a boundary cell, that part will return false automatically
        So tenary operators are used
        */
        (current.x != MAZE_SIZE - 1 ? maze->cells[current.x + 1][current.y].isAllWallsUp() : false) ||
        (current.y != MAZE_SIZE - 1 ? maze->cells[current.x][current.y + 1].isAllWallsUp() : false) ||
        (current.x != 0 ? maze->cells[current.x - 1][current.y].isAllWallsUp() : false) ||
        (current.y != 0 ? maze->cells[current.x][current.y - 1].isAllWallsUp() : false))
    {

        file << "\n" << current.x << " " << current.y << " " << "pushed" << std::endl;
        printf("\033c");
        std::cout << current.x << " " << current.y << " Stack length: " << Stack.size() << std::endl;
        Maze::print(current.x, current.y, true); //Print current plain
        usleep(TIME);
        Cell * next;
        
        //Generate random numbers
        //It will continue looping if the number of the corresponding neighbour cell does not have all walls up
        do { 
            rdNum = randomNum() % 4;
            file << "random code = " << rdNum << std::endl;
        } while (
            (!maze->cells[current.x + 1][current.y].isAllWallsUp() && rdNum == 3) ||
            (!maze->cells[current.x][current.y + 1].isAllWallsUp() && rdNum == 1) ||
            (!maze->cells[current.x - 1][current.y].isAllWallsUp() && rdNum == 2) ||
            (!maze->cells[current.x][current.y - 1].isAllWallsUp() && rdNum == 0) ||

            //Handle boundary cases of movements 
            ((current.x == 0) && (rdNum == 2)) ||
            ((current.x == MAZE_SIZE - 1) && (rdNum == 3)) ||
            ((current.y == 0) && (rdNum == 0)) ||
            ((current.y == MAZE_SIZE - 1) && (rdNum == 1))
        );
        
        switch (rdNum)
        {
        case 0: //Move Up
            next = &cells[current.x][current.y - 1];
            current.top_wall = false;
            next->bottom_wall = false;
            break;
        case 1: //Move Down
            next = &cells[current.x][current.y + 1];
            current.bottom_wall = false;
            next->top_wall = false;
            break;
        case 2: //Move Left
            next = &cells[current.x - 1][current.y];
            current.left_wall = false;
            next->right_wall = false;
            break;
        case 3: //Move Right
            next = &cells[current.x + 1][current.y];
            current.right_wall = false;
            next->left_wall = false;
            break;
        default:
            break;
        }

        //Update cells to the walls variable 
        current.update();
        next->update();
        Stack.push(current);
        file << "Stack " << Stack.top().x << " " << Stack.top().y << std::endl;
        DFS(*next);
    }
    else
    {
        file << "Popping the top item on the stack..." << std::endl;
        Cell previous = Stack.top();
        Stack.pop();
        DFS(previous);
    }
}

//bool walls[MAZE_SIZE + 1][MAZE_SIZE + 1];
void Maze::print(int x, int y, bool flag)
{
    for (int j = 0; j < MAZE_SIZE * 2 + 1; j++)
    {
        if (j % 2 != 0)
        {
            for (int i = 0; i < MAZE_SIZE * 2 + 1; i++)
            {
                if (i % 2 == 0)
                {
                    
                    if (maze->walls.rows[int(j/2)].rowVertical[int(i/2)]){
                        std::cout << "#";
                    } else {
                        std::cout << " ";
                    }
                }
                else
                {
                    std::cout << " "; //Cells
                }
            }
            std::cout << std::endl;
        }
        else
        {
            for (int i = 0; i < MAZE_SIZE * 2 + 1; i++)
            {
                if (i % 2 == 0)
                {
                    std::cout << "#"; //Const blocks
                }
                else
                {
                    if (maze->walls.rows[int(j/2)].rowHorizontal[int(i/2)]){
                        std::cout << "#";
                    } else {
                        std::cout << " ";
                    }
                }
            }
            std::cout << std::endl;
        }
    }
}
void Maze::generate()
{
    file << "Start generating maze..." << std::endl;
    Cell start;
    start.cell_init(5, 5);
    Stack.push(start);
    DFS(start);
}
void Maze::init()
{
    maze_init();
    walls_init();
    generate();
}
void Maze::run()
{
    init();
    printf("\033c");
    print(0,0, false);
}

int main()
{
    file.open("../logs/maze_logs.txt");
    
    maze->run();
    delete maze;
    file.close();
    return 0;
}