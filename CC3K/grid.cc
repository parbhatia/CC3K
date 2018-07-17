#include "grid.h"
#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void Grid::default_layout(string s) {
    ifstream file(s.c_str());
    string l;
    int line_num;
    while(getline(file,l)) {
        stringstream line{l};
        char c;
        int char_num;
        while(line >> c) {
            switch(c) {
                case '|':
                    //do something
                case '-':
                    //do something
                case '.':
                    //do something
                case '#':
                    //do something
                case ' ':
                    //do something
                case '+':
                    //do something
            }
        }
    }
}
