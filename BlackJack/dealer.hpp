///*---///
//Nikita Orlov|2017-12-29|___WORKSPACE___|C++|orlovcs
//*///---

#ifndef dealer_hpp
#define dealer_hpp
#include "abstractplayer.hpp"

class dealer: public abstractplayer{
public:

    dealer(const string name): abstractplayer("Dealer"+name) {}

    void showHalf(){
        cout << "Dealer has: " << endl;
        (playerdeck.front()->print());
        cout << "Other card is hidden." << endl;
        }
    
    
};


#endif /* dealer_hpp */
