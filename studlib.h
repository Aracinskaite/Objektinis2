#pragma once
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
#include <numeric>

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

class Zmogus {
protected:
    std::string vardas_, pavarde_;

public:
    Zmogus() : vardas_(""), pavarde_("") {}

    Zmogus(const std::string& vardas, const std::string& pavarde)
        : vardas_(vardas), pavarde_(pavarde) {}

    virtual void setVardas(const std::string& vardas) = 0;
    virtual void setPavarde(const std::string& pavarde) = 0;

    virtual const std::string& getVardas() const = 0;
    virtual const std::string& getPavarde() const = 0;

    virtual ~Zmogus() = default;
};


class Studentas : public Zmogus {
protected:
    std::vector<int> pazymiai_;
    int egzaminas_;
    float rezultatas_;
    float rezultatas1_;
    int skaicius;

public:




    Studentas();
    Studentas(const std::vector<int>& pazymiai, int egzaminas);

    Studentas(const Studentas& other);
    Studentas& operator=(const Studentas& other);
    ~Studentas();


    friend std::istream& operator>>(std::istream& is, Studentas& studentas);
    friend std::ostream& operator<<(std::ostream& os, const Studentas& studentas);

    void generuoti();
    double vidurkiosk() const;
    double medianossk() const;


    const vector<int>& getPazymiai() const { return pazymiai_; }
    int getEgzaminas() const { return egzaminas_; }
    float getRezultatas() const { return rezultatas_; }
    float getRezultatas1() const { return rezultatas1_; }


    void setPazymiai(int pazymys) {pazymiai_.push_back(pazymys);}
    void setEgzaminas(int egzaminas) { egzaminas_ = egzaminas; }
    void setRezultatas(float rezultatas) { rezultatas_ = rezultatas; }
    void setRezultatas1(float rezultatas1) { rezultatas1_ = rezultatas1; }

    static void studFailas(int sarasas);
    static void nuskaitymas(list<Studentas>& grupe, int sarasas);
    static void isvedimas(const list<Studentas>& grupe, const string& filename);
    static void surusiuoti(list<Studentas>& grupe, list<Studentas>& vargsiukai, const string& pagalRusiuoti);
    static void isvedimasLaiko(double laikas1, double laikas2, double laikas3, double laikas4, double laikas5, int testsk, int sarasas);
    static void mano_funkcija1();
    static void mano_funkcija();



};


#endif // MYLIB_H




