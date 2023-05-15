#include "players.h"
#ifndef bowler_h
#define bowler_h
using namespace std; 

class bowler : virtual public players{
    protected: 
        float economy;

    public: 

        bowler(){
            economy = 0; 
        }

        void setEconomy(float economy);
        float getEconomy() const;

        void add_players(vector<players>& playerList);
       void displayData(const std::string& filename); 

        //void setData(); 
        //void retrieveData();
        //int base();
        //int foreignPlayers();

};


#endif 