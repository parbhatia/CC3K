#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include "grid.h"
using namespace std;

Grid::Grid() {
    create_randomness(); //for random generation
    read_layout("/Users/par/Desktop/CC3K/CC3K/cc3k_emptyfloor.txt");
}

void Grid::reset_chambers() {
    //reset variales of chambers
    for (auto chamber: chambers) {
        chamber.clear();
    }
}

void Grid::reset_cells() {
    //clear old cells
    for (auto row: cells) {
        for (auto cell: row) {
            cell->clear();
        }
    }
    player_cell = nullptr;
}

void Grid::intialize_player(string type) {
    //pick chamber to generate player
    int chamb_num = chamber_picker();
    chambers[chamb_num].generate_player(type);
    player = chambers[chamb_num].give_player(); //grid keeps track of player
    race = player_name.at(type); //for grid's display purposes
    player_cell = chambers[chamb_num].give_playercell(); //ask chamber for player cell
}

void Grid::new_level() {
    reset_cells();
    reset_chambers();
    //pick chamber to generate new player location
    int chamb_num = chamber_picker();
    //put existing player on new cel
    chambers[chamb_num].generate_player_cell(player);
    //set new player_cell location
    player_cell = chambers[chamb_num].give_playercell(); //ask chamber for player cell
    if (level != 5) {
        ++level;
        generate_stairs();
    }
    //generate_potions();
    //generate_gold();
    generate_enemies();
}

Grid::~Grid() {
    //delete all cells
    for (auto row: cells) {
        for (auto cell: row) {
            delete cell; //calls cell's dtor
        }
    }
}

bool Grid::in_range(int row, int col) {
    return ((row>=0 && row<height-5) && (col >=0 && col<width));
}

void Grid::notify_player_observers() {
    try {
        player_cell->notifyObservers();
    }
    catch(Attack &o) {
        cout << "Enemy attacks player" << endl;
    }
}

void Grid::test_observers() {
    for (auto row:cells) {
        for (auto cell:row) {
            cout << "CELL: " << cell->sizeObservers() << endl;
        }
    }
}

void Grid::set_observers() {
    //iterate over cells, and set radius of each cell to observe others
    for (auto row : cells) {
        for (auto cell: row) {
            int x = cell->getCol();
            int y = cell->getRow();
            if (in_range(y+1,x-1)) {cell->attachObserver(cells[y+1][x-1]);}
            if (in_range(y+1,x)) {cell->attachObserver(cells[y+1][x]);}
            if (in_range(y+1,x+1)) {cell->attachObserver(cells[y+1][x+1]);}
            if (in_range(y,x-1)) {cell->attachObserver(cells[y][x-1]);}
            if (in_range(y,x+1)) {cell->attachObserver(cells[y][x+1]);}
            if (in_range(y-1,x-1)) {cell->attachObserver(cells[y-1][x-1]);}
            if (in_range(y-1,x)) {cell->attachObserver(cells[y-1][x]);}
            if (in_range(y-1,x+1)) {cell->attachObserver(cells[y-1][x+1]);}
        }
    }
}


/*bool Grid::has_player_test() {
    cout << player_cell->print() << endl;
    return player_cell != nullptr;
}

void Grid::cell_test() {
    for(auto row: cells) {
        for (auto cell: row) {
            cout << cell->getRow() << "," << cell->getCol() << endl;
        }
    }
}*/

void Grid::attack_enemy(Direction d) {
    int p_row = player_cell->getRow();
    int p_col = player_cell->getCol();
    Cell *new_cell = nullptr;
    //set new_cell position
    if (d == Direction::N) { new_cell = cells[p_row-1][p_col]; }
    else if (d == Direction::NW) { new_cell = cells[p_row-1][p_col-1]; }
    else if (d == Direction::NE) { new_cell = cells[p_row-1][p_col+1]; }
    else if (d == Direction::S) { new_cell = cells[p_row+1][p_col]; }
    else if (d == Direction::SW) { new_cell = cells[p_row+1][p_col-1]; }
    else if (d == Direction::SE) { new_cell = cells[p_row+1][p_col+1]; }
    else if (d == Direction::E) { new_cell = cells[p_row][p_col+1]; }
    else { new_cell = cells[p_row][p_col-1]; }
    //attack enemy
    try {
        player_cell->attack(*new_cell);
    }
    catch (Attack &o) {
        cout << "health is: " << o.health << endl;
        return;
    }
    catch (Stair_Cell &o) {
        new_level();
        return;
    }
    //only change player_cell if move was successful
    player_cell = new_cell;
}

void Grid::use_pot(Direction d) {
    //get cell to call use pot on
    Cell *new_cell = nullptr;
    new_cell = new_cell_pos(player_cell,d);
    //make player use pot
    try {
        player_cell->use(*new_cell);
    }
    catch (Poteffect &p) {
    }
}

void Grid::move_player(Direction d) {
    int p_row = player_cell->getRow();
    int p_col = player_cell->getCol();
    Cell *new_cell = nullptr;
    //set new_cell position
    if (d == Direction::N) { new_cell = cells[p_row-1][p_col]; }
    else if (d == Direction::NW) { new_cell = cells[p_row-1][p_col-1]; }
    else if (d == Direction::NE) { new_cell = cells[p_row-1][p_col+1]; }
    else if (d == Direction::S) { new_cell = cells[p_row+1][p_col]; }
    else if (d == Direction::SW) { new_cell = cells[p_row+1][p_col-1]; }
    else if (d == Direction::SE) { new_cell = cells[p_row+1][p_col+1]; }
    else if (d == Direction::E) { new_cell = cells[p_row][p_col+1]; }
    else { new_cell = cells[p_row][p_col-1]; }
    //move player
    try {
        player_cell->moveTo(*new_cell);
    }
    catch (Move_Unsuccessful &o) {
        return;
    }
    catch (Stair_Cell &o) {
        new_level();
        return;
    }
    //only change player_cell if move was successful
    player_cell = new_cell;
}

Direction Grid::direction_picker() {
    int rand_dir = rand() % 8;
    return Direction(rand_dir);
}

Cell* Grid::new_cell_pos(Cell *old_cell, Direction d) {
    int o_row = old_cell->getRow();
    int o_col = old_cell->getCol();
    Cell *new_cell = nullptr;
    if (d == Direction::N) {
        if (!in_range(o_row-1,o_col)) throw InvalidRange();
        new_cell = cells[o_row-1][o_col];
    }
    else if (d == Direction::NW) {
        if (!in_range(o_row-1,o_col-1)) throw InvalidRange();
        new_cell = cells[o_row-1][o_col-1];
    }
    else if (d == Direction::NE) {
        if (!in_range(o_row-1,o_col+1)) throw InvalidRange();
        new_cell = cells[o_row-1][o_col+1];
    }
    else if (d == Direction::S) {
        if (!in_range(o_row+1,o_col)) throw InvalidRange();
        new_cell = cells[o_row+1][o_col];
    }
    else if (d == Direction::SW) {
        if (!in_range(o_row+1,o_col-1)) throw InvalidRange();
        new_cell = cells[o_row+1][o_col-1];
    }
    else if (d == Direction::SE) {
        if (!in_range(o_row+1,o_col+1)) throw InvalidRange();
        new_cell = cells[o_row+1][o_col+1];
    }
    else if (d == Direction::E) {
        if (!in_range(o_row,o_col+1)) throw InvalidRange();
        new_cell = cells[o_row][o_col+1];
    }
    else {
        if (!in_range(o_row,o_col-1)) throw InvalidRange();
        new_cell = cells[o_row][o_col-1];
    }
    return new_cell;
}

void Grid::reset_cellsmoved() {
    for (auto row: cells) {
        for (auto cell: row) {
            cell->reset_has_moved();
        }
    }
}

void Grid::move_enemies() {
    //pick random direction
    for (auto row: cells) {
        for (auto cell: row) {
            //pick random direction
            Direction dir = direction_picker();
            Cell *new_cell = nullptr;
            try { //try getting new cell of valid range
                new_cell = new_cell_pos(cell,dir);
            }
            catch (InvalidRange &i) {
                continue;
            }
            //move enemy
            try {
                cell->moveTo(*new_cell);
            }
            catch (Move_Unsuccessful &o) {
                continue;
            }
        }
    }
}

/*void Grid::test_chambers() {
    int i = 1;
    for (auto it : chambers) {
        cout << "Chamber: " << i << " " << endl;
        ++i;
        it.print();
    }
}*/

void Grid::create_randomness() {
    srand((unsigned)time(NULL));
}

int Grid::chamber_picker() {
    return rand() % 5;
}

void Grid::generate_stairs() {
    int chamb_num = chamber_picker();
    chambers[chamb_num].generate_stairs();
}

void Grid::generate_enemies() {
    while(1) {
        int chamb_num = chamber_picker();
        try {
            chambers[chamb_num].generate_enemy();
        }
        catch(No_More_Enemies &) {
            return;
        }
    }
}

void Grid::generate_potions() {
    while(1) {
        int chamb_num = chamber_picker();
        try {
            chambers[chamb_num].generate_potion();
        }
        catch(No_More_Potions &) {
            return;
        }
    }
}

void Grid::read_layout(string s) {
    //create chambers
    for (int i = 0; i < 5; ++i) {
        chambers.emplace_back(Chamber());
    }
    
    ifstream file(s.c_str()); //read lines
    string l;
    int row = -1;
    while (getline(file, l)) {
        stringstream line_str{l}; //read chars from lines
        ++row;
        char c;
        int col = -1;
        vector<Cell *> line;
        while (line_str >> std::noskipws >> c) {
            ++col;
            switch (c) {
                case '|':
                    line.emplace_back(new NullCell(row, col, '|'));
                    break;
                case '-':
                    line.emplace_back(new NullCell(row, col, '-'));
                    break;
                case '1':
                {
                    Cell *new_cell = new FloorCell(row, col, '.');
                    line.emplace_back(new_cell);
                    chambers[0].add_cell(new_cell);
                    break;
                }
                case '2':
                {
                    Cell *new_cell2 = new FloorCell(row, col, '.');
                    line.emplace_back(new_cell2);
                    chambers[1].add_cell(new_cell2);
                    break;
                }
                case '3':
                {
                    Cell *new_cell3 = new FloorCell(row, col, '.');
                    line.emplace_back(new_cell3);
                    chambers[2].add_cell(new_cell3);
                    break;
                }
                case '4':
                {
                    Cell *new_cell4 = new FloorCell(row, col, '.');
                    line.emplace_back(new_cell4);
                    chambers[3].add_cell(new_cell4);
                    break;
                }
                case '5':
                {
                    Cell *new_cell5 = new FloorCell(row, col, '.');
                    line.emplace_back(new_cell5);
                    chambers[4].add_cell(new_cell5);
                    break;
                }
                case '#':
                    line.emplace_back(new Bridge(row, col, '#'));
                    break;
                case ' ':
                    line.emplace_back(new NullCell(row, col, ' '));
                    break;
                case '+':
                    line.emplace_back(new DoorCell(row, col, '+'));
                    break;
            }
        }
        cells.emplace_back(line);
        line.clear();
        col = 0; //reset column counter
    }
    set_observers();
}

std::ostream &operator<<(std::ostream &out, const Grid &g) {
    //print display
    for (int i = 0; i < g.height - 5; ++i) {
        for (int j = 0; j < g.width; ++j) {
            out << g.cells[i][j]->print();
        }
        if (i != 25) out << endl;
    }
    //print stats
    out.setf(ios::left);
    out << "Race: " << setw(8) << g.race << " Gold: " << setw(3) << g.gold;
    out.unsetf(ios::left);
    out.setf(ios::right);
    out << setw(50) << "Level: " << g.level << endl;
    out.unsetf(ios::right);
    out << "HP: " << g.player->getHp() << endl;
    out << "Atk: " << g.player->getAtk() << endl;
    out << "Def: " << g.player->getDef() << endl;
    out << "Action: " << endl;
    
    return out;
}
