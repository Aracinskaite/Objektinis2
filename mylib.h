

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

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

struct studentas {
    string vardas, pavarde;
    vector<int> pazimiai;
    int egzaminas;
    float rezultatas;
};


void mano_funkcija();
void isvedimas();
