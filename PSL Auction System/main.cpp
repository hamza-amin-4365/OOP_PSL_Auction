#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <time.h>
#include "admin.h"

using namespace std;
#define RESET   "\033[0m"
#define RED     "\033[31m"      
#define GREEN   "\033[32m"      
#define YELLOW  "\033[33m"      
#define BLUE    "\033[34m"      
#define MAGENTA "\033[35m"      
#define CYAN    "\033[36m"      
#define WHITE   "\033[37m"      
#define BOLD    "\033[1m"      
#define UNDERLINE "\033[4m"     
#define BLINK   "\033[5m"      
#define REVERSE "\033[7m" 

const int NUM_TEAMS = 6;
const string ADMIN_USERNAME = "admin";
const string ADMIN_PASSWORD = "password";

struct Team {
    string name;
    string username;
    string password;
};

int get_choice() {
    int choice;
   // system("CLS");
    cout << MAGENTA << BOLD << "PSL Auction Login" << RESET << endl;
    cout << "Select User Type:\n";
    cout << "1. Team Manager\n";
    cout << "2. Admin\n";
    cout << "3. Exit\n";
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    return choice;
}

int get_team_choice() {
    int choice;
    do {
        cout << YELLOW << BOLD << "Team Selection" << RESET << endl;
        cout << "Select Team:\n";
        cout << "1. Lahore Qalandars\n";
        cout << "2. Karachi Kings\n";
        cout << "3. Multan Sultans\n";
        cout << "4. Islamabad United\n";
        cout << "5. Peshawar Zalmi\n";
        cout << "6. Quetta Gladiators\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        // Check if the choice is outside the valid range of values
        if (choice < 1 || choice > 6) {
            cout << RED << "Invalid choice. Please try again." << RESET << endl;
        }
    } while (choice < 1 || choice > 6); // Repeat if choice is outside the valid range

    return choice;
    }

void team_manager_login(Team team) {
    string username, password;
    bool login_successful = false;
    while (!login_successful) {
        cout << YELLOW << BOLD << "Team Manager Login - " << team.name << RESET << endl;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;
        vector<players> playerList;
        // check if the username and password are correct
        if (username == team.username && password == team.password) {
            cout << GREEN << "Login successful!" << RESET << endl;
            // TODO: add code to display team manager dashboard
            login_successful = true; // set flag to exit loop

            // auction starts here
            int category_choice, bid_id, bid_amount;
            char contbid;
            srand(time(0));

            cout << "\t\tPSL AUCTION HOUSE" << endl;
            cout << "Rules: " << endl;
            cout << "1. A team can have a maximum of 15 players" << endl;
            cout << "2. A team can have a maximum of 4 foreign players" << endl;
            cout << "3. The team with the maximum bid wins" << endl;


            do {
                do {
                    cout << "\nFrom which category do you want to bid on:" << endl;
                    cout << "1. Batsmen" << endl;
                    cout << "2. Bowlers" << endl;
                    cout << "3. All-Rounders" << endl;
                    cout << "Enter your choice (1-3): ";
                    cin >> category_choice;
                } while (category_choice < 1 || category_choice > 3);

                batsmen bats;
                bowler bo;
                all_rounder all;

                switch (category_choice) {
                case 1:
                    bats.displayData("batsmen.txt");
                    break;

                case 2:
                    bo.displayData("bowlers.txt");
                    break;

                case 3:
                    all.displayData("allrounders.txt");
                    break;

                default:
                    cout << "Incorrect input!" << endl;
                    break;
                }

                cout << "Do you want to continue to Bid? (y/n): ";
                cin >> contbid;

                while (contbid != 'y' && contbid != 'n') {
                    cout << "Invalid input! Do you want to continue to Bid? (y/n): ";
                    cin >> contbid;
                }

                if (contbid == 'n') {
                    break;
                }

                cout << "Enter the Player ID you want to bid on: ";
                cin >> bid_id;
                cin.ignore();

                bool found = false;
                for (const players& player : playerList) {
                    if (player.getID() == bid_id) {
                        found = true;
                        cout << "Player found" << endl;
                        break;
                    }
                }
                if (!found) {
                    cout << "Player not found" << endl;
                    continue;
                }

                int randomBid, randomTeam;
                randomBid = 100000 + (rand() % 900000);
                cout << "How much do you want to bid: ";
                cin >> bid_amount;
                cin.ignore();
                while (true) {
                    if (randomBid > bid_amount) {
                        cout << "Another team has made a bid of $" << randomBid << endl;
                        cout << "Do you wish to continue? (y/n):";
                        cin >> contbid;
                        while (contbid != 'y' && contbid != 'n') {
                            cout << "Invalid input! Do you wish to continue? (y/n): ";
                            cin >> contbid;
                        }
                        if (contbid == 'n') {
                            break;
                        }
                    }
                    else if (randomBid < bid_amount) {
                        cout << "You have won the player" << endl;
                        break;
                    }
                }

                cout << "Do you wish to continue bidding in another category (y/n): ";
                cin >> contbid;
                while (contbid != 'y' && contbid != 'n') {
                    cout << "Invalid input! Do you wish to continue bidding in another category (y/n): ";
                    cin >> contbid;
                }

            } while (contbid == 'y');
            //auction ends here
        }
        else {
            cout << RED << "Incorrect username or password. Please try again." << RESET << endl;
            }
        }
    }

void admin_login() {
    string username, password;

    cout << YELLOW << BOLD << "Admin Login" << RESET << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    // check if the username and password are correct
    if (username == ADMIN_USERNAME && password == ADMIN_PASSWORD) {
        cout << GREEN << "Login successful!" << RESET << endl;
        // TODO: add code to display admin dashboard
        std::vector<players> playerList; // Declare and initialize vector object
        adminMenu(playerList); // Pass vector to function

       
    }
    else {
        cout << RED << "Incorrect username or password. Please try again." << RESET << endl;
    }
}

int main() {
    system("CLS");
    // Define an array to hold information about the teams
    Team teams[NUM_TEAMS];
    // Read team information from a file
    ifstream infile("teams.txt");
    
   
    string line;
    int i = 0;
    while (getline(infile, line)) {
        vector<string> fields;
        string field = "";
        for (char c : line) {
            if (c == ',') {
                fields.push_back(field);
                field = "";
            }
            else {
                field += c;
            }
        }
        fields.push_back(field);
        teams[i].name = fields[0];
        teams[i].username = fields[1];
        teams[i].password = fields[2];
        i++;
    }
    if (!infile.eof() && infile.fail()) {
        // An error occurred during the read
        cerr << "Error: Failed to read teams.txt" << endl;
    }
    else {
        // Read operation was successful
        cout << "Teams successfully read from teams.txt" << endl;
    }
    // Display the login menu and get the user's choice
    int choice;
    do {
        choice = get_choice();

        switch (choice) {
        case 1: // Team Manager Login
        {
            int team_choice = get_team_choice();
            team_manager_login(teams[team_choice - 1]);
            break;
        }
        case 2: // Admin Login
            admin_login();
            break;
        case 3: // Exit
            cout << RED << BOLD << "Good bye!" << RESET << endl;
            return 0;
        default:
            cout << RED << "Invalid choice. Please try again." << RESET << endl;
            break;
        }

    } while (choice);

    return 0;
}
//player.getID() == bid_id