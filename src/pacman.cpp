
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "pacman.h"

using namespace std;

//to initialize the position of the
void Pacman::initpos(Bot &B)
{
    B.r = rand() % 15;
    if (B.r == 1)
        B.r = rand() % 15;
    B.c = rand() % 30;
    if (B.c == 1)
        B.c = rand() % 30;
    if (B.r == 0)
        B.r++;
    if (B.r == 14)
        B.r--;
    if (B.c == 0)
        B.c++;
    if (B.c == 29)
        B.c--;
}

//to initialize the position of score
void Pacman::initspos(Score &S)
{
    S.r = rand() % 15;
    if (S.r == 1)
        S.r = rand() % 15;
    S.c = rand() % 30;
    if (S.c == 1)
        S.c = rand() % 30;
    if (S.r == 0)
        S.r++;
    if (S.r == 14)
        S.r--;
    if (S.c == 0)
        S.c++;
    if (S.c == 29)
        S.c--;
}

//to move the position of the bot randomly
void Pacman::randmove(Bot &B)
{
    int c;
    c = rand() % 4;
    if (c == 0)
        B.r++;
    if (c == 1)
        B.r--;
    if (c == 2)
        B.c++;
    if (c == 3)
        B.c--;
    if (B.r == 0)
        B.r++;
    if (B.r == 14)
        B.r--;
    if (B.c == 0)
        B.c++;
    if (B.c == 29)
        B.c--;
}

//to initialize the array which is the map
void Pacman::initarray()
{
    for (int i = 0; i < 15; i++)
    {
        for (int n = 0; n < 30; n++)
        {
            a[i][n] = ' ';
        }
    }
    for (int i = 0; i < 30; i++)
    {
        a[0][i] = 'x';
    }
    for (int i = 0; i < 30; i++)
    {
        a[14][i] = 'x';
    }
    for (int i = 0; i < 15; i++)
    {
        a[i][0] = 'x';
    }
    for (int i = 0; i < 15; i++)
    {
        a[i][29] = 'x';
    }
}

//to print the array
void Pacman::print(char a[15][30])
{
    for (int i = 0; i < 15; i++)
    {
        for (int n = 0; n < 30; n++)
        {
            cout << a[i][n];
        }
        cout << endl;
    }
}

//to move the position of the player according to the user's input
void Pacman::move(char input, Player &p)
{
    switch (input)
    {
    case 'w':
        p.r--;
        break;
    case 'a':
        p.c--;
        break;
    case 's':
        p.r++;
        break;
    case 'd':
        p.c++;
        break;
    }
}

//to play the game
//if the player hit the walls or the bots, the game will be over
//if the player's position overlaps with that of the score, the player will get one score
int Pacman::play()
{
    srand(time(NULL));
    Bot B, B1, B2;
    Score s1, s2, s3;
    initpos(B);
    initpos(B1);
    initpos(B2);
    initspos(s1);
    initspos(s2);
    char input;
    Player p;
    p.r = p.c = 1;
    initarray();
    a[B.r][B.c] = 'B';
    a[B1.r][B1.c] = 'B';
    a[B2.r][B2.c] = 'B';
    a[p.r][p.c] = 'P';
    a[s1.r][s1.c] = 'S';
    a[s2.r][s2.c] = 'S';
    print(a);
    int tof = 0;
    while (p.r != 0 || p.c != 0 || p.c != 29 || p.r != 14)
    {
        system("stty raw");
        cin >> input;
        system("stty cooked");
        a[p.r][p.c] = ' ';
        a[B.r][B.c] = ' ';
        a[B1.r][B1.c] = ' ';
        a[B2.r][B2.c] = ' ';
        move(input, p);
        a[p.r][p.c] = 'P';
        if (p.r == 0 || p.c == 0 || p.c == 29 || p.r == 14)
            break;
        if (p.r == B.r && p.c == B.c)
            break;
        if (p.r == B1.r && p.c == B1.c)
            break;
        if (p.r == B2.r && p.c == B2.c)
            break;
        if (p.r == s1.r && p.c == s1.c)
        {
            a[s1.r][s1.c] = 'P';
            p.score++;
            tof = 1;
            s1.r = s1.c = 0;
            a[s1.r][s1.c] = 'x';
        } else {
            if (a[s1.r][s1.c] != 'x')
                a[s1.r][s1.c] = 'S';
        }
        if (p.r == s2.r && p.c == s2.c)
        {
            a[s2.r][s2.c] = 'P';
            p.score++;
            tof = 2;
            s2.r = s2.c = 0;
            a[s2.r][s2.c] = 'x';
        } else {
            if (a[s2.r][s2.c] != 'x')
                a[s2.r][s2.c] = 'S';
        }
        randmove(B);
        randmove(B1);
        randmove(B2);
        a[B.r][B.c] = 'B';
        a[B1.r][B1.c] = 'B';
        a[B2.r][B2.c] = 'B';
        if (p.r == 0 || p.c == 0 || p.c == 29 || p.r == 14)
            return 1;
        if (p.r == B.r && p.c == B.c)
            return 1;
        if (p.r == B1.r && p.c == B1.c)
            return 1;
        if (p.r == B2.r && p.c == B2.c)
            return 1;
        if (p.score==2) break;
        printf("\033c");
        print(a);
    }
    printf("\033c");
    print(a);
    cout << "Type \'C\' to Continue..." << endl;
    system("stty raw");
    cin >> input;
    system("stty cooked");
    printf("\033c");
    if (input == 'c')
    {  
        cout<<"You win the game!"<<endl;
        cout << "████████████████████████████████████████" << endl;
        cout << "████████████████████████████████████████" << endl;
        cout << "██████▀░░░░░░░░▀████████▀▀░░░░░░░▀██████" << endl;
        cout << "████▀░░░░░░░░░░░░▀████▀░░░░░░░░░░░░▀████" << endl;
        cout << "██▀░░░░░░░░░░░░░░░░▀▀░░░░░░░░░░░░░░░░▀██" << endl;
        cout << "██░░░░░░░░░░░░░░░░░░░▄▄░░░░░░░░░░░░░░░██" << endl;
        cout << "██░░░░░░░░░░░░░░░░░░█░█░░░░░░░░░░░░░░░██" << endl;
        cout << "██░░░░░░░░░░░░░░░░░▄▀░█░░░░░░░░░░░░░░░██" << endl;
        cout << "██░░░░░░░░░░████▄▄▄▀░░▀▀▀▀▄░░░░░░░░░░░██" << endl;
        cout << "██▄░░░░░░░░░████░░░░░░░░░░█░░░░░░░░░░▄██" << endl;
        cout << "████▄░░░░░░░████░░░░░░░░░░█░░░░░░░░▄████" << endl;
        cout << "██████▄░░░░░████▄▄▄░░░░░░░█░░░░░░▄██████" << endl;
        cout << "████████▄░░░▀▀▀▀░░░▀▀▀▀▀▀▀░░░░░▄████████" << endl;
        cout << "██████████▄░░░░░░░░░░░░░░░░░░▄██████████" << endl;
        cout << "████████████▄░░░░░░░░░░░░░░▄████████████" << endl;
        cout << "██████████████▄░░░░░░░░░░▄██████████████" << endl;
        cout << "████████████████▄░░░░░░▄████████████████" << endl;
        cout << "██████████████████▄▄▄▄██████████████████" << endl;
        cout << "████████████████████████████████████████" << endl;
        cout << "████████████████████████████████████████" << endl;
    }
    return 0;
}

/*int main(){
    Pacman * pacman = new Pacman;
    pacman->play();
    delete pacman;
    return 0;
}*/
