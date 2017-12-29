//Headeree

#ifndef player_hpp
#define player_hpp
#include <vector>
#include "card.hpp"

class player{
    string name;
    vector <card> playerdeck;
public:
    player(string name): name{name} {}
    void acceptCard();
    string getName(){
        return name;
    }
    
    
};


#endif /* player_hpp */
