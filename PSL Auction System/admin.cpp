//#include "players.h"
//#include "batsmen.h"
//#include "bowlers.h"
//#include "allrounders.h"
//#include <algorithm>
//#include <fstream>
#include "admin.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
#define MAGENTA "\033[35m"      
#define BOLD    "\033[1m"      
#define RESET   "\033[0m"
#define RED     "\033[31m"  
#define CYAN    "\033[36m"
#define BLUE    "\033[34m"
#define GREEN   "\033[32m" 
const int MAX_TEAMS = 10;
ATeam* ateams[MAX_TEAMS];
int num_teams = 0;

void add_team() {
    string name;
    int budget;
    cout << "Enter the team name: ";
    getline(cin, name);
    cout << "Enter the team budget: ";
    cin >> budget;
    cin.ignore(); // to clear the newline character from the input buffer
    ATeam* new_team = new ATeam(name, budget);
    if (num_teams < MAX_TEAMS) {
        ateams[num_teams] = new_team;
        num_teams++;
        cout << GREEN << "New team added successfully!" << RESET << endl;
        cout << endl;
    }
    else {
        cout << "Maximum number of teams reached, cannot add more." << endl;
        delete new_team; // free the memory allocated for the new team
    }
}
void delete_team() {
    string name;
    cout << "Enter the team name to delete: ";
    getline(cin, name);
    bool deleted = false;
    for (int i = 0; i < num_teams; i++) {
        if (ateams[i]->get_name() == name) {
            for (int j = i; j < num_teams - 1; j++) {
                ateams[j] = ateams[j + 1];
            }
            num_teams--;
            deleted = true;
            cout << RED << BOLD <<"Team deleted successfully!" << RESET << endl;
            cout << endl;
            break;
        }
    }
    if (!deleted) {
        cout << "Team not found!" << endl;
    }
}
// admin menu
void adminMenu(vector<players>& playerList) {
    int choice, player_choice;

    do {
        cout << RED << BOLD << "Admin Menu" << RESET << endl;
        cout << "1. Add team" << endl;
        cout << "2. Delete team" << endl;
        cout << "3. Add a player \n";
        cout << "4. Logout from admin" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // to clear the newline character from the input buffer

        batsmen batsman;
        bowler bowl;
        all_rounder allround;

        switch (choice) {
        case 1:
            add_team();
            break;
        case 2:
            delete_team();
            break;
        case 3:
                //Players Addition Menu
                cout << "Which Player do you want to add" << endl;
                cout << "1. Batsmen" << endl;
                cout << "2. Bowler" << endl;
                cout << "3. All-Rounder" << endl;
                cout << "Enter your choice (1-3):";
                cin >> player_choice;
            //Adding Specific Type Players
            switch (player_choice)
            {
            case 1:
                batsman.add_players(playerList);
                break;

            case 2:
                bowl.add_players(playerList);
                break;

            case 3:
                allround.add_players(playerList);
                break;

            default:
                cout << "Incorrect Input" << endl;
                break;
            }

            cout << CYAN << "Exiting..." << RESET << endl;
            system("CLS");
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);
}

//void adminMenu()
//{
//}
