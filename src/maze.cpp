#include <iostream>
#include <stack>
#include <stdio.h>
#include "maze.h"
#include <fstream>
#include <random>
#include <unistd.h>
#include <vector>
#include <ctime>

void Cell::cell_init(int _x, int _y, Maze *_m)
{
    x = _x;
    y = _y;
    top_wall = true;
    bottom_wall = true;
    left_wall = true;
    right_wall = true;
    m = _m;
}

// Return true if all the walls of the cell is up
bool Cell::isAllWallsUp()
{
    if (!top_wall || !bottom_wall || !left_wall || !right_wall)
    {
        return false;
    }
    else
        return true;
}

// Update cells to the correspoding walls variable
void Cell::update()
{
    m->walls.rows[y].rowHorizontal[x] = top_wall;
    m->walls.rows[y + 1].rowHorizontal[x] = bottom_wall;
    m->walls.rows[y].rowVertical[x] = left_wall;
    m->walls.rows[y].rowVertical[x + 1] = right_wall;
}

// Initialise the walls variables
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
    for (int i = 0; i < MAZE_SIZE; i++)
    {
        walls.rowFinal[i] = true;
    }
}
// Cell cells[MAZE_SIZE][MAZE_SIZE];
void Maze::maze_init()
{
    for (int i = 0; i < MAZE_SIZE; i++)
    {
        for (int j = 0; j < MAZE_SIZE; j++)
        {
            cells[i][j].cell_init(i, j, this);
            this->log << "Cell Initialisation: " << i << " " << j << " initialised " << std::endl;
        }
    }
}

void Maze::DFS(Cell &current)
{
    // Check if there is neighbour cells with all walls up
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
        (current.x != MAZE_SIZE - 1 ? this->cells[current.x + 1][current.y].isAllWallsUp() : false) ||
        (current.y != MAZE_SIZE - 1 ? this->cells[current.x][current.y + 1].isAllWallsUp() : false) ||
        (current.x != 0 ? this->cells[current.x - 1][current.y].isAllWallsUp() : false) ||
        (current.y != 0 ? this->cells[current.x][current.y - 1].isAllWallsUp() : false))
    {

        this->log << "DFS: Processing cell " << current.x << " " << current.y << "..." << std::endl;
        printf("\033c");
        std::cout << current.x << " " << current.y << " Stack length: " << Stack.size() << std::endl;
        Maze::print(); // Print current plain
        usleep(TIME);
        Cell *next;

        // Generate random numbers
        // It will continue looping if the number of the corresponding neighbour cell does not have all walls up
        do
        {
            rdNum = randomNum() % 4;
            this->log << "Random code = " << rdNum << std::endl;
        } while (
            (!this->cells[current.x + 1][current.y].isAllWallsUp() && rdNum == 3) ||
            (!this->cells[current.x][current.y + 1].isAllWallsUp() && rdNum == 1) ||
            (!this->cells[current.x - 1][current.y].isAllWallsUp() && rdNum == 2) ||
            (!this->cells[current.x][current.y - 1].isAllWallsUp() && rdNum == 0) ||

            // Handle boundary cases of movements
            ((current.x == 0) && (rdNum == 2)) ||
            ((current.x == MAZE_SIZE - 1) && (rdNum == 3)) ||
            ((current.y == 0) && (rdNum == 0)) ||
            ((current.y == MAZE_SIZE - 1) && (rdNum == 1)));

        switch (rdNum)
        {
        case 0: // Move Up
            next = &cells[current.x][current.y - 1];
            current.top_wall = false;
            next->bottom_wall = false;
            break;
        case 1: // Move Down
            next = &cells[current.x][current.y + 1];
            current.bottom_wall = false;
            next->top_wall = false;
            break;
        case 2: // Move Left
            next = &cells[current.x - 1][current.y];
            current.left_wall = false;
            next->right_wall = false;
            break;
        case 3: // Move Right
            next = &cells[current.x + 1][current.y];
            current.right_wall = false;
            next->left_wall = false;
            break;
        default:
            break;
        }

        // Update cells to the walls variable
        current.update();
        next->update();
        Stack.push(current);
        this->log << "Stack updated: " << Stack.top().x << " " << Stack.top().y << " pushed" << std::endl;
        DFS(*next);
    }
    else
    {
        Cell previous = Stack.top();
        Stack.pop();
        this->log << "Stack updated: " << previous.x << " " << previous.y << " popped" << std::endl;
        DFS(previous);
    }
}

void Maze::print()
{
    for (int j = 0; j < MAZE_SIZE * 2 + 1; j++)
    {
        if (j % 2 != 0)
        {
            for (int i = 0; i < MAZE_SIZE * 2 + 1; i++)
            {
                if (i % 2 == 0)
                {
                    if (this->walls.rows[int(j / 2)].rowVertical[int(i / 2)])
                    {
                        std::cout << WALL_CHAR;
                    }
                    else
                    {
                        std::cout << BLANK_CHAR;
                    }
                }
                else
                {
                    std::cout << BLANK_CHAR; // Cells
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
                    std::cout << WALL_CHAR; // Const blocks
                }
                else
                {
                    if (this->walls.rows[int(j / 2)].rowHorizontal[int(i / 2)])
                    {
                        std::cout << WALL_CHAR;
                    }
                    else
                    {
                        std::cout << BLANK_CHAR;
                    }
                }
            }
            std::cout << std::endl;
        }
    }
}

// Initial function to generate the maze
void Maze::generate()
{
    this->log << "Start generating maze..." << std::endl;
    Cell start;
    start.cell_init(randomNum() % (MAZE_SIZE + 1), randomNum() % (MAZE_SIZE + 1), this);
    Stack.push(start);
    DFS(start);
}

// Maze generation function
void Maze::init()
{
    maze_init();
    walls_init();
    generate();
    this->log << "Maze generation completed." << std::endl;
}

// Output generated maze to the two-dimensional vector for playing the maze
void Maze::writeToPlain()
{
    std::vector<bool> temp;
    for (int j = 0; j < MAZE_SIZE * 2 + 1; j++)
    {
        temp.clear();
        if (j % 2 != 0)
        {
            for (int i = 0; i < MAZE_SIZE * 2 + 1; i++)
            {
                if (i % 2 == 0)
                {
                    if (this->walls.rows[int(j / 2)].rowVertical[int(i / 2)])
                    {
                        temp.push_back(false);
                    }
                    else
                    {
                        temp.push_back(true);
                    }
                }
                else
                {
                    temp.push_back(true); // Cells
                }
            }
            gamePlain.push_back(temp);
        }
        else
        {
            for (int i = 0; i < MAZE_SIZE * 2 + 1; i++)
            {
                if (i % 2 == 0)
                {
                    temp.push_back(false); // Const blocks
                }
                else
                {
                    if (this->walls.rows[int(j / 2)].rowHorizontal[int(i / 2)])
                    {
                        temp.push_back(false);
                    }
                    else
                    {
                        temp.push_back(true);
                    }
                }
            }
            gamePlain.push_back(temp);
        }
    }
}

// Prints the game plain each time while playing the maze
void Maze::printGamePlain(int x, int y)
{
    for (int j = 0; j < gamePlain.size(); j++)
    {
        for (int i = 0; i < gamePlain[j].size(); i++)
        {
            if (x == i && y == j)
                std::cout << PLAYER_CHAR;
            else if (i == destination_x && j == destination_y)
                std::cout << DESTINATION_CHAR;
            else
                std::cout << (gamePlain[j][i] ? BLANK_CHAR : WALL_CHAR);
        }
        std::cout << std::endl;
    }
}

// Overall function for playing the maze
void Maze::play()
{
    char input;
    int current_x = 1;
    int current_y = 1;
    writeToPlain();
    while (!((current_x == destination_x) && (current_y == destination_y)))
    {
        printGamePlain(current_x, current_y);
        system("stty raw");
        std::cin >> input;
        system("stty cooked");
        switch (input)
        {
        case 'w':
            if (gamePlain[current_y - 1][current_x])
                current_y--;
            break;
        case 'a':
            if (gamePlain[current_y][current_x - 1])
                current_x--;
            break;
        case 's':
            if (gamePlain[current_y + 1][current_x])
                current_y++;
            break;
        case 'd':
            if (gamePlain[current_y][current_x + 1])
                current_x++;
            break;
        default:
            break;
        }
        printf("\033c");
    }
    std::cout << "You win!" << std::endl;
}

// Running the maze
void Maze::run()
{
    this->log.open("../logs/maze_generation_logs.txt");
    init();
    this->log << "Initialisation completed." << std::endl;
    printf("\033c");
    play();
    this->log.close();
}

// For testing only
/*int main()
{
    Maze *maze = new Maze;
    maze->run();
    delete maze;
    return 0;
}*/
