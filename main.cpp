#include "mylib.h"
#include "timer.h"

using namespace std;


int main() {
    vector<studentas> grupe;
    vector<studentas> vargsiukai;
    vector<studentas> galvociai;

    int sarasas[] = {1000, 10000, 100000, 1000000, 10000000};
    int failosk;

    cout << "Iveskite atitinkama skaiciu iki kiek norite generuoti studentu faila:";
    cout << "1 - 1000, 2 - 10000, 3 - 100000, 4 - 1000000, 5 - 10000000: ";

    while (!(cin >> failosk) || (failosk != 1 && failosk != 2 && failosk != 3 && failosk != 4 && failosk != 5)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Klaida: ivestas ne skaicius arba ne toks skaicius. Iveskite 1 - 1000, 2 - 10000, 3 - 100000, 4 - 1000000, 5 - 10000000 : " ;
    }

    studFailas(sarasas[failosk - 1]);

    Timer t;
    nuskaitymas(grupe);
    double z = t.elapsed();

    int skaicius;

    cout << "Jei norite galutini bala skaiciuoti pagal mediana rasykite 1, jei norite pagal vidurki rasykite 2: " ;

    while (!(cin >> skaicius) || (skaicius != 1 && skaicius != 2)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Klaida: ivestas ne skaicius arba ne 1 ir ne 2. Prasome dar karta ivesti skaiciu 1 - galutinis skaiciuojams nuo medianos, 2 - galutinis skaiciuojamas nuo vidurkio : " ;
    }

    Timer1 t1;
    surusiuoti(grupe, skaicius, vargsiukai, galvociai);
    double z1 = t1.elapsed();
    Timer2 t2;
    isvedimas(vargsiukai, "vargsiukai.txt", skaicius);
    double z2 = t2.elapsed();
    Timer3 t3;
    isvedimas(galvociai, "galvociai.txt", skaicius);
    double z3 = t3.elapsed();

    cout <<" \n";
    cout << (sarasas[failosk - 1]) << " studentu nuskaityti uztruko: " << (z=  t.elapsed(),z) << " s\n";
    cout << (sarasas[failosk - 1]) << " studentu dalijimas i dvi grupes laikas: " << (z1=  t1.elapsed(),z1) << " s\n";
    cout << (sarasas[failosk - 1]) << " irasu 'vargsiukai' irasymo i faila laikas: " << (z2=  t2.elapsed(),z2) << " s\n";
    cout << (sarasas[failosk - 1]) << " irasu 'galvociai' irasymo i faila laikas: " << (z3=  t3.elapsed(),z3) << " s\n";
    system("pause");
    return 0;
}

