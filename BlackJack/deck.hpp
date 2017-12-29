//Headeree

#ifndef deck_hpp
#define deck_hpp

#include "card.hpp"
#include <vector>
class deck{
    vector<card> d;
public:
    deck(){
        d.emplace_back(card("10","Hearts"));
    }
    void shuffle();
    void deal();
    bool empty();
    
    
};


#endif /* deck_hpp */
