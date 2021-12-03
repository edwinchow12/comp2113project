#include <iostream>
#include <fstream>
#include <sstream>
#include "filehandler.h"

using namespace std;

bool isExist(string n)
{
    ifstream userdata;
    string temp;
    userdata.open("../data/userdata.txt");
    while (userdata >> temp)
    {
        if (temp == n)
        {
            cout << "Player already exists! Enter a new name." << endl;
            return true;
        }
        else
        {
            userdata >> temp;
            userdata >> temp;
        }
    }
    userdata.close();
    return false;
    
}

void CreateNewUser(Player * newPlayer)
{
    string name;
    // Receive input and test if it already exists in the file
    do
    {
        cout << "Enter the username: " << endl;
        cin >> name;
    } while (isExist(name));

    newPlayer->player(name, 0, "Mathematics");

    ofstream temp;
    string str_temp;
    temp.open("../data/userdata.txt", ios::app);
    temp << newPlayer->name << " ";
    temp << newPlayer->numPowerDusts << " ";
    temp << newPlayer->planet << endl;

    temp.close();
}

bool LoadUser(Player * player){
    char input;
    bool found = false;
    string str_temp;
    ifstream userdata;
    userdata.open("../data/userdata.txt");
    while (getline(userdata, str_temp)){
        stringstream s(str_temp);
        string datum;
        int int_datum;
        s >> datum;
        if (datum == player->name){
            s >> int_datum;
            player->numPowerDusts = int_datum;
            s >> datum;
            player->planet = datum;
            found = true;
        }
    }
    userdata.close();
    if (!found){
        cout << "User not found. Create a new user instead? (Y/N)" << endl;
        do {
            cin >> input;
            if (input == 'Y') {
                CreateNewUser(player);
                found = true;
            }
        } while (input != 'Y' && input != 'N');
    }

    return found;
}

void SaveProcess(Player *p)
{
    ofstream temp;     // New Userdata file
    ifstream original; // Old Userdata file
    string str_temp;

    temp.open("../data/.temp.txt");
    original.open("../data/userdata.txt");
    while (original >> str_temp)
    {
        if (str_temp != p->name)
        {
            temp << str_temp << " ";
            original >> str_temp;
            temp << str_temp << " ";
            original >> str_temp;
            temp << str_temp << " ";
        }
        else
        {
            temp << p->name << " ";
            temp << p->numPowerDusts << " ";
            temp << p->planet;

            // skip the next three words
            original >> str_temp;
            original >> str_temp;
            original >> str_temp;
        }
        temp << endl;
    } 
    temp << endl;
    temp.close();
    original.close();
    rename("../data/.temp.txt", "../data/userdata.txt");
}

/*int main()
{
    Player *player = new Player;
    player->player("new", 20, "Mathematics");
    SaveProcess(player);
    //CreateNewUser(player);
    delete player;
    return 0;
}*/
