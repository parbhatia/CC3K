#include <iostream>
#include <stdexcept>
#include "grid.h"
#include "info.h"
using namespace std;

int main(int argc, const char * argv[]) {
    Grid g;
    string race;
    //cin >> race;
    cout << g;
    //g.test_chambers();
    g.generate_enemies();
    cout << g;
    
    //command interpreter
    
    /*
    cin.exceptions(ios::eofbit|ios::failbit);
    string cmd;
    
    
    
    try {
        while (true) {
            cin >> cmd;
            if ((cmd == "no") | (cmd == "so") | (cmd == "ea") |
                (cmd == "we") | (cmd == "ne") | (cmd == "nw") |
                (cmd == "se") | (cmd == "sw")) {
                //grid moves player at direction cmd
                g.move_player(dir_map[cmd]);
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
                g.use_pot_player(dir_map[dir]);
            } else if (cmd == "a") {
            } else if (cmd == "f") {
            } else if (cmd == "r") {
            } else if (cmd == "q") {
            }
        }
    }
    catch (ios::failure &) {
        return 0;
    }  // Any I/O failure quits
     */
}


