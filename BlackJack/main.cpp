//Headeree
//8 decks at max
#include <iostream>
#include <vector>
#include "player.hpp"
#include "deck.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    
    int players;
    int deckamount = 1;
    
    cout << "enter amount of decks 1-8" << endl;
    cin >> deckamount;
    deck d(deckamount);
    
    cout << "enter amount of players 2-7" << endl;
    cin >> players;
    
    vector<player*> playerlist;
    
    for (int i = 0; i < players; ++i){
        cout << "enter name" << endl;
        string pname;
        cin >> pname;
        playerlist.emplace_back(new player(pname));
    }
    
    cout << "players are: " << endl;
    for (auto m: playerlist){
        cout <<  m->getName() << endl;
    }
    
    //make menu for view player, cards what each player has
    cout << "There are " << d.getSize() << " cards in the deck." << endl;

    d.shuffle();
    
    cout << "cards are being dealt: " << endl;
    for (auto m: playerlist){
        if (!d.empty()){
        m->acceptCard(d.deal());
        m->acceptCard(d.deal());
        }
    }
    
    cout << "players cards are: " << endl;
    for (auto m: playerlist){
        m->showCards();
            }
    


    
    
    
    cout << "hit: " << endl;
    for (auto m: playerlist){
        cout << "There are " << d.getSize() << " cards left in the deck." << endl;

        cout << "hit " << m->getName() << "?" << endl;
        string hit;
        cin >> hit;
        while (hit == "yes"){
       m->acceptCard(d.deal());
       cout << m->getName() << " was hit, they now have: " << endl;
       m->showCards();
            if (m->calcValues()==21){
                cout << m->getName() << " got a blackjack" << endl;
                hit = "no";
                continue;
            }
            else if (m->calcValues()>21){
                cout << m->getName() << " got a bust" << endl;
                hit = "no";
                continue;
            }
       cout << "hit " << m->getName() << " again?" << endl;
       cin >> hit;
       }
        cout << m->getName() << " has stood" << endl;
        
        
        }
    
    
    
    

    return 0;
}
