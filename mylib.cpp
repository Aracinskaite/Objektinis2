#include "mylib.h"


void mano_funkcija() {
    int studsk;
    cout << "Iveskite studentu skaiciu: ";
    cin >> studsk;
    studentas Studentas;
    vector <studentas> grupe;
    for (int j = 0; j < studsk; j++) {
        cout << "Ivesk varda ir pavarde: ";
        cin >> Studentas.vardas >> Studentas.pavarde;
        cout << "Kiek studentas tures pazymiu: ";
        int n;
        cin>>n;
        for (int i = 0; i < n; i++) {
            int k;
            cout << "Iveskite " << i + 1 << " pazymi: ";
            cin >> k;
            Studentas.pazimiai.push_back(k);
        }
        cout << "Iveskite egzamina: ";
        cin >> Studentas.egzaminas;
        grupe.push_back(Studentas);
        Studentas.pazimiai.clear();
    }
    cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(15) << "Vidurkis" << endl;
    cout << string(55, '-') << endl;
    for (auto& a : grupe) {
        cout << left << setw(20) << a.vardas << setw(20) << a.pavarde << setw(15) << a.egzaminas << endl;
    }
}
/*cout << 10 << "-" <
    for (auto& a : grupe) {
        cout << 10 << a.vardas << 10<< " " << a.pavarde << "Semestras :";
        for (auto& z : a.pazimiai) cout << z << " ";
        cout << "egz :" << a.egzaminas << endl;
    }
studentas ivesk(){
    studentas temp;
    cout<<"Ivesk varda: ";
    cin>>temp.var;
    return}

void ivesk(studentas &Temp){
    cout<<"Ivesk varda: ";
    cin>>Temp.var;}  */

