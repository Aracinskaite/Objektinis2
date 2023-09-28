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

void mano_funkcija() {

    int skait;
        cout << "Jei norite ivesti studentus ir atlikti veiksums rasykite 1, jei norite nuskaityti studentus rasykite 2:";
        cin >> skait;

        if (skait == 1){
                    int studsk;
                    cout << "Iveskite studentu skaiciu: ";
                    cin >> studsk;
                    studentas Studentas;
                    int skaicius;
                    cout << "Jei norite galutini bala skaiciuti pagal mediana rasykite 1, jei norite pagal mediana rasykite 2:";
                    cin >> skaicius;
                    vector<studentas> grupe;

                    for (int j = 0; j < studsk; j++) {
                    cout << "Ivesk varda ir pavarde: ";
                    cin >> Studentas.vardas >> Studentas.pavarde;

                    int ivedimas;
                    cout << "Jei norite ivesti pazymius  rasykite 1, jei norite, kad sugeneruotu rasykite 2:";
                    cin >> ivedimas;
                    if (ivedimas == 1){
                        cout << "Iveskite pazymi (baigti su -1): ";
                        int k;
                        while (cin >> k && k != -1 ) {
                            Studentas.pazymiai.push_back(k);
                        }
                        cout << "Iveskite egzamina: ";
                        cin >> Studentas.egzaminas;
                    }else if (ivedimas == 2) {
                        generuoti(Studentas);
                    }

                    if (skaicius == 1) {
                        double galutinis = 0.4 * medianossk(Studentas.pazymiai) + 0.6 * Studentas.egzaminas;
                        Studentas.rezultatas = galutinis;
                    } else if (skaicius == 2) {
                        double galutinis1 = 0.4 * vidurkiosk(Studentas.pazymiai) + 0.6 * Studentas.egzaminas;
                        Studentas.rezultatas = galutinis1;
                    }

                    grupe.push_back(Studentas);
                    Studentas.pazymiai.clear();
                    }

                    if (skaicius == 1) {
                        cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(15) << "Galutinis (Med.)"  << endl;
                        cout << string(55, '-') << endl;
                        for (auto& a : grupe) {
                            cout << left << setw(20) << a.vardas << setw(20) << a.pavarde;
                            cout << fixed << setprecision(2) << setw(15) << a.rezultatas << endl;
                        }
                    } else if (skaicius == 1) {
                        cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(15) << "Galutinis (Vid.)"<< endl;
                        cout << string(55, '-') << endl;
                        for (auto& a : grupe) {
                            cout << left << setw(20) << a.vardas << setw(20) << a.pavarde;
                            cout << fixed << setprecision(2) << setw(15) << a.rezultatas << endl;
                            }
                        }
                    }
        else if (skait==2){
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
        }
    }
}
