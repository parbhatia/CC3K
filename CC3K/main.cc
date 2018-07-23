#include <iostream>
#include <stdexcept>
#include "grid.h"
#include "info.h"
using namespace std;

int main(int argc, const char * argv[]) {
    Grid g;
    string race;
    //cout << g;
    //command interpreter
    cin.exceptions(ios::eofbit|ios::failbit);
    string cmd;
    try {
        bool player_set = false;
        while (true) {
            cin >> cmd;
            if ((cmd == "no") | (cmd == "so") | (cmd == "ea") |
                (cmd == "we") | (cmd == "ne") | (cmd == "nw") |
                (cmd == "se") | (cmd == "sw")) {
                if (!player_set) {
                    cout << "Please pick player." << endl;
                    continue;
                }
                //grid moves player at direction cmd
                g.move_player(dir_map.at(cmd));
                cout << g;
            } else if ((cmd == "s") | (cmd == "d") | (cmd == "v") |
                       (cmd == "g") | (cmd == "t")) {
                if (player_set) {
                    cout << "Player already picked." << endl;
                    continue;
                }
                player_set = true;
                g.intialize_player(cmd);
                g.generate_stairs();
                //stairway location
                //potions
                //gold
                g.generate_enemies();
                cout << g;
            } else if (cmd == "u") {
                string dir;
                cin >> dir;
                //make player use potion at direction dir
                g.use_pot(dir_map.at(dir));
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
}


