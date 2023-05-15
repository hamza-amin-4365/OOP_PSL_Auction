#ifndef player_h
#define player_h 
#include <string>
#include <vector>
using namespace std; 

class players{
    protected: 
        string name; 
        int player_id; 
        
    public: 
        players(){
            player_id = 0;  
        }

        void setName(string name);
        string getName() const;

        void setID(int player_id);
        int getID() const;


        virtual void add_players(vector<players>& playerList); 
        virtual void displayData(const std::string& filename);
};

#endif 
