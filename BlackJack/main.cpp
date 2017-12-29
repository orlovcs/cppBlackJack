//Headeree

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
        cout << "hit " << m->getName() << "?" << endl;
        string hit;
        cin >> hit;
        if (hit=="yes"){
        while (hit=="yes"){
            m->acceptCard(d.deal());
            cout << "hit " << m->getName() << " again?" << endl;
            cin >> hit;
            m->showCards();
        }}else{
    cout << m->getName() << " has folded" << endl;
        m->showCards();
        }
    }
    

    return 0;
}
