#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include "grid.h"
using namespace std;

Grid::Grid() {
    read_layout("/Users/par/Desktop/CC3K/CC3K/cc3k_emptyfloor.txt");
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
    return ((row>=0 && row<height-5) && (col >0 && col<width));
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


bool Grid::has_player_test() {
    return player_cell == nullptr;
}

void Grid::cell_test() {
    for(auto row: cells) {
        for (auto cell: row) {
            cout << cell->getRow() << "," << cell->getCol() << endl;
        }
    }
}

void Grid::intialize_player(string type) {
    //pick chamber to generate player
    int chamb_num = chamber_picker();
    chambers[chamb_num].generate_player(type);
    race = player_name.at(type); //for grid's display purposes
    player_cell = chambers[chamb_num].give_playercell(); //ask chamber for player cell
}

void Grid::use_pot(Direction d) {
    if (d == Direction::N) {}
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
    //move player if newcell is not empty
    if (!new_cell->isOccupied()) {
        player_cell->moveTo(*new_cell);
    }
}

void Grid::test_chambers() {
    int i = 1;
    for (auto it : chambers) {
        cout << "Chamber: " << i << " " << endl;
        ++i;
        it.print();
    }
}

void Grid::create_randomness() {
    srand((unsigned)time(NULL));
}

int Grid::chamber_picker() {
    return rand() % 5;
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

void Grid::read_layout(string s) {
    //create chambers
    for (int i = 0; i < 5; ++i) {
        chambers.emplace_back(Chamber());
    }
    create_randomness(); //for random generation
    
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
                    line.emplace_back(new NullCell(row, col, c));
                    break;
                case '-':
                    line.emplace_back(new NullCell(row, col, c));
                    break;
                case '1':
                {
                    Cell *new_cell = new FloorCell(row, col);
                    line.emplace_back(new_cell);
                    chambers[0].add_cell(new_cell);
                    break;
                }
                case '2':
                {
                    Cell *new_cell2 = new FloorCell(row, col);
                    line.emplace_back(new_cell2);
                    chambers[1].add_cell(new_cell2);
                    break;
                }
                case '3':
                {
                    Cell *new_cell3 = new FloorCell(row, col);
                    line.emplace_back(new_cell3);
                    chambers[2].add_cell(new_cell3);
                    break;
                }
                case '4':
                {
                    Cell *new_cell4 = new FloorCell(row, col);
                    line.emplace_back(new_cell4);
                    chambers[3].add_cell(new_cell4);
                    break;
                }
                case '5':
                {
                    Cell *new_cell5 = new FloorCell(row, col);
                    line.emplace_back(new_cell5);
                    chambers[4].add_cell(new_cell5);
                    break;
                }
                case '#':
                    line.emplace_back(new Bridge(row, col));
                    break;
                case ' ':
                    line.emplace_back(new NullCell(row, col, c));
                    break;
                case '+':
                    line.emplace_back(new DoorCell(row, col));
                    break;
            }
        }
        cells.emplace_back(line);
        line.clear();
        col = 0; //reset column counter
    }
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
    out << "HP: " << endl;
    out << "Atk: " << endl;
    out << "Def: " << endl;
    out << "Action: " << endl;
    
    return out;
}
