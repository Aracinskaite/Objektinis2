#include "mylib.h"
#include <fstream>

void mano_funkcija() {
    vector<studentas> grupe;

    ifstream kursiokaitxt("C:/Users/araci/OneDrive/Desktop/c++/kursiokai.txt");

    if (!kursiokaitxt.is_open()) {
        cerr << "Error opening the file." << endl;
        return;
    }

    string line;
    getline(kursiokaitxt, line);
    while (getline(kursiokaitxt, line)) {
        studentas Studentas;
        stringstream ss(line);
        ss >> Studentas.vardas >> Studentas.pavarde;
       for (int i = 1; i <= 15; i++) {
        int pazymys;
        if (ss >> pazymys) {
            Studentas.pazymiai.push_back(pazymys);
            }
        }

        ss >> Studentas.egzaminas;
        grupe.push_back(Studentas);
    }

    cout << left << setw(10) << "Vardas" << setw(10) << "Pavarde";
    cout << setw(5) << "ND1"<< setw(5) << "ND2"<< setw(5) << "ND3"<< setw(5) << "ND4"<< setw(5) << "ND5"<< setw(5) << "ND6";
    cout << setw(5) << "ND7" << setw(5) << "ND8"<< setw(5) << "ND9"<< setw(5) << "ND10" << setw(5) << "ND11" << setw(5) << "ND12";
    cout << setw(5) << "ND13" << setw(5) << "ND14" << setw(5) << "ND15";
    cout << setw(10) << "Egzaminas" << endl;
    cout << string(105, '-') << endl;

    for (const studentas& Studentas : grupe) {
    cout << left << setw(10) << Studentas.vardas << setw(10) << Studentas.pavarde;
    for (int pazymys : Studentas.pazymiai) {
        cout << setw(5) << pazymys;
    }
    cout << setw(10) << Studentas.egzaminas << '\n';
}}

