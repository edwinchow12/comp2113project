#ifndef MATHEMATICS_H
#define MATHEMATICS_H

class GuessTheNumber
{
public:
    int run();
};

class PeacefulWar
{
private:
    struct Player
    {
        int hp;
        int defence;
        int attackers;
    };
    void init(Player &, Player &);
    void print_status(Player, Player);
    void manageMovements(Player &, Player &, bool);

public:
    int run();
};

#endif
