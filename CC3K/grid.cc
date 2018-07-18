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
                case '-':
                    line.emplace_back(new NullCell(row,col,c));
                case '.':
                    line.emplace_back(new FloorCell(row,col));
                case '#':
                    line.emplace_back(new Bridge(row,col));
                case ' ':
                    line.emplace_back(new NullCell(row,col,c));
                case '+':
                    line.emplace_back(new DoorCell(row,col));
            }
        }
        cells.emplace_back(line);
        line.clear();
        col = 0; //reset column counter
    } 
    
}

std::ostream &operator<<(std::ostream &out, const Grid &g) {
    for (auto it: g.cells) {
        for (auto it2: it) {
            out << it2->print();
        }
        out << endl;
    }
    return out;
    
}
