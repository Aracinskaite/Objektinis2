#include "mylib.h"
#include "timer.h"


using namespace std;

int main() {
    vector<int> sarasas = {1000, 10000, 100000, 1000000, 10000000};
    vector<studentas> grupe;
    vector<studentas> vargsiukai;
    vector<studentas> galvociai;

    int skaicius;

    cout << "Jei norite galutini bala skaiciuoti pagal mediana rasykite 1, jei norite pagal vidurki rasykite 2: ";
    while (!(cin >> skaicius) || (skaicius != 1 && skaicius != 2)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Klaida: ivestas ne skaicius arba ne 1 ir ne 2. Prasome dar karta ivesti skaiciu 1 - galutinis skaiciuojams nuo medianos, 2 - galutinis skaiciuojamas nuo vidurkio: ";
    }

    for (int i = 0; i < sarasas.size(); i++) {
        studFailas(sarasas[i]);

        Timer t;
        nuskaitymas(grupe, (sarasas[i]));
        double z = t.elapsed();

        vector<studentas> vargsiukai;
        vector<studentas> galvociai;

        Timer1 t1;
        surusiuoti(grupe, skaicius, vargsiukai, galvociai);
        double z1 = t1.elapsed();

        Timer2 t2;
        isvedimas(vargsiukai, "vargsiukai_" + to_string(sarasas[i]) + ".txt", skaicius);
        double z2 = t2.elapsed();

        Timer3 t3;
        isvedimas(galvociai, "galvociai_" + to_string(sarasas[i]) + ".txt", skaicius);
        double z3 = t3.elapsed();

        cout << "\n";
        cout << sarasas[i] << " studentu nuskaityti uztruko: " << fixed << setprecision(2) << (z = t.elapsed()) << " s\n";
        cout << sarasas[i] << " studentu dalijimas i dvi grupes laikas: " << fixed << setprecision(2) << (z1 = t1.elapsed()) << " s\n";
        cout << sarasas[i] << " irasu 'vargsiukai' irasymo i faila laikas: " << fixed << setprecision(2) << (z2 = t2.elapsed()) << " s\n";
        cout << sarasas[i] << " irasu 'galvociai' irasymo i faila laikas: " << fixed << setprecision(2) << (z3 = t3.elapsed()) << " s\n";

    }

    system("pause");
    return 0;
}
