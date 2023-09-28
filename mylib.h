#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>



using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::setw;
using std::fixed;
using std::left;
using std::right;
using std::setprecision;
using std::numeric_limits;
using std::streamsize;
using std::cerr;

struct studentas {
    string vardas, pavarde;
    vector<int> pazymiai;
    int egzaminas;
    float rezultatas;
};


void mano_funkcija();

