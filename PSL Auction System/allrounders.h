#include "players.h"
#include "batsmen.h"
#include "bowlers.h"
#ifndef allrounder_h
#define allrounder_h
using namespace std; 

class all_rounder : public batsmen, public bowler{
    public: 

        all_rounder(){
            strike_rate = 0; 
            economy = 0;
        }

        void setStrikerate(float strike_rate);
        float getStrikerate() const;
        void setEconomy(float economy);
        float getEconomy() const;

        void add_players(vector<players>& playerList); 
        void displayData (const std::string& filename) override ;

        // void setData();
       // void retrieveData();
        //int base();
        //int foreignPlayers();

};


#endif 