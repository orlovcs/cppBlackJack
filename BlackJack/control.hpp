
#include <iostream>
#include <vector>
#include "player.hpp"
#include "dealer.hpp"
#include "deck.hpp"
using namespace std;

class control{
    int players;
    int deckamount = 1;
    deck d;
    dealer * pdealer;
    vector<player*> playerlist;
    
public:
  
    control(){  }
    
    void init(){
        cout << "enter amount of decks 1-8" << endl;
        cin >> deckamount;
        deck d(deckamount);
        
    }
    void dealerinit(){
        
        cout << "Enter Dealer name: " << endl;
        string dealername;
        cin >> dealername;
        dealer * pdealer = new dealer(dealername);
        
    }
    
    void playerinit(){
        
        cout << "enter amount of players 2-7" << endl;
        cin >> players;
        
        
        
        for (int i = 0; i < players; ++i){
            cout << "enter player " << i+1 <<  " name" << endl;
            string pname;
            cin >> pname;
            cout << "enter player " << i+1 << " bet" << endl;
            int pbet;
            cin >> pbet;
            playerlist.emplace_back(new player(pname, pbet));
        }
        
    }
    
    void displayplayers(){
        
        cout << "players are: " << endl;
        for (auto m: playerlist){
            cout <<  m->getName() << endl;
        }
        
    }
    
    void deckSize(){
        
        //make menu for view player, cards what each player has
        cout << "There are " << d.getSize() << " cards in the deck." << endl;
        
    }
    
    void deckShuffle(){
        cout << "Cards are being shuffled." << endl;
        d.shuffle();
        }
    
    
};
