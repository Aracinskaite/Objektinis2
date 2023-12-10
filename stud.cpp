#include "studlib.h"
#include "timer.h"

Studentas::~Studentas() {}

Studentas::Studentas(const Studentas& other)
    : Zmogus(other), pazymiai_(other.pazymiai_), egzaminas_(other.egzaminas_),
      rezultatas_(other.rezultatas_), rezultatas1_(other.rezultatas1_) {}


Studentas& Studentas::operator=(const Studentas& other) {
        if (this != &other) {
            Zmogus::operator=(other);
            pazymiai_ = other.pazymiai_;
            egzaminas_ = other.egzaminas_;
            rezultatas_ = other.rezultatas_;
            rezultatas1_ = other.rezultatas1_;
        }
        return *this;
    }

Studentas::Studentas() : egzaminas_(0), rezultatas_(0.0), rezultatas1_(0.0) {}

Studentas::Studentas( const std::vector<int>& pazymiai, int egzaminas)
    : pazymiai_(pazymiai), egzaminas_(egzaminas), rezultatas_(0.0), rezultatas1_(0.0) {}

std::istream& operator>>(std::istream& is, Studentas& studentas) {
    is >> studentas.vardas_ >> studentas.pavarde_;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Studentas& studentas) {
    os << left  << setw(20) << studentas.getVardas() << setw(20) << studentas.getPavarde();
    return os;
}


void Studentas::generuoti() {
    int ndskaicius = rand() % 11;
    cout << "Generuoti pazymiai: ";
    for (int i = 0; i < ndskaicius; i++) {
        int pazymys = rand() % 11;
        pazymiai_.push_back(pazymys);
        cout << pazymys << " ";
    }
    cout << "\nGeneruotas egzaminas: " << (egzaminas_ = rand() % 11) << endl;
}


double Studentas::vidurkiosk() const {
    assert(!pazymiai_.empty());
    int dydis = pazymiai_.size();
    int sum = std::accumulate(pazymiai_.begin(), pazymiai_.end(), 0);
    return static_cast<double>(sum) / dydis;
}

double Studentas::medianossk() const {
    assert(!pazymiai_.empty());
    std::vector<int> surusiuota = pazymiai_;
    std::sort(surusiuota.begin(), surusiuota.end());
    int dydis = surusiuota.size();
    if (dydis % 2 == 0) {
        int vid1 = surusiuota[dydis / 2 - 1];
        int vid2 = surusiuota[dydis / 2];
        return static_cast<double>(vid1 + vid2) / 2.0;
    } else {
        return static_cast<double>(surusiuota[dydis / 2]);
    }
}

void Studentas::mano_funkcija1() {
    string failopavadinimas;
    cout << "Iveskite savo failo pavadinima: ";
    cin >> failopavadinimas;
    list<Studentas> grupe;
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
        Studentas studentas;
        std::stringstream ss(eilute);
        ss >> studentas;

        for (int i = 1; i <= num; i++) {
        int pazymys;
        if (ss >> pazymys) {
            studentas.setPazymiai(pazymys);}
        }

        int egzaminas;
        ss >> egzaminas;
        studentas.setEgzaminas(egzaminas);

        double galutinis = 0.4 * studentas.medianossk() + 0.6 * studentas.getEgzaminas();
        studentas.setRezultatas(galutinis);
        double galutinis1 = 0.4 * studentas.vidurkiosk() + 0.6 * studentas.getEgzaminas();
        studentas.setRezultatas1(galutinis1);

        grupe.push_back(studentas);
    }

    grupe.sort([](const Studentas& a, const Studentas& b) {
        if (a.getVardas() != b.getVardas()) {
            return a.getVardas() < b.getVardas();
        } else {
            return a.getPavarde() < b.getPavarde();
        }});

    cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde"<< left << setw(20) << "Galutinis (Vid.)" << left << setw(20) << "Galutinis (Med.)" << endl;
    cout << string(80, '-') << endl;

    for (const auto& studentas : grupe) {
        cout << studentas;
        cout << left << fixed << setprecision(2) << setw(20) << studentas.getRezultatas1();
        cout << left << fixed << setprecision(2) << setw(20) << studentas.getRezultatas() << endl;
    }
}


void Studentas::mano_funkcija() {
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
    list<Studentas> grupe;
    for (int j = 0; j < studsk; j++) {
        Studentas studentas;

        cout << "Ivesk varda ir pavarde: ";
        string vardas, pavarde;
        cin >> studentas;

        int ivedimas;
        cout << "Jei norite ivesti pazymius, rasykite 1, jei norite, kad sugeneruotu, rasykite 2: ";
        while (true) {
            if (cin >> ivedimas && (ivedimas == 1 || ivedimas == 2)) {
                break;
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Klaida: ivestas ne skaicius arba ne 1 ir ne 2. Prasome dar karta ivesti skaiciu 1 - jei norite ivesti pazymius, 2 - jei norite, kad sugeneruotu: " << endl;
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
                    break;}
                studentas.setPazymiai(k);
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
            studentas.generuoti();
        }
        double galutinis = 0.4 * studentas.medianossk() + 0.6 * studentas.getEgzaminas();
        studentas.setRezultatas(galutinis);
        double galutinis1 = 0.4 * studentas.vidurkiosk() + 0.6 * studentas.getEgzaminas();
        studentas.setRezultatas1(galutinis1);
        grupe.push_back(studentas);
    }

    grupe.sort([](const Studentas& a, const Studentas& b) {
        if (a.getVardas() != b.getVardas()) {
            return a.getVardas() < b.getVardas();
        } else {
            return a.getPavarde() < b.getPavarde();
        }});

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
        cout << left << setw(20) << "Adresas" << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(15) << "Galutinis (Vid.)" << endl;}
    cout << string(75, '-') << endl;

    for (const auto& a : grupe) {
        cout <<setw(20) << &a << a;
        if (skaicius == 1) {
            cout << fixed << setprecision(2) << setw(15) << a.getRezultatas() << endl;
        } else if (skaicius == 2) {
            cout << fixed << setprecision(2) << setw(15) << a.getRezultatas1() << endl;
        }
    }
}





void Studentas::nuskaitymas(list<Studentas>& grupe, int sarasas) {
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
    num -= 3;

    while (getline(failas, eilute)) {
        Studentas studentas;
        stringstream ss(eilute);
        ss >> studentas;

        for (int i = 1; i < num; i++) {
            int pazymys;
            if (ss >> pazymys) {
                studentas.pazymiai_.push_back(pazymys);
            }
        }

        ss >> studentas.egzaminas_;
        double galutinis1 = 0.4 * studentas.vidurkiosk() + 0.6 * studentas.egzaminas_;
        studentas.rezultatas1_ = galutinis1;

        grupe.push_back(studentas);
    }
}


void Studentas::surusiuoti(list<Studentas>& grupe, list<Studentas>& vargsiukai, const string& pagalRusiuoti) {
    if (pagalRusiuoti == "vardas") {
        grupe.sort([](const Studentas& a, const Studentas& b) {
            return a.getVardas() < b.getVardas();
        });
    } else if (pagalRusiuoti == "pavarde") {
        grupe.sort([](const Studentas& a, const Studentas& b) {
            return a.getPavarde() < b.getPavarde();
        });
    } else if (pagalRusiuoti == "galutinis") {
        grupe.sort([](const Studentas& a, const Studentas& b) {
            return a.getRezultatas1() < b.getRezultatas1();
        });
    }

    for (auto a = grupe.begin(); a != grupe.end();) {
        if (a->getRezultatas1() < 5.0) {
            vargsiukai.push_back(*a);
            a = grupe.erase(a);
        } else {
            ++a;
        }
    }
}

void Studentas::isvedimas(const list<Studentas>& grupe, const string& failas) {
    ofstream output(failas);
    if (!output.is_open()) {
        cerr << "Failed to open output file: " << failas << endl;
        return;
    }

    output << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(15) << "Galutinis (Vid.)" << endl;
    output << string(55, '-') << endl;

    for (const auto& a : grupe) {
        output << a;
        output << fixed << setprecision(2) << setw(15) << a.getRezultatas1() << endl;
    }

    output.close();
}


void Studentas::studFailas(int sarasas) {
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




void Studentas::isvedimasLaiko(double laikas1, double laikas2, double laikas3, double laikas4, double laikas5, int testsk, int sarasas) {
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

