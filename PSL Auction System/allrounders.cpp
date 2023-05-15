#include "allrounders.h"
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
float all_rounder::getStrikerate() const {
    return strike_rate;
}

float all_rounder::getEconomy() const {
    return economy;
}

//Setter Functions
void all_rounder::setStrikerate(float str) {
    strike_rate = str;
}

void all_rounder::setEconomy(float e) {
    economy = e;
}

void all_rounder::add_players(vector<players>& playerList) {

    players::add_players(playerList);
    all_rounder newAllRounder;

    cout << "Enter All-Rounder Strike Rate: ";
    cin >> newAllRounder.strike_rate;
    newAllRounder.setStrikerate(newAllRounder.strike_rate);

    cout << "Enter All-Rounder Economy: ";
    cin >> newAllRounder.economy;
    newAllRounder.setEconomy(newAllRounder.economy);

    playerList.push_back(newAllRounder);

    ofstream outfile("players.txt", ios_base::app);
    outfile << newAllRounder.getName() << "," << newAllRounder.getID() << "," << newAllRounder.getStrikerate() << "," << newAllRounder.getEconomy() << "\n";
    outfile.close();

    outfile.open("allrounders.txt", ios_base::app);
    outfile << newAllRounder.getName() << "," << newAllRounder.getID() << "," << newAllRounder.getStrikerate() << "," << newAllRounder.getEconomy() << "\n";
    outfile.close();

    cout << GREEN << "Player added successfully!" << RESET << endl;
    cout << endl;
}

void all_rounder::displayData(const std::string& filename) {

    std::ifstream file(filename);
    if (!file) {
        std::cout << "Error opening file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::string name, id, economy, avgStrikeRate;
        size_t commaPos1 = line.find(',');
        size_t commaPos2 = line.find(',', commaPos1 + 1);
        size_t commaPos3 = line.find(',', commaPos2 + 1);
        if (commaPos1 != std::string::npos && commaPos2 != std::string::npos && commaPos3 != std::string::npos) {
            name = line.substr(0, commaPos1);
            id = line.substr(commaPos1 + 1, commaPos2 - commaPos1 - 1);
            economy = line.substr(commaPos2 + 1, commaPos3 - commaPos2 - 1);
            avgStrikeRate = line.substr(commaPos3 + 1);
            std::cout << "Name: " << name << ", ID: " << id << ", Economy: " << economy << ", Avg Strike Rate: " << avgStrikeRate << std::endl;
        }
    }

    file.close();
}

