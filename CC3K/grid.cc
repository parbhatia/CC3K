#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include "grid.h"
using namespace std;

void Grid::default_layout(string s) {
    ifstream file(s.c_str());
    string l;
    int row = 0;
    while(getline(file,l)) {
        stringstream line{l};
        ++row;
        char c;
        int col = 0;
        while(line >> c) {
            ++col;
            switch(c) {
                case '|':
                    cells[row][col] = new OBDCell(row,col,c);
                case '-':
                    cells[line_num][char_num] = new OBDCell(row,col,c);
                case '.':
                    cells[line_num][char_num] = new Floor(row,col);
                case '#':
                    cells[line_num][char_num] = new Bridge(row,col);
                case ' ':
                    cells[line_num][char_num] = new OBDCell(row,col,c);
                case '+':
                    cells[line_num][char_num] = new Door(row,col);
            }
        }
        col = 0; //reset column counter
    }
}

std::ostream &Grid::operator<<(std::ostream &out, const Grid &g) {
    
}
