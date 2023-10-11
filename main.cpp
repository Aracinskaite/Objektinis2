#include "mylib.h"

using namespace std;


int main() {
    vector<studentas> grupe;

    int sarasas[] = {1000, 10000, 100000, 1000000, 10000000};
    int failosk;

    cout << "Iveskite atitinkama skaiciu iki kiek norite generuoti studentu faila:";
    cout << "1 - 1000, 2 - 10000, 3 - 100000, 4 - 1000000, 5 - 10000000"<< endl;

    while (!(cin >> failosk) || (failosk != 1 && failosk != 2 && failosk != 3 && failosk != 4 && failosk != 5)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Klaida: ivestas ne skaicius arba ne toks skaicius. Iveskite 1 - 1000, 2 - 10000, 3 - 100000, 4 - 1000000, 5 - 10000000 :" << endl;
    }

    studFailas(sarasas[failosk - 1]);
    nuskaitymas(grupe);

    int skaicius;

    cout << "Jei norite galutini bala skaiciuoti pagal mediana rasykite 1, jei norite pagal vidurki rasykite 2:" << endl;

    while (!(cin >> skaicius) || (skaicius != 1 && skaicius != 2)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Klaida: ivestas ne skaicius arba ne 1 ir ne 2. Prasome dar karta ivesti skaiciu 1 - galutinis skaiciuojams nuo medianos, 2 - galutinis skaiciuojamas nuo vidurkio" << endl;
    }

    surusiuoti(grupe, skaicius);

    return 0;
}

