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
#include <string>

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
using std::ifstream;
using std::cerr;
using std::stringstream;
using std::setprecision;
using std::numeric_limits;
using std::streamsize;
using std::cerr;
using std::ofstream;

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
void nuskaitymas(vector<studentas>& grupe, int sarasas);
void isvedimas(const vector<studentas>& grupe, const string& filename, int skaicius);
void surusiuoti(const vector<studentas>& grupe,  vector<studentas>& vargsiukai, vector<studentas>& galvociai);
studentas GeneruotiStudentai(int& numeris) ;
void isvedimasLaiko(double laikas1, double laikas2, double laikas3, double laikas4, double laikas5, double z, int testsk, int sarasas);

#endif;
