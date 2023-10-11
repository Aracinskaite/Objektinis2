#include "mylib.h"
#include "timer.h"

double vidurkiosk(const vector<int>& pazymiai) {
    assert(!pazymiai.empty());
    int dydis = pazymiai.size();
    int sum = 0;
    for (int num : pazymiai) {
        sum += num;
    }
    return static_cast<double>(sum) / dydis;
}

double medianossk(const vector<int>& pazymiai) {
    assert(!pazymiai.empty());
    vector<int> surusiuota = pazymiai;
    sort(surusiuota.begin(), surusiuota.end());
    int dydis = surusiuota.size();
    if (dydis % 2 == 0) {
        int vid1 = surusiuota[dydis / 2 - 1];
        int vid2 = surusiuota[dydis / 2];
        return static_cast<double>(vid1 + vid2) / 2.0;
    } else {
        return static_cast<double>(surusiuota[dydis / 2]);
    }
}


void nuskaitymas(vector<studentas>& grupe) {
    string failopavadinimas;
    cout << "Iveskite savo failo pavadinima:";
    cin >> failopavadinimas;

    ifstream failas(failopavadinimas);

    if (!failas.is_open()) {
        cerr << "Failo atidaryti nepavyko" << endl;
    }
    string eilute;
    getline(failas, eilute);

    while (getline(failas, eilute)) {
        studentas Studentas;
        stringstream ss(eilute);
        ss >> Studentas.vardas >> Studentas.pavarde;
        for (int i = 0; i < 10; i++) {
            int pazymys;
            if (ss >> pazymys) {
                Studentas.pazymiai.push_back(pazymys);
            }
        }
        ss >> Studentas.egzaminas;

        double galutinis = 0.4 * medianossk(Studentas.pazymiai) + 0.6 * Studentas.egzaminas;
        Studentas.rezultatas = galutinis;
        double galutinis1 = 0.4 * vidurkiosk(Studentas.pazymiai) + 0.6 * Studentas.egzaminas;
        Studentas.rezultatas1 = galutinis1;
        grupe.push_back(Studentas);
    }
}

void surusiuoti(const vector<studentas>& grupe, int skaicius, vector<studentas>& vargsiukai, vector<studentas>& galvociai) {
    for (const auto& a : grupe) {
        if (a.rezultatas < 5.0) {
            vargsiukai.push_back(a);
        } else {
            galvociai.push_back(a);
        }
    }
}




void isvedimas(const vector<studentas>& grupe, const string& failas, int skaicius) {
    ofstream output(failas);

    if (!output.is_open()) {
        cerr << "Failed to open output file: " << failas << endl;
        return;
    }

    if (skaicius == 1) {
        output << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(15) << "Galutinis (Med.)" << endl;
    } else if (skaicius == 2) {
        output << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(15) << "Galutinis (Vid.)" << endl;
    }

    output << string(55, '-') << endl;

    for (const auto& a : grupe) {
        output << left << setw(20) << a.vardas << setw(20) << a.pavarde;
        if (skaicius == 1) {
            output << fixed << setprecision(2) << setw(15) << a.rezultatas << endl;
        } else if (skaicius == 2) {
            output << fixed << setprecision(2) << setw(15) << a.rezultatas1 << endl;
        }
    }

    output.close();
}

studentas GeneruotiStudentai() {
    studentas Studentas;
    static int numeris = 1;
    Studentas.vardas = "Vardas" + std::to_string(numeris);
    Studentas.pavarde = "Pavarde" + std::to_string(numeris);
    int pazymiuSkaicius = 10;
    for (int i = 0; i < pazymiuSkaicius; i++) {
        Studentas.pazymiai.push_back(rand() % 10 + 1);
    }
    Studentas.egzaminas = rand() % 10 + 1;

    numeris++;
    return Studentas;
}



void studFailas(int sarasas) {
    ofstream kuriamasFailas(std::to_string(sarasas) + ".txt");
    if (!kuriamasFailas) {
        cerr << "Failed to create the file." << endl;
        return;
    }

    srand(time(nullptr));

    kuriamasFailas << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
    for (int a = 1; a <= 10; a++) {
        kuriamasFailas << left << setw(5) << "ND" + std::to_string(a);
    }
    kuriamasFailas << left << setw(10) << "Egzaminas" << endl;

    for (int i = 0; i < sarasas; i++) {
        studentas Studentas = GeneruotiStudentai();
        kuriamasFailas << left << setw(20) << Studentas.vardas << setw(20) << Studentas.pavarde;

        for (int j = 0; j < Studentas.pazymiai.size(); j++) {
            kuriamasFailas << left << setw(5) << Studentas.pazymiai[j];
        }

        kuriamasFailas << left << setw(10) << Studentas.egzaminas;

        kuriamasFailas << endl;
    }

    kuriamasFailas.close();
}

