
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

char a[15][30];

struct Player
{
    int r;
    int c;
    int score = 0;
};

struct Bot
{
    int r;
    int c;
};

struct Score
{
    int r;
    int c;
};

void initpos(Bot &B)
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

void initspos(Score &S)
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

void randmove(Bot &B)
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

void initarray()
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

void print(char a[15][30])
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

void move(char input, Player &p)
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

int main()
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
        }
        if (p.r == s2.r && p.c == s2.c)
        {
            a[s2.r][s2.c] = 'P';
            p.score++;
            tof = 2;
            s2.r = s2.c = 0;
        }
        randmove(B);
        randmove(B1);
        randmove(B2);
        a[B.r][B.c] = 'B';
        a[B1.r][B1.c] = 'B';
        a[B2.r][B2.c] = 'B';
        if (p.r == 0 || p.c == 0 || p.c == 29 || p.r == 14)
            break;
        if (p.r == B.r && p.c == B.c)
            break;
        if (p.r == B1.r && p.c == B1.c)
            break;
        if (p.r == B2.r && p.c == B2.c)
            break;
        printf("\033c");
        print(a);
    }
    printf("\033c");
    print(a);
    cout << p.score << endl;
    cout << "Type \'C\' to Continue..." << endl;
    system("stty raw");
    cin >> input;
    system("stty cooked");
    system("clear");
    if (input == 'c')
    {
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