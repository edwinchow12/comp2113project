#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <chrono>

#include "filehandler.h"
#include "maze.h"
#include "mathematics.h"
#include "pacman.h"

using namespace std;

//Prints the input file until the separator '!'
//key refers to which key the user presses to continue 
//needWait is false if just prints out the texts but no need to wait for input
void waitForInput(ifstream &fileobj, char key, bool needWait)
{
    char dummy;
    string temp;

    while (getline(fileobj, temp) && temp != "!")
    {
        cout << temp << endl;
    }

    dummy = ' ';
    system("stty raw");
    if (needWait)
        while (dummy != key)
        {
            cin >> dummy;
        }
    system("stty cooked");
}

int main()
{

    Player player;
    ofstream log;
    ifstream FileObj;
    string temp;

    chrono::time_point<chrono::system_clock> start, end;

    char dummy;
    int choice;

    
    log.open("../logs/log.txt");
    printf("\033c");
    cout << "The Stellians - Exploration" << endl;

    FileObj.open("../dialogues/Entry.txt");
    waitForInput(FileObj, 'k', true);

    printf("\033c");
    do
    {
        printf("1. Load game\n2. New game\n");
        cin >> choice;
        if (choice == 1)
        {
            do
            {
                printf("Enter username: ");
                cin >> player.name;
            } while (!LoadUser(&player));
        }
        if (choice == 2)
        {
            printf("Create new user\n");
            CreateNewUser(&player);
        }
    } while (choice != 1 && choice != 2);

    waitForInput(FileObj, ' ', false);
    FileObj.close();

    //----------------------------------------------------

    //The games will be separated with ---- like the above one
    if (player.planet == "Mathematics")
    {
        int numTimesUsed;
        printf("\033c");
        FileObj.open("../dialogues/Mathematics.txt");
        waitForInput(FileObj, 'y', true);
        waitForInput(FileObj, 's', true);
        try
        {
            log << "The user started playing Guess The Number" << endl; //Write to logs
            GuessTheNumber *guessTheNumber = new GuessTheNumber; // Declaration of pointer game object
            numTimesUsed = guessTheNumber->run(); // The time used for the player to guess the number is returned
            delete guessTheNumber;
            log << "The user finished playing Guess The Number" << endl;
        }
        catch (exception)
        {
            log << "Error occurred while playing Guess The Number";
        }

        //Calculate the number of power dusts
        if (numTimesUsed < 5) player.numPowerDusts += 100; 
        else if (numTimesUsed < 10) player.numPowerDusts += 50;
        cout << "You have " << player.numPowerDusts << " power dusts now." << endl;
        waitForInput(FileObj, 's', true);

        SaveProcess(&player);
        int isWin;
        try
        {
            
            log << "The user started playing PeacefulWar" << endl;
            start = chrono::system_clock::now();
            PeacefulWar *peacefulWar = new PeacefulWar;
            isWin = peacefulWar->run();
            delete peacefulWar;
            end = chrono::system_clock::now();
            log << "The user finished playing PeacefulWar" << endl;
        }
        catch (exception)
        {
            log << "Error occurred while playing PeacefulWar";
        }

        int sec = chrono::duration_cast<chrono::seconds>(end - start).count();
        if (isWin == 0){
        if (0 <= sec && sec <= 30)
            player.numPowerDusts += 100;
        else if (30 <= sec && sec <= 60)
            player.numPowerDusts += 50;
        else
            player.numPowerDusts += 20;
        }
        cout << "You have " << player.numPowerDusts << " power dusts now." << endl;

        waitForInput(FileObj, 'c', true);
        FileObj.close();
        player.planet = "Pacman";
        SaveProcess(&player);
    }
    //----------------------------------------------------
    if (player.planet == "Pacman")
    {
        int isWin; // 1 = lose and 0 = win
        printf("\n");
        FileObj.open("../dialogues/Pacman.txt");
        waitForInput(FileObj, 'y', true);
        waitForInput(FileObj, 's', true);
        try
        {
            printf("\033c");
            log << "The user started playing Pacman" << endl;
            start = chrono::system_clock::now(); // record them time when the player starts playing
            Pacman *pacman = new Pacman;
            isWin = pacman->play(); // 1 is returned for losing cases, 0 is returned for winning cases
            delete pacman;
            end = chrono::system_clock::now(); // record the time when the player ends playing
            log << "The user finished playing Pacman" << endl;
        }
        catch (exception)
        {
            log << "Error occurred while playing Pacman";
        }

        int sec = chrono::duration_cast<chrono::seconds>(end - start).count(); // Calculate the time the player needed to play the game
        if (isWin == 0){
            if (0 <= sec && sec <= 30)
                player.numPowerDusts += 100;
            else if (30 <= sec && sec <= 60)
                player.numPowerDusts += 50;
            else
                player.numPowerDusts += 20;
        }
        cout << "You have " << player.numPowerDusts << " power dusts now." << endl;

        waitForInput(FileObj, 'c', true);
        FileObj.close();
        player.planet = "Maze";
        SaveProcess(&player);
    }
    //----------------------------------------------------
    if (player.planet == "Maze")
    {
        printf("\n");
        FileObj.open("../dialogues/Maze.txt");
        waitForInput(FileObj, 's', true);
        try
        {
            log << "The user started playing Maze" << endl;
            start = chrono::system_clock::now(); // record them time when the player starts playing
            Maze *maze = new Maze;
            maze->run();
            delete maze;
            end = chrono::system_clock::now(); // record them time when the player ends playing
        }
        catch (exception)
        {
            log << "Error occurred while playing Maze";
        }
        log << "The user finshed playing Maze" << endl;
        log << "Game ended." << endl;

        int sec = chrono::duration_cast<chrono::seconds>(end - start).count(); // Calculate the time played used to finish the maze

        //Calculate the number of power dusts from the time played
        if (0 <= sec && sec <= 30)
            player.numPowerDusts += 100;
        else if (30 <= sec && sec <= 60)
            player.numPowerDusts += 50;
        else
            player.numPowerDusts += 20;
        cout << "You have " << player.numPowerDusts << " power dusts now." << endl;

        waitForInput(FileObj, 'c', true);
        FileObj.close();
        player.planet = "Finished";
        SaveProcess(&player);
        printf("\n");
        FileObj.open("../dialogues/Ending.txt");
        waitForInput(FileObj, ' ', false);
        FileObj.close();
    }
    return 0;
}
