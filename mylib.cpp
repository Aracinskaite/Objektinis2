#include "mylib.h"

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

void mano_funkcija() {
    int studsk;
    cout << "Iveskite studentu skaiciu: ";
    cin >> studsk;
    studentas Studentas;
    vector<studentas> grupe;

    for (int j = 0; j < studsk; j++) {
        cout << "Ivesk varda ir pavarde: ";
        cin >> Studentas.vardas >> Studentas.pavarde;
        cout << "Kiek studentas tures pazymiu: ";
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int k;
            cout << "Iveskite " << i + 1 << " pazymi: ";
            cin >> k;
            Studentas.pazymiai.push_back(k);
        }

        cout << "Iveskite egzamina: ";
        cin >> Studentas.egzaminas;

        double galutinis1 = 0.4 * vidurkiosk(Studentas.pazymiai) + 0.6 * Studentas.egzaminas;
        Studentas.rezultatas = galutinis1;

        grupe.push_back(Studentas);
        Studentas.pazymiai.clear();
    }

    cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(15) << "Vidurkis" << endl;
    cout << string(55, '-') << endl;

    for (auto& a : grupe) {
        cout << left << setw(20) << a.vardas << setw(20) << a.pavarde;
        cout << fixed << setprecision(2) << setw(15) << a.rezultatas << endl;
    }
}
