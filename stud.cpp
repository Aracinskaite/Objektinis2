#include "studlib.h"
#include "timer.h"

std::istream& Studentas::IveskStud(std::istream& is) {
    is >> vardas_ >> pavarde_;
    return is;
}

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

void generuoti(Studentas &studentas) {
    int ndskaicius = rand() % 11;
    cout << "Pazymiai: ";
    for (int i = 0; i < ndskaicius; i++) {
        int pazymys = rand() % 11;
        cout << pazymys << " ";
        studentas.addPazymys(pazymys);
    }
    cout << std::endl;

    int egzaminas = rand() % 11;
    cout << "Egzamino pazymys: " << egzaminas << std::endl;
    studentas.setEgzaminas(egzaminas);
}



void mano_funkcija1() {

    string failopavadinimas;
    cout << "Iveskite savo failo pavadinima:";
    cin >> failopavadinimas;

    vector<Studentas> grupe;
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
    num = num - 3;

    while (getline(failas, eilute)) {
        stringstream ss(eilute);
        Studentas studentas;

        string vardas, pavarde;
        ss >> vardas >> pavarde;
        studentas.setVardas(vardas);
        studentas.setPavarde(pavarde);
        vector<int> pazymiai;
        for (int i = 1; i <= num; i++) {
            int pazymys;
            if (ss >> pazymys) {
                pazymiai.push_back(pazymys);
            }
        }
        studentas.setPazymiai(pazymiai);

        int egzaminas;
        ss >> egzaminas;
        studentas.setEgzaminas(egzaminas);
        studentas.Rezultatusk();
        studentas.Rezultatusk1();
        grupe.push_back(studentas);
    }

    sort(grupe.begin(), grupe.end(), [](const Studentas& a, const Studentas& b) {
        if (a.getVardas() != b.getVardas()) {
            return a.getVardas() < b.getVardas();
        } else {
            return a.getPavarde() < b.getPavarde();
        }
    });


    cout << std::left << std::setw(20) << "Vardas"
        << std::left << std::setw(20) << "Pavarde"
        << std::left << std::setw(20) << "Galutinis (Vid.)"
        << std::left << std::setw(20) << "Galutinis (Med.)" << std::endl;
    cout << std::string(80, '-') << std::endl;

    for (const auto& studentas : grupe) {
        cout << std::left << std::setw(20) << studentas.getVardas()
            << std::left << std::setw(20) << studentas.getPavarde()
            << std::left << std::setw(20) << studentas.getRezultatas()
            << std::left << std::setw(20) << studentas.getRezultatas1() << std::endl;
}}



void mano_funkcija() {
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

    vector<Studentas> grupe;

    for (int j = 0; j < studsk; j++) {
        Studentas studentas;

        cout << "Ivesk varda ir pavarde: ";
        studentas.IveskStud(cin);
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
                studentas.addPazymys(k);
            }

            int p;
            cout << "Iveskite egzamina: ";
            while (!(cin >> p)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Klaida: ivestas ne skaicius. Prasome dar karta ivesti egzamino pazymi." << endl;
            }
            studentas.setEgzaminas(p);
        } else if (ivedimas == 2) {
            generuoti(studentas);
        }
        studentas.Rezultatusk();
        studentas.Rezultatusk1();

        grupe.push_back(studentas);
        studentas.clearPazymiai();
    }

    sort(grupe.begin(), grupe.end(), [](const Studentas& a, const Studentas& b) {
        if (a.getVardas() != b.getVardas()) {
            return a.getVardas() < b.getVardas();
        } else {
            return a.getPavarde() < b.getPavarde();
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
        cout << left << setw(20) << &a << setw(20) << a.getVardas() << setw(20) << a.getPavarde();
        if (skaicius == 1) {
            cout << fixed << setprecision(2) << setw(15) << a.getRezultatas() << endl;
        } else if (skaicius == 2) {
            cout << fixed << setprecision(2) << setw(15) << a.getRezultatas1() << endl;
        }
    }
}


void nuskaitymas(vector<Studentas>& grupe, int sarasas) {
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


    while (getline(failas, eilute)) {
        Studentas studentas;

        stringstream ss(eilute);

        string vardas, pavarde;
        ss >> vardas >> pavarde;
        studentas.setVardas(vardas);
        studentas.setPavarde(pavarde);

        for (int i = 0; i < 10; i++) {
            int pazymys;
            if (ss >> pazymys) {
                studentas.addPazymys(pazymys);
            }
        }

        int egzaminas;
        ss >> egzaminas;
        studentas.setEgzaminas(egzaminas);
        studentas.Rezultatusk();
        grupe.push_back(studentas);
    }
}




void surusiuoti(vector<Studentas>& grupe, vector<Studentas>& vargsiukai, vector<Studentas>& galvociai, const string& pagalRusiuoti) {
    if (pagalRusiuoti == "vardas") {
        sort(grupe.begin(), grupe.end(), [](const Studentas& a, const Studentas& b) {
            return a.getVardas() < b.getVardas();
        });
    } else if (pagalRusiuoti == "pavarde") {
        sort(grupe.begin(), grupe.end(), [](const Studentas& a, const Studentas& b) {
            return a.getPavarde() < b.getPavarde();
        });
    } else if (pagalRusiuoti == "galutinis") {
        sort(grupe.begin(), grupe.end(), [](const Studentas& a, const Studentas& b) {
            return a.getRezultatas1() > b.getRezultatas1();
        });
    }


    auto separator = partition(grupe.begin(), grupe.end(), [](const Studentas& a) {
        return a.getRezultatas1() < 5.0;
    });

    copy(grupe.begin(), separator, back_inserter(vargsiukai));
    copy(separator, grupe.end(), back_inserter(galvociai));
}



void isvedimas(const vector<Studentas>& grupe, const string& failas) {
    ofstream output(failas);
    if (!output.is_open()) {
        cerr << "Failed to open output file: " << failas << endl;
        return;
    }

    output << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(15) << "Galutinis (Vid.)" << endl;
    output << string(55, '-') << endl;

    for (const auto& a : grupe) {
        output << left << setw(20) << a.getVardas() << setw(20) << a.getPavarde();
        output << fixed << setprecision(2) << setw(15) << a.getRezultatas1() << endl;
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

