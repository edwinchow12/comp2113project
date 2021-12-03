
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>
#include "mathematics.h"

using namespace std;

// Guess The Number

int GuessTheNumber::run()
{
    int numGuess, numSecret, numUp, numDown, numMid, count;
    count = 0;
    numUp = 100;
    numDown = 1;
    numGuess = -1;
    std::mt19937 randomNum(time(NULL));
    numSecret = randomNum() % 100 + 1;
    while (numGuess != numSecret)
    {
        cout << "Enter the number " << numDown << " to " << numUp << endl;
        cin >> numGuess;
        if (numGuess < numUp && numGuess > numDown)
        {
            if (numGuess > numSecret)
            {
                numUp = numGuess;
            }
            if (numGuess < numSecret)
            {
                numDown = numGuess;
            }
            count++;
        }
    }
    cout << "You win!" << endl;
    return count;
}

// Peaceful War

// Initialize the players' statuses (call by reference)
void PeacefulWar::init(Player &a, Player &b)
{
    a.hp = 4;
    a.defence = 1;
    a.attackers = 0;
    b.hp = 4;
    b.defence = 1;
    b.attackers = 0;
}

void PeacefulWar::print_status(Player a, Player b)
{
    printf("\033c");
    printf("--------------------------------------\n");
    printf("#########################\n");
    printf("# Your HP: %i            #\n", a.hp);
    printf("# Your Walls: %i         #\n", a.defence);
    printf("# Your Attackers: %i     #\n", a.attackers);
    printf("# Enemy's HP: %i         #\n", b.hp);
    printf("# Enemy's Walls: %i      #\n", b.defence);
    printf("# Enemy's Attackers: %i  #\n", b.attackers);
    printf("#########################\n");
}

// Manages the movements by the player or the computer
void PeacefulWar::manageMovements(Player &a, Player &b, bool isPlayerWin)
{
    /*
    ----------LOGIC----------
    If the player has less than 4 health, there will be no choices but to
    increase health until health reaches 4.
    If the player has 4 health, the player can choose to add a defence wall,
    to add an attacker, or to attack, given that there is an attacker.
    If the player chooses to attack, the computer's attacker will be destroyed,
    followed by the defence walls, and health ultimately.

    The computer will build an attacker when the computer has 3 defences
    The computer will continuously attack the player if the computer has 1
    attacker.
    */
    int choice;
    if (isPlayerWin)
    {
        // Player wins
        cout << "You win this round!" << endl;
        if (a.hp < 4)
        {
            a.hp += 1;
            cout << "1 HP has recovered for you" << endl;
        }
        else
        {
            cout << "Choose to add a defence or attack (0 to add a defence wall, 1 to add an attacker, 2 to attack" << endl;
            cin >> choice;
            // Detection for invalid value(s)
            while (!(choice >= 0 && choice <= 2))
            {
                cout << "Please enter a valid value!" << endl;
                cin >> choice;
            }
            // If the player chooses to attack without an attacker
            if (a.attackers == 0)
            {
                while (choice == 2)
                {
                    cout << "You don't have an attacker. Please chooce again." << endl;
                    cin >> choice;
                }
            }
            switch (choice)
            {
            case 0:
            {
                // Player builds defence wall
                a.defence += 1;
                break;
            }
            case 1:
            {
                // Player builds attacker
                a.attackers += 1;
                break;
            }
            case 2:
            {
                // Player attacks
                if (b.attackers > 0)
                {
                    b.attackers -= 1;
                }
                else if (b.defence > 0)
                {
                    b.defence -= 1;
                }
                else
                {
                    b.hp -= 1;
                }
                break;
            }
            default:
                throw "Index out of range!";
                break;
            }
        }
    }
    else
    {
        // Computer wins
        cout << "You lose this round!" << endl;
        if (b.hp < 4)
        {
            b.hp += 1;
        }
        else if (b.defence < 2)
        {
            choice = 0;
        }
        else if (b.attackers == 0)
        {
            choice = 1;
        }
        else
        {
            choice = 2;
        }
        switch (choice)
        {
        case 0:
        {
            b.defence += 1;
            break;
        }
        case 1:
        {
            b.attackers += 1;
            break;
        }
        case 2:
        {
            if (a.attackers > 0)
            {
                a.attackers -= 1;
            }
            else if (a.defence > 0)
            {
                a.defence -= 1;
            }
            else
            {
                a.hp -= 1;
            }
            break;
        }
        default:
            throw "Index out of range!";
        }
    }
}

int PeacefulWar::run()
{
    bool condition = true; // Game flag, false will terminate the game
    Player player;
    Player computer;
    int p; // Player's choice
    int c; // Computer's randomized choice
    bool PlayerWins;
    init(player, computer);
    while (condition)
    {
        print_status(player, computer);
        srand(time(NULL));
        c = rand() % 3;
        p = -1; // Initialization of player's choice
        cout << "Enter your choice: (0 for scissors, 1 for rock, 2 for paper" << endl;
        cin >> p;
        // Detection for invalid value(s)
        while (!(p >= 0 && p <= 2))
        {
            cout << "Please enter a valid value!" << endl;
            cin >> p;
        }
        if ((p - c == 1) || (p - c == -2))
        {
            PlayerWins = true;
        }
        else
        {
            PlayerWins = false;
        }
        manageMovements(player, computer, PlayerWins);
        if ((player.hp == 0) || (computer.hp == 0))
        {
            // Terminate the game
            condition = false;
        }
    }
    if (computer.hp == 0)
    {
        cout << "You win!" << endl;
        return 0;
    }
    else if (player.hp == 0)
    {
        cout << "You lose!" << endl;
        return 1;
    }
}
