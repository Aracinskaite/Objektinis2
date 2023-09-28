#include "mylib.h"
#include <fstream>

double vidurkiosk(const vector<int>& pazymiai) {
    int dydis = pazymiai.size();
    if (dydis == 0) {
        return 0.0;
    }
    int sum;
    for (int num : pazymiai) {
        sum += num;
    }
    return static_cast<double>(sum) / dydis;
}

double medianossk(const vector<int>& pazymiai) {
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


void mano_funkcija(){
    int studsk;
    cout << "Iveskite studentu skaiciu: ";
    while (!(cin >> studsk)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Klaida: ivestas ne skaicius. Prasome dar karta ivesti studentu skaiciu." << endl;
    }
    studentas Studentas;
    vector<studentas> grupe;
    for (int j = 0; j < studsk; j++) {
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
                cout << "Klaida: ivestas ne skaicius arba ne 1 ir ne 2. Prašome dar karta ivesti skaiciu 1 - jei norite ivesti pazymius, 2 - jei norite, kad sugeneruotu: " << endl;
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
    int skaicius;
    cout << "Jei norite galutini bala skaiciuti pagal mediana rasykite 1, jei norite pagal vidurki rasykite 2:";
    while (!(cin >> skaicius) || (skaicius != 1 && skaicius != 2)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Klaida: ivestas ne skaicius arba ne 1 ir ne 2. Prasome dar karta ivesti skaiciu 1 - galutinis skaiciuojams nuo medianos, 2 - galutinis skaiciuojamas nuo vidurkio" << endl;
    }
    cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(15) << "Galutinis (Med.)" << endl;
    cout << string(55, '-') << endl;
    for (const auto& a : grupe) {
        cout << left << setw(20) << a.vardas << setw(20) << a.pavarde;
        if (skaicius == 1) {
            cout << fixed << setprecision(2) << setw(15) << a.rezultatas << endl;
        } else if (skaicius == 2) {
            cout << fixed << setprecision(2) << setw(15) << a.rezultatas1 << endl;
        }
    }
}




