#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include "grid.h"
using namespace std;

Grid::Grid() {
    read_layout("/Users/par/Desktop/CC3K/CC3K/cc3k_emptyfloor.txt");
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

void Grid::intialize_player(string type) {
    //randomly pick chamber to generate enemy
    srand((unsigned)time(NULL));
    int chamb_num = rand() % 5;
    chambers[chamb_num].generate_player(type);
    race = type;
}

void Grid::use_pot_player(Direction d) {
    if (d == Direction::N) {}
}

/*void Grid::move_player(Direction d) {
    if (d == Direction::N) {
        if (cells[])
    }
}*/

void Grid::test_chambers() {
    int i = 1;
    for (auto it : chambers) {
        cout << "Chamber: " << i << " " << endl;
        ++i;
        it.print();
    }
}

void Grid::generate_enemies() {
    while(true) {
        //randomly pick chamber to generate enemy
        srand((unsigned)time(NULL));
        int chamb_num = rand() % 5;
        chambers[chamb_num].generate_enemy();
        //chambers[chamb_num].generate_potions();
        //chambers[chamb_num].generate_gold();
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
    out << "Race: " << left << setw(63) << g.race
    << right << setw(8) << "Level: " << g.level << endl;
    out << "HP: " << endl;
    out << "Atk: " << endl;
    out << "Def: " << endl;
    out << "Action: " << endl;
    
    return out;
}
