#include "players.h"
#ifndef batsmen_h
#define batsmen_h
using namespace std;

class batsmen : virtual public players {
protected:
    float strike_rate;

public:

    batsmen() {
        strike_rate = 0;
    }

    void setStrikerate(float strike_rate);
    float getStrikerate() const;

    void add_players(vector<players>& playerList);
   void displayData(const std::string& filename); 

    // void setData();
    //void retrieveData();
    //int base();
    //int foreignPlayers();

};


#endif 