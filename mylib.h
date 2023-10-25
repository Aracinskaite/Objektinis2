#ifndef MYLIB_H
#define MYLIB_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <fstream>
#include <sstream>
#include <ctime>
#include <list>

using std::cout;
using std::list;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::setw;
using std::fixed;
using std::left;
using std::right;
using std::setprecision;
using std::ifstream;
using std::cerr;
using std::stringstream;
using std::setprecision;
using std::numeric_limits;
using std::streamsize;
using std::cerr;
using std::ofstream;
using std::invalid_argument;

struct studentas {
    string vardas, pavarde;
    vector<int> pazymiai;
    int egzaminas;
    float rezultatas;
    float rezultatas1;
};


void mano_funkcija();
void mano_funkcija1();

void studFailas(int sarasas);
void nuskaitymas(list<studentas>& grupe, int sarasas);
void isvedimas(const list<studentas>& grupe, const string& filename);
void surusiuoti(list<studentas>& grupe, list<studentas>& vargsiukai, list<studentas>& galvociai, const string& pagalRusiuoti);
void isvedimasLaiko(double laikas1, double laikas2, double laikas3, double laikas4, double laikas5, int testsk, int sarasas);

#endif;
