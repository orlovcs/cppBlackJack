//Headeree

#ifndef player_hpp
#define player_hpp
#include <vector>
#include <iostream>
#include "card.hpp"

class player{
    string name;
    vector <card*> playerdeck;
    int value;
public:
    player(string name): name{name} {}
    void acceptCard(card * o){
        playerdeck.emplace_back(o);
    }
    string getName(){
        return name;
    }
    void showCards(){
        cout << name <<" has: " << endl;
        for (auto m: playerdeck){
            m->print();
        }
        cout << " value is:  " << calcValues() << endl;
    }
    
    int calcValues(){
        int aceAmount = 0;
        for (auto m: playerdeck){
            
                if (m->getFace() == "TWO" ){
                    value += 2;
                }
                else if (m->getFace() == "THREE" ){
                    value += 3;
                }
                else if (m->getFace() == "FOUR" ){
                    value += 4;
                }
                else if (m->getFace() == "FIVE" ){
                    value += 5;
                }
                else if (m->getFace() == "SIX" ){
                    value += 6;
                }
                else if (m->getFace() == "SEVEN" ){
                    value += 7;
                }
                else if (m->getFace() == "EIGHT" ){
                    value += 8;
                }
                else if (m->getFace() == "NINE" ){
                    value += 9;
                }
                else if (m->getFace() == "TEN" ){
                    value += 10;
                }
                else if (m->getFace() == "KING" ){
                    value += 10;
                }
                else if (m->getFace() == "QUEEN" ){
                    value += 10;
                }
                else if (m->getFace() == "JACK" ){
                    value += 10;
                }
                else if (m->getFace() == "ACE" ){
                    aceAmount += 1;
                }
            
            
                
                }
        
        while(aceAmount!=0){
            aceAmount--;
            if ((value+11+aceAmount) <= 21) {value += 11;}
            else {value++;}
        }
        
        
        return value;
        
        }
    
    
    
};


#endif /* player_hpp */
