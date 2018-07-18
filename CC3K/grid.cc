#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include "grid.h"
#include "cell.h"
using namespace std;

Grid::Grid() {
    read_layout("/Users/par/Desktop/CC3K/CC3K/cc3k_emptyfloor.txt");
}

void Grid::read_layout(string s) {
    //create chambers
    for (int i=0; i<5; ++i) {
        chambers.emplace_back(Chamber());
    }
    
    ifstream file(s.c_str()); //read lines
    string l;
    int row = -1;
    while(getline(file,l)) {
        stringstream line_str{l}; //read chars from lines
        ++row;
        char c;
        int col = -1;
        vector <Cell*> line;
        while(line_str >> std::noskipws >> c) {
            ++col;
            switch(c) {
                case '|':
                    line.emplace_back(new NullCell(row,col,c));
                    break;
                case '-':
                    line.emplace_back(new NullCell(row,col,c));
                    break;
                case '1':
                    line.emplace_back(new FloorCell(row,col));
                    chambers[0].emplace_back(cells[row][col]);
                    break;
                case '2':
                    line.emplace_back(new FloorCell(row,col));
                    chambers[1].emplace_back(cells[row][col]);
                    break;
                case '3':
                    line.emplace_back(new FloorCell(row,col));
                    chambers[2].emplace_back(cells[row][col]);
                    break;
                case '4':
                    line.emplace_back(new FloorCell(row,col));
                    chambers[3].emplace_back(cells[row][col]);
                    break;
                case '5':
                    line.emplace_back(new FloorCell(row,col));
                    chambers[4].emplace_back(cells[row][col]);
                    break;
                case '#':
                    line.emplace_back(new Bridge(row,col));
                    break;
                case ' ':
                    line.emplace_back(new NullCell(row,col,c));
                    break;
                case '+':
                    line.emplace_back(new DoorCell(row,col));
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
    for (int i=0; i<25; ++i) {
        for (int j=0; j<79; ++j) {
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
