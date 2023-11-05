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

void generuoti(studentas &Studentas) {
    int ndskaicius = rand() % 11;
    cout << "Pazymiai: ";
    for (int i = 0; i < ndskaicius; i++) {
        int pazymys = rand() % 11;
        cout << pazymys<< " ";
        Studentas.pazymiai.push_back(pazymys);
    }
    cout << endl;
    Studentas.egzaminas = rand() % 11;
    cout << "Egzamino pazymys: "<< Studentas.egzaminas<<endl;

}


void mano_funkcija1() {
    string failopavadinimas;
    cout << "Iveskite  savo failo pavadinima:";
    cin >> failopavadinimas;

    vector<studentas> grupe;
    ifstream failas(failopavadinimas);

    if (!failas.is_open()) {
        cerr << "Failo atidaryti nepavyko" << endl;
    }
    string eilute;
    getline(failas, eilute);
    stringstream eilute1(eilute);
    string elem;
    int num = 0;
    while (eilute1 >> elem) {
        num++;
    }
    num = num-3;
    while (getline(failas, eilute)) {
        studentas Studentas;
        stringstream ss(eilute);
        ss >> Studentas.vardas >> Studentas.pavarde;
        for (int i = 1; i <= num; i++) {
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
    sort(grupe.begin(), grupe.end(), [](const studentas& a, const studentas& b) {
        if (a.vardas != b.vardas) {
            return a.vardas < b.vardas;
        } else {
            return a.pavarde < b.pavarde;
        }
    });
    cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis (Vid.)"<< left << setw(20) << "Galutinis (Med.)"  << endl;
    cout << string(80, '-') << endl;
    for (auto& a : grupe) {
        cout << left << setw(20) << a.vardas << left << setw(20) << a.pavarde;
        cout << left << fixed << setprecision(2) << setw(20) << a.rezultatas1;
        cout << left << fixed << setprecision(2) << setw(20) << a.rezultatas << endl;
        }
}


void mano_funkcija(){
    int studsk;
    while (true) {
        try {
            cout << "Iveskite studentu skaiciu: ";
            cin >> studsk;
            if (cin.fail()) {
                throw invalid_argument("Klaida: ivestas ne skaicius.");
            }
            break;
        } catch (const invalid_argument &e) {
            cout << e.what() << " Prasome dar karta ivesti studentu skaiciu." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    vector<studentas> grupe;

    for (int j = 0; j < studsk; j++) {
        studentas Studentas;

        cout << "Ivesk varda ir pavarde: ";
        cin >> Studentas.vardas >> Studentas.pavarde;

        int ivedimas;
        cout << "Jei norite ivesti pazymius, rasykite 1, jei norite, kad sugeneruotu, rasykite 2: ";
        while (true) {
            if (cin >> ivedimas && (ivedimas == 1 || ivedimas == 2)) {
                break;
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Klaida: ivestas ne skaicius arba ne 1 ir ne 2. Praðome dar karta ivesti skaiciu 1 - jei norite ivesti pazymius, 2 - jei norite, kad sugeneruotu: " << endl;
            }
        }
        if (ivedimas == 1) {
            cout << "Iveskite pazymius (baigti su -1): ";
            int k;
            while (true) {
                while (!(cin >> k)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Klaida: ivestas ne skaicius. Prasome dar karta ivesti pazymi." << endl;
                }
                if (k == -1) {
                    break;
                }
                Studentas.pazymiai.push_back(k);
            }
            int p;
            cout << "Iveskite egzamina: ";
            while (!(cin >> p)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Klaida: ivestas ne skaicius. Prasome dar karta ivesti egzamino pazymi." << endl;
            }
            Studentas.egzaminas = p;
        }else if (ivedimas == 2) {
            generuoti(Studentas);
        }
        double galutinis = 0.4 * medianossk(Studentas.pazymiai) + 0.6 * Studentas.egzaminas;
        Studentas.rezultatas = galutinis;
        double galutinis1 = 0.4 * vidurkiosk(Studentas.pazymiai) + 0.6 * Studentas.egzaminas;
        Studentas.rezultatas1 = galutinis1;
        grupe.push_back(Studentas);
        Studentas.pazymiai.clear();
    }

    sort(grupe.begin(), grupe.end(), [](const studentas& a, const studentas& b) {
        if (a.vardas != b.vardas) {
            return a.vardas < b.vardas;
        } else {
            return a.pavarde < b.pavarde;
        }
    });

    int skaicius;
    cout << "Jei norite galutini bala skaiciuti pagal mediana rasykite 1, jei norite pagal vidurki rasykite 2:";
    while (!(cin >> skaicius) || (skaicius != 1 && skaicius != 2)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Klaida: ivestas ne skaicius arba ne 1 ir ne 2. Prasome dar karta ivesti skaiciu 1 - galutinis skaiciuojams nuo medianos, 2 - galutinis skaiciuojamas nuo vidurkio" << endl;
    }
    if (skaicius == 1) {
        cout << left << setw(20) << "Adresas" << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(15) << "Galutinis (Med.)" << endl;
    } else if (skaicius == 2) {
        cout << left << setw(20) << "Adresas" << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(15) << "Galutinis (Vid.)" << endl;
    }

    cout << string(75, '-') << endl;

    for (const auto& a : grupe) {
        cout << left << setw(20) << &a << setw(20) << a.vardas << setw(20) << a.pavarde;
        if (skaicius == 1) {
            cout << fixed << setprecision(2) << setw(15) << a.rezultatas << endl;
        } else if (skaicius == 2) {
            cout << fixed << setprecision(2) << setw(15) << a.rezultatas1 << endl;
        }
}}

void nuskaitymas(vector<studentas>& grupe, int sarasas) {
    string failopavadinimas = std::to_string(sarasas) + ".txt";
    ifstream failas(failopavadinimas);
    if (!failas.is_open()) {
        cerr << "Failo atidaryti nepavyko" << endl;
        return;
    }
    string eilute;
    getline(failas, eilute);
    stringstream eilute1(eilute);
    string elem;
    int num = 0;
    while (eilute1 >> elem) {
        num++;
    }
    num = num-3;
    while (getline(failas, eilute)) {
        studentas Studentas;
        stringstream ss(eilute);
        ss >> Studentas.vardas >> Studentas.pavarde;
        for (int i = 1; i < num; i++) {
            int pazymys;
            if (ss >> pazymys) {
                Studentas.pazymiai.push_back(pazymys);
            }
        }
        ss >> Studentas.egzaminas;

        double galutinis1 = 0.4 * vidurkiosk(Studentas.pazymiai) + 0.6 * Studentas.egzaminas;
        Studentas.rezultatas1 = galutinis1;
        grupe.push_back(Studentas);
    }
}


void surusiuoti(vector<studentas>& grupe, vector<studentas>& vargsiukai, vector<studentas>& galvociai, const string& pagalRusiuoti) {
    if (pagalRusiuoti == "vardas") {
        sort(grupe.begin(), grupe.end(), [](const studentas& a, const studentas& b) {
            return a.vardas < b.vardas;
        });
    } else if (pagalRusiuoti == "pavarde") {
        sort(grupe.begin(), grupe.end(), [](const studentas& a, const studentas& b) {
            return a.pavarde < b.pavarde;
        });
    } else if (pagalRusiuoti == "galutinis") {
        sort(grupe.begin(), grupe.end(), [](const studentas& a, const studentas& b) {
            return a.rezultatas1 < b.rezultatas1;
        });
    }
    for (const auto& a : grupe) {
        if (a.rezultatas1 < 5.0) {
            vargsiukai.push_back(a);
        } else {
            galvociai.push_back(a);
        }
}}





void isvedimas(const vector<studentas>& grupe, const string& failas) {
    ofstream output(failas);
    if (!output.is_open()) {
        cerr << "Failed to open output file: " << failas << endl;
        return;
    }

    output << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(15) << "Galutinis (Vid.)" << endl;
    output << string(55, '-') << endl;

    for (const auto& a : grupe) {
        output << left << setw(20) << a.vardas << setw(20) << a.pavarde;
        output << fixed << setprecision(2) << setw(15) << a.rezultatas1 << endl;

    }
    output.close();
}



void studFailas(int sarasas) {
    int numeris = 1;
    ofstream kuriamasFailas(std::to_string(sarasas) + ".txt");
    if (!kuriamasFailas) {
        cerr << "Failed to create the file." << endl;
        return;
    }
    kuriamasFailas << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
    for (int a = 1; a <= 10; a++) {
        kuriamasFailas << left << setw(5) << "ND" + std::to_string(a);
    }
    kuriamasFailas << left << setw(10) << "Egzaminas" << endl;

    for (int i = 1; i <= sarasas; ++i) {
        string vardas = "Vardas" + std::to_string(i);
        string pavarde = "Pavarde" + std::to_string(i);

        kuriamasFailas << left << setw(20) << vardas << setw(20) << pavarde;

        for (int j = 0; j < 10; ++j) {
            kuriamasFailas << setw(5) << rand() % 11;
        }

        kuriamasFailas << setw(10) << rand() % 11 << endl;
    }

    kuriamasFailas.close();
}

void isvedimasLaiko(double laikas1, double laikas2, double laikas3, double laikas4, double laikas5, int testsk, int sarasas) {
    laikas1 /= testsk;
    laikas2 /= testsk;
    laikas3 /= testsk;
    laikas4 /= testsk;
    laikas5 /= testsk;

    cout << sarasas << " studentu nuskaityti vidutiniskai uztruko: " << fixed << setprecision(2) << (laikas1) << " s\n";
    cout << sarasas << " studentu dalijimas i dvi grupes vidutinis laikas: " << fixed << setprecision(2) << (laikas3) << " s\n";
    cout << sarasas << " irasu 'vargsiukai' irasymo i faila vidutinis laikas: " << fixed << setprecision(2) << (laikas4) << " s\n";
    cout << sarasas << " irasu 'galvociai' irasymo i faila vidutinis laikas: " << fixed << setprecision(2) << (laikas5) << " s\n";
    cout << sarasas << " irasu testo vidutinis laikas: " << fixed << setprecision(2) << (laikas2) << " s\n";
    cout << "\n";
}
