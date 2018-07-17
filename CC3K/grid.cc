#include "grid.h"
#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void Grid::default_layout(string s) {
    ifstream file(s.c_str());
    string line;
    while(getline(file,line)) {
        cout << line << endl;
    }
}
