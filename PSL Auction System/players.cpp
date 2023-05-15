#include "players.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

#define BLUE    "\033[34m"
#define RESET   "\033[0m"
#define GREEN   "\033[32m" 
using namespace std;

// Getter functions
string players :: getName() const {
    return name;
}

int players :: getID() const {
    return player_id;
}

//Setter Functions
void players :: setName(string n) {
    name = n;
}

void players :: setID(int i){
    player_id = i;
}


void players :: add_players(vector<players>& playerList){
    
    players newPlayer; 
    cin.ignore();
    cout<<"Enter Player Name: "; 
    cin>>newPlayer.name;
    newPlayer.setName(newPlayer.name); 

    do{
        cout<<"Enter Player ID: ";
        cin>>newPlayer.player_id;
        newPlayer.setID(newPlayer.player_id);
    }
    while(newPlayer.player_id < 0);

    playerList.push_back(newPlayer);

    ofstream outfile("players.txt", ios_base::app);
    outfile << newPlayer.getName() << "," << newPlayer.getID()<< "\n";
    outfile.close();

}

void players::displayData(const std::string& filename) {

    ifstream file(filename);
    if (!file) {
        cout << "Error opening file." << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        string name, id;
        size_t commaPos = line.find(',');
        if (commaPos != string::npos) {
            name = line.substr(0, commaPos);
            id = line.substr(commaPos + 1);
            std::cout << "Name: " << name << ", ID: " << id << std::endl;
        }
    }

    file.close();

    
}
