#ifndef PACMAN_H
#define PACMAN_H

class Pacman
{
private:
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
    void initpos(Bot &);
    void initspos(Score &);
    void randmove(Bot &);
    void initarray();
    void print(char a[15][30]);
    void move(char, Player &);

public:
    int play();
};

#endif