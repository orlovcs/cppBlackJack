//Headeree

#ifndef deck_hpp
#define deck_hpp

#include "card.hpp"
#include <vector>
class deck{
    vector< card* > d;
public:
    deck(){
        d.emplace_back( new card("10","Hearts"));
    }
    void shuffle();
    
    card* deal(){
        card * tmp = d.back();
        d.pop_back();
        return tmp;
    }
    
    bool empty(){
        return d.empty();
        
    }
    
    
};


#endif /* deck_hpp */
