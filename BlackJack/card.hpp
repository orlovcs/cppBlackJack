
#ifndef card_hpp
#define card_hpp

#include <iostream>
#include <string>
using namespace std;
class card {
    string face;
    string suit;
public:
    card(string face, string suit) : face{face}, suit{suit} {}
    void print(){
        cout << "|!Face: "<<face << "Suit: " << suit << "|"<< endl;
    }
    string getFace(){
        return face;
    }
    
};

#endif /* card_hpp */
