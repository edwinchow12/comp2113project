#ifndef FILEHANDLER_H
#define FILEHANDLER_H

using namespace std;

struct Player
{
    string name;
    int numPowerDusts;
    string planet;
    void player(string name, int n, string p)
    {
        this->name = name;
        this->numPowerDusts = n;
        this->planet = p;
    }
};

bool isExist(std::string);
bool LoadUser(Player *);
void CreateNewUser(Player *);
void SaveProcess(Player *);

#endif
