#include <iostream>
#include <stdexcept>
#include "grid.h"
#include "info.h"
#include "merchant.h"
using namespace std;

std::vector <std::string> Character::actions;
bool Merchant::merchant_hostile = false;

//determines valid direction given direction
bool valid_direction(string dir) {
    if ((dir == "no") | (dir == "so") | (dir == "ea") |
        (dir == "we") | (dir == "ne") | (dir == "nw") |
        (dir == "se") | (dir == "sw")) {
        return true;
    } return false;
}

void create_randomness() {
    srand((unsigned)time(NULL));
}

int main(int argc, const char * argv[]) {
    create_randomness();
    while(true) { //handles multiple games
        Grid g;
        string race;
        //command interpreter
        bool stop_enemies = false;
        cin.exceptions(ios::eofbit|ios::failbit);
        string cmd;
        cout << "Please pick race." << endl;
        try {
            bool player_set = false;
            while (true) { //handles all moves in single game
                cin >> cmd;
                if (valid_direction(cmd)) {
                    if (!player_set) {
                        cout << "Please pick player." << endl;
                        continue;
                    }
                    g.move_player(dir_map.at(cmd));
                    if (!stop_enemies) g.move_enemies();
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
                    g.generate_gold();
                    g.generate_enemies();
                    //cout << g;
                } else if (cmd == "u") {
                    cin >> cmd;
                    if (valid_direction(cmd)) {
                        g.use_pot(dir_map.at(cmd));
                        if (!stop_enemies) g.move_enemies();
                    }
                } else if (cmd == "a") {
                    cin >> cmd;
                    if (valid_direction(cmd)) {
                        //grid attacks player at direction cmd
                        g.attack_enemy(dir_map.at(cmd));
                        if (!stop_enemies) g.move_enemies();
                    }
                } else if (cmd == "f") {
                    //toggle stop_enemies flag
                    if (!stop_enemies) stop_enemies = true;
                    else stop_enemies = false;
                } else if (cmd == "r") {
                    cout << "Restarting Game" << endl;
                    break;
                } else if (cmd == "q") {
                }
                g.notify_player_observers();
                g.reset_cellsmoved();
                cout << g;
                g.reset_actions();
                g.check_game(); //check after every move
            }
        }
        catch (Game_Won &g) {
            cout << "yay" << endl;
        }
        catch (Game_Lost &g) {
            cout << "Game Lost." << endl;
        }
        catch (ios::failure &) {
            return 0;
        }  // Any I/O failure quits
    }
}


