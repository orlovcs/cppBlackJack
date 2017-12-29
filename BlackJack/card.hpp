
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
        cout << "|Face: "<< face << " -- Suit: " << suit << "| -- Value: ";
        
        if (face == "TWO" ){
            cout << "2" << endl;
        }
        else if (face == "THREE" ){
            cout << "3" << endl;
        }
        else if (face == "FOUR" ){
            cout << "4" << endl;
        }
        else if (face == "FIVE" ){
            cout << "5" << endl;
        }
        else if (face == "SIX" ){
            cout << "6" << endl;
        }
        else if (face == "SEVEN" ){
            cout << "7" << endl;
        }
        else if (face == "EIGHT" ){
            cout << "8" << endl;
        }
        else if (face == "NINE" ){
            cout << "9" << endl;
        }
        else if (face == "TEN" ){
            cout << "10" << endl;
        }
        else if (face == "KING" ){
            cout << "10" << endl;
        }
        else if (face == "QUEEN" ){
            cout << "10" << endl;
        }
        else if (face == "JACK" ){
            cout << "10" << endl;
        }
        else if (face == "ACE" ){
            cout << "1 or 11" << endl;
        }
    }
    string getFace(){
        return face;
    }
    
};

#endif /* card_hpp */
