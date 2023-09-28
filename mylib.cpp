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



void mano_funkcija() {
    int studsk;
    cout << "Iveskite studentu skaiciu: ";
    cin >> studsk;
    studentas Studentas;
    string zodis;
    cout << "Iveskite, galutini norite skaiciuoti su mediana ar vidurkiu :";
    cin >> zodis;
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



        if (zodis == "mediana") {
            double galutinis = 0.4 * medianossk(Studentas.pazymiai) + 0.6 * Studentas.egzaminas;
            Studentas.rezultatas = galutinis;
        } else if (zodis == "vidurkiu") {
            double galutinis1 = 0.4 * vidurkiosk(Studentas.pazymiai) + 0.6 * Studentas.egzaminas;
            Studentas.rezultatas = galutinis1;
}

        grupe.push_back(Studentas);
        Studentas.pazymiai.clear();
    }

    if (zodis == "mediana") {
    cout << left << setw(20) << "Vardas" << setw(20) << "Pavardë" << setw(15) << "Galutinis (Med.)"  << endl;
    cout << string(55, '-') << endl;
    for (auto& a : grupe) {
        cout << left << setw(20) << a.vardas << setw(20) << a.pavarde;
        cout << fixed << setprecision(2) << setw(15) << a.rezultatas << endl;
        }
    } else if (zodis == "vidurki") {
        cout << left << setw(20) << "Vardas" << setw(20) << "Pavardë" << setw(15) << "Galutinis (Vid.)"<< endl;
        cout << string(55, '-') << endl;
        for (auto& a : grupe) {
            cout << left << setw(20) << a.vardas << setw(20) << a.pavarde;
            cout << fixed << setprecision(2) << setw(15) << a.rezultatas << endl;
        }
    }


}

