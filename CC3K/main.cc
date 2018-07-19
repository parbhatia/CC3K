#include <iostream>
#include <stdexcept>
#include <map>
#include "grid.h"

//will put in seperate file later
enum class Direction { NW, N, NE, W, E, SW, S, SE };
map<string, Direction> dir_map = {
    {"no", Direction::N},
    {"so", Direction::S},
    {"ea", Direction::E},
    {"we", Direction::W},
    {"ne", Direction::NE},
    {"nw", Direction::NW},
    {"se", Direction::SE},
    {"sw", Direction::SW},
};


int main(int argc, const char * argv[]) {
    Grid g;
    string race;
    //cin >> race;
    cout << g;
    
    //command interpreter
  
    
    cin.exceptions(ios::eofbit|ios::failbit);
    string cmd;
    try {
        while (true) {
            cin >> cmd;
            if (cmd == "no") {
                //grid moves player N
            } else if (cmd == "so") {
                //grid moves player S
            } else if (cmd == "ea") {
                //grid moves player E
            } else if (cmd == "we") {
                //grid moves player W
            } else if (cmd == "ne") {
                //grid moves player NE
            } else if (cmd == "nw") {
                //grid moves player NW
            } else if (cmd == "se") {
                //grid moves player SE
            } else if (cmd == "sw") {
                //grid moves player SW
            } else if (cmd == "s") {
                g.intialize_player(cmd);
            } else if (cmd == "d") {
                g.intialize_player(cmd);
            } else if (cmd == "v") {
                g.intialize_player(cmd);
            } else if (cmd == "g") {
                g.intialize_player(cmd);
            } else if (cmd == "t") {
                g.intialize_player(cmd);
            } else if (cmd == "u") {
                string dir;
                cin >> dir;
                //make player use potion at direction dir
                g.player->use(dir_map[dir]);
            } else if (cmd == "a") {
            } else if (cmd == "f") {
            } else if (cmd == "r") {
            } else if (cmd == "q") {
            }
        }
    }
}


