#include "bowlers.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

#define BLUE    "\033[34m"
#define RESET   "\033[0m"
#define GREEN   "\033[32m" 
using namespace std;

// Getter functions
float bowler :: getEconomy() const {
    return economy;
}

//Setter Functions
void bowler :: setEconomy(float e) {
    economy = e;
}

void bowler :: add_players(vector<players>& playerList){
    
    players::add_players(playerList);
    bowler newBowler; 

    cout<<"Enter Bowler Economy: "; 
    cin>>newBowler.economy;
    newBowler.setEconomy(newBowler.economy); 

    playerList.push_back(newBowler);

    ofstream outfile1("players.txt", ios_base::app);
    outfile1 << newBowler.getName() << "," << newBowler.getID() << "," << newBowler.getEconomy() << "\n";
    outfile1.close();

    ofstream outfile2("bowlers.txt", ios_base::app);
    outfile2 << newBowler.getName() << "," << newBowler.getID() << "," << newBowler.getEconomy() << "\n";
    outfile2.close();




    cout << GREEN << "Player added successfully!" << RESET <<endl;
    cout << endl;
}

void bowler::displayData(const std::string& filename) {

    std::ifstream file(filename);
    if (!file) {
        std::cout << "Error opening file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::string name, id, avgEconomy;
        size_t commaPos1 = line.find(',');
        size_t commaPos2 = line.find(',', commaPos1 + 1);
        if (commaPos1 != std::string::npos && commaPos2 != std::string::npos) {
            name = line.substr(0, commaPos1);
            id = line.substr(commaPos1 + 1, commaPos2 - commaPos1 - 1);
            avgEconomy = line.substr(commaPos2 + 1);
            std::cout << "Name: " << name << ", ID: " << id << ", Avg Economy: " << avgEconomy << std::endl;
        }
    }

    file.close();
}
