//Headeree

#include <iostream>
#include <vector>
#include "player.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
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
    

    return 0;
}
