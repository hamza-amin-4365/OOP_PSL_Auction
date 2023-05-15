#include "batsmen.h"
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
float batsmen :: getStrikerate() const {
    return strike_rate;
}

//Setter Functions
void batsmen :: setStrikerate(float str) {
    strike_rate = str;
}

void batsmen::add_players(vector<players>& playerList) {

    players::add_players(playerList);
    batsmen newBatsmen;

    cout << "Enter Batsman Strike Rate: ";
    cin >> newBatsmen.strike_rate;
    newBatsmen.setStrikerate(newBatsmen.strike_rate);

    playerList.push_back(newBatsmen);

    ofstream outfile1("players.txt", ios_base::app);
    outfile1 << newBatsmen.getName() << "," << newBatsmen.getID() << "," << newBatsmen.getStrikerate() << "\n";
    outfile1.close();

    ofstream outfile2("batsmen.txt", ios_base::app);
    outfile2 << newBatsmen.getName() << "," << newBatsmen.getID() << "," << newBatsmen.getStrikerate() << "\n";
    outfile2.close();


    cout << GREEN << "Player added successfully!" << RESET << endl;
    cout << endl;
}


void batsmen::displayData(const std::string& filename) {

    std::ifstream file(filename);
    if (!file) {
        std::cout << "Error opening file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::string name, id, avgStrikeRate;
        size_t commaPos1 = line.find(',');
        size_t commaPos2 = line.find(',', commaPos1 + 1);
        if (commaPos1 != std::string::npos && commaPos2 != std::string::npos) {
            name = line.substr(0, commaPos1);
            id = line.substr(commaPos1 + 1, commaPos2 - commaPos1 - 1);
            avgStrikeRate = line.substr(commaPos2 + 1);
            std::cout << "Name: " << name << ", ID: " << id << ", Avg Strike Rate: " << avgStrikeRate << std::endl;
        }
    }

    file.close();
}


