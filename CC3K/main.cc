#include <iostream>
#include <stdexcept>
#include "grid.h"
#include "info.h"
using namespace std;

int main(int argc, const char * argv[]) {
    Grid g;
    string race;
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
                g.move_enemies();
                g.reset_cellsmoved();
                g.notify_player_observers();
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
                g.generate_potions();
                //gold
                g.generate_enemies();
                cout << g;
            } else if (cmd == "u") {
                cin >> cmd;
                if ((cmd == "no") | (cmd == "so") | (cmd == "ea") |
                    (cmd == "we") | (cmd == "ne") | (cmd == "nw") |
                    (cmd == "se") | (cmd == "sw")) {
                    g.use_pot(dir_map.at(cmd));
                    g.move_enemies();
                    g.reset_cellsmoved();
                    g.notify_player_observers();
                    cout << g;
                }
            } else if (cmd == "a") {
                cin >> cmd;
                if ((cmd == "no") | (cmd == "so") | (cmd == "ea") |
                    (cmd == "we") | (cmd == "ne") | (cmd == "nw") |
                    (cmd == "se") | (cmd == "sw")) {
                    //grid attacks player at direction cmd
                    g.attack_enemy(dir_map.at(cmd));
                    g.move_enemies();
                    g.reset_cellsmoved();
                    g.notify_player_observers();
                    cout << g;
                }
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


