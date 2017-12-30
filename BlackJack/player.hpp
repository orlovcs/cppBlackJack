//Headeree

#ifndef player_hpp
#define player_hpp
#include <vector>
#include "abstractplayer.hpp"

class player: public abstractplayer{
public:
    
    player(const string name): abstractplayer(name) {}
    player(const string name, int bet): abstractplayer(name, bet) {}
    
    bool playeractive(){
        return active;
    }
    void resetBet(){
        bet = 0;
    }
    
    void setInactive(){
        active = false;
    }
    
    bool busted(){
        if (calcValues() > 21){
            return true;
        }
        else{
            return false;
        }
    }
    
    
};
#endif /* player_hpp */
