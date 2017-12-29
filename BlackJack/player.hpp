//Headeree

#ifndef player_hpp
#define player_hpp
#include <vector>
#include "abstractplayer.hpp"

class player: public abstractplayer{
public:
    
    player(const string name): abstractplayer(name) {}

    
    bool playeractive(){
        return active;
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
