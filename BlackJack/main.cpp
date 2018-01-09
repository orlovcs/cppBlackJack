
#include <iostream>
#include <vector>
#include "player.hpp"
#include "dealer.hpp"
#include "deck.hpp"
using namespace std;

    int main(int argc, const char * argv[]) {
        
        int players;
        int deckamount = 1;
        
        cout << "enter amount of decks 1-8" << endl;
        cin >> deckamount;
        deck d(deckamount);
        
        
        
        cout << "Enter Dealer name: " << endl;
        string dealername;
        cin >> dealername;
        dealer * pdealer = new dealer(dealername);
        
        // once control is initialized , create a dealer player in ctor
        
        cout << "enter amount of players 2-7" << endl;
        cin >> players;
        
        vector<player*> playerlist;
        
        for (int i = 0; i < players; ++i){
            cout << "enter player " << i+1 <<  " name" << endl;
            string pname;
            cin >> pname;
            cout << "enter player " << i+1 << " bet" << endl;
            int pbet;
            cin >> pbet;
            playerlist.emplace_back(new player(pname, pbet));
        }
        
        cout << "players are: " << endl;
        for (auto m: playerlist){
            cout <<  m->getName() << endl;
        }
        
        //make menu for view player, cards what each player has
        cout << "There are " << d.getSize() << " cards in the deck." << endl;
        
        cout << "Cards are being shuffled." << endl;
        d.shuffle();
        
        cout << "cards are being dealt: " << endl;
        pdealer->acceptCard(d.deal());
        pdealer->acceptCard(d.deal());
        for (auto m: playerlist){
            if (!d.empty()){
                m->acceptCard(d.deal());
                m->acceptCard(d.deal());
            }
        }
        
        
        cout << "-----------" << endl;
        pdealer->showHalf();
        cout << "players cards are: " << endl;
        for (auto m: playerlist){
            m->showCards();
        }
        cout << "-----------" << endl;
        
        
        cout << "Checking for naturals in the players cards: " << endl;
        for (auto m: playerlist){
            if (m->calcValues()==21){
                cout << m->getName() << " got a natural" << endl;
                cout << m->getName() << "'s bet was " << m->getBet() << endl;
                cout << m->getName() << " recieves " << (3/2)* m->getBet() << " from the house." << endl;
                m->addWinnings((3/2)* m->getBet());
                m->setInactive();
            }
        }
        
        cout << "hit: " << endl;
        for (auto m: playerlist){
            if (m->playeractive()){
                cout << "There are " << d.getSize() << " cards left in the deck." << endl;
                if (d.getSize() < 1){
                    cout << "Not enough cards." << endl;
                    break;
                }
                cout << ">>>>>>>>>>>> " << m->getName() << "'s turn." << endl;
                cout << "hit " << m->getName() << "?" << endl;
                string hit;
                cin >> hit;
                
                if (hit == "yes"){
                    while (hit == "yes"){
                        m->acceptCard(d.deal());
                        cout << m->getName() << " was hit" << endl;
                        m->showCards();
                        
                        if (d.getSize() < 1){
                            cout << "Not enough cards." << endl;
                            break;
                        }
                        
                        if (m->calcValues()==21){
                            cout << m->getName() << " got a blackjack" << endl;
                            hit = "no";
                            m->setInactive();
                            continue;
                        }
                        
                        else if (m->calcValues()>21){
                            cout << m->getName() << " got a bust" << endl;
                            hit = "no";
                            cout << m->getName() << "'s bet was " << m->getBet() << endl;
                            cout << "The house recieves " << m->getBet() << " from " << m->getName() << "." << endl;
                            pdealer -> addWinnings(m->getBet());
                            m -> resetBet();
                            m->setInactive();
                            continue;
                        }
                        cout << "hit " << m->getName() << " again?" << endl;
                        cin >> hit;
                    }}else{
                        cout << m->getName() << " has stood" << endl;
                    }
                
                
                cout << "<<<<<<<<<<<< "  << m->getName() << "'s turn ended." << endl;
                
            }
            
        }
        
        pdealer->showCards();
        while (pdealer->calcValues() < 17){
            cout  << pdealer->getName() << "gains a card: " << endl;
            pdealer->acceptCard(d.deal());
            
            if (pdealer->calcValues()>21){
                cout << pdealer->getName() << " has busted." << endl;
                cout << " All remaining players win." << endl;
                for (auto m: playerlist){
                    if (m->calcValues()==21){
                        cout << m->getName() << "'s bet was " << m->getBet() << endl;
                        cout << m->getName() << " recieves " << (3/2)* m->getBet() << " from the house." << endl;
                        m->addWinnings((3/2)* m->getBet());
                        m->setInactive();
                    }
                }
                break;
            }
            cout << "Dealer now has: " << endl;
            pdealer->showCards();
        }
        
        
        
        
        
        
        
        
        return 0;
    }
    


    

