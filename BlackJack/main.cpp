//Headeree
//8 decks at max
#include <iostream>
#include <vector>
#include "player.hpp"
#include "deck.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    deck d;
    int players;
    cout << "enter amount of players" << endl;
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
    
    for (auto m: playerlist){
        if(m->won()){
            cout << m->getName() << " has won" << endl;
            exit(0);
        }
        else if(m->busted()){
            cout << m->getName() << " has busted" << endl;
            m->setInactive();
        }
    }
    
    cout << "hit: " << endl;
    for (auto m: playerlist){
        if (m->playeractive()){
        cout << "hit " << m->getName() << "?" << endl;
        string hit;
        cin >> hit;
        if (hit=="yes"){
        while (hit=="yes"){
            m->acceptCard(d.deal());
            
            if(m->won()){
                cout << m->getName() << " has won" << endl;
                exit(0);
            }
            else if(m->busted()){
                cout << m->getName() << " has busted" << endl;
                m->setInactive();
                continue;
            }
            
            cout << "hit " << m->getName() << " again?" << endl;
            cin >> hit;
            m->showCards();
        }}else{
    cout << m->getName() << " has stood" << endl;
        m->showCards();
        }
        
        
        }
    }
    

    return 0;
}
