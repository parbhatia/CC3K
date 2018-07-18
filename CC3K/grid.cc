#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include "grid.h"
#include "cell.h"
using namespace std;

Grid::Grid() {
    read_layout("cc3k_emptyfloor.txt");
}

void Grid::read_layout(string s) {
    ifstream file(s.c_str()); //read lines
    string l;
    int row = 0;
    while(getline(file,l)) {
        stringstream line{l}; //read chars from lines
        ++row;
        char c;
        int col = 0;
        while(line >> c) {
            ++col;
            switch(c) {
                case '|':
                    cells[row][col] = new NullCell(row,col,c);
                case '-':
                    cells[row][col] = new NullCell(row,col,c);
                case '.':
                    cells[row][col] = new FloorCell(row,col);
                case '#':
                    cells[row][col] = new Bridge(row,col);
                case ' ':
                    cells[row][col] = new NullCell(row,col,c);
                case '+':
                    cells[row][col] = new Door(row,col);
            }
        }
        col = 0; //reset column counter
    } 
    
}

std::ostream &Grid::operator<<(std::ostream &out, const Grid &g) {
    for (int i=0; i<30; ++i) {
        for (int j=0; j<79; ++j) {
            out << cell[i][j].print();
        }
        out << endl;
    }
    out << endl;
    return out;
    
    //(*td) << out; for tomorrow
}
