//Headeree

#ifndef deck_hpp
#define deck_hpp

#include "card.hpp"
#include <algorithm>
#include <random>
#include <vector>
class deck{
    vector< card* > d;
public:
    deck(){
        string suites[] = {"ACE", "CLUBS","SPADES", "HEARTS"};
        string faces[] = {"TWO","THREE","FOUR","FIVE","SIX" ,"SEVEN", "EIGHT", "NINE", "TEN", "KING" ,"QUEEN", "JACK", "ACE"};
        for (auto s : suites){
            for (auto f : faces){
                d.emplace_back( new card(f,s));
            }
            
            
            
        }
        

    }
    void shuffle(){
        srand( time(NULL) );
                for (int i = d.size()-1; i > 0; i--)
        {
            int r = rand() % (i+1);
            std::swap(d[i], d[r]);
        }
        
    }
    
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
