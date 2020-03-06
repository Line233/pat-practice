//
#define DEBUG
#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
#ifdef DEBUG
    ifstream ifile;
    ofstream ofile;
    ifile.open("data.txt");
    ofile.open("1135.txt");
    cout.rdbuf(ofile.rdbuf());
    cin.rdbuf(ifile.rdbuf());
#endif

#ifdef DEBUG
    ifile.close();
    ofile.close();
#endif
}