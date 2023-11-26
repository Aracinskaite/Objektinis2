#ifndef MYLIB_H
#define MYLIB_H

#include <iostream>
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
using std::invalid_argument;

double medianossk(const std::vector<int>& pazymiai);
double vidurkiosk(const std::vector<int>& pazymiai);

class Studentas {
private:
    string vardas_;
    string pavarde_;
    vector<int> pazymiai_;
    int egzaminas_;
    double rezultatas_;
    double rezultatas1_;

public:
    Studentas() : egzaminas_(0) {} // default konstruktorius

    void setVardas(const string& vardas) {vardas_ = vardas;}
    void setPavarde(const string& pavarde) {pavarde_ = pavarde;}
    void setPazymiai(const vector<int>& pazymiai) {pazymiai_ = pazymiai;}
    void addPazymys(int pazymys) {
        pazymiai_.push_back(pazymys);
    }
    void setEgzaminas(const int& egzaminas) {egzaminas_ = egzaminas;}
    void setRezultatas(const double& rezultatas) {rezultatas_ = rezultatas;}
    void setRezultatas1(const double& rezultatas1) {rezultatas1_ = rezultatas1;}

    std::istream& IveskStud(std::istream&);

    void Rezultatusk() {rezultatas_ = 0.4 * vidurkiosk(pazymiai_) + 0.6 * egzaminas_;}
    void Rezultatusk1() {rezultatas1_ = 0.4 * medianossk(pazymiai_) + 0.6 * egzaminas_;}

    // Getter for rezultatas_
    double getRezultatas() const {return rezultatas_;}
    double getRezultatas1() const {return rezultatas1_;}
    inline const string& getVardas() const {return vardas_;}
    inline const string& getPavarde() const {return pavarde_;}

    void clearPazymiai() { pazymiai_.clear(); }


    /*
    Studentas(std::istream& is);
    inline std::string vardas() const { return vardas_; }    // get'eriai, inline
    inline std::string pavarde() const { return pavarde_; }  // get'eriai, inline
    double galBalas(double (*) (const std::vector<int>&) = mediana) const;  // get'eriai
    std::istream& readStudent(std::istream&);  // set'eriai*/
};

bool compare(const Studentas&, const Studentas&);
bool comparePagalPavarde(const Studentas&, const Studentas&);
bool comparePagalEgza(const Studentas&, const Studentas&);

void mano_funkcija();
void mano_funkcija1();



void studFailas(int sarasas);
void nuskaitymas(std::vector<Studentas>& grupe, int sarasas);
void isvedimas(const std::vector<Studentas>& grupe, const std::string& filename);
void surusiuoti(std::vector<Studentas>& grupe, std::vector<Studentas>& vargsiukai, std::vector<Studentas>& galvociai, const std::string& pagalRusiuoti);
Studentas GeneruotiStudentai(int& numeris);
void isvedimasLaiko(double laikas1, double laikas2, double laikas3, double laikas4, double laikas5, int testsk, int sarasas);

#endif // MYLIB_H


