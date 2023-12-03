#include "studlib.h"
#include "timer.h"


using namespace std;

int main() {
    int skait;
    cout << "Jei norite ivesti studentus ir atlikti veiksums. Rasykite 1." << endl;
    cout << "Jei norite nuskaityti studentus. Rasykite 2." << endl;
    cout << "Jei norite norite sugeneruoti failus ir atlikus veiksmus su jais paskaiciuoti vidutini laika. Rasykite 3." << endl;
    while (!(cin >> skait) || (skait != 1 && skait != 2 && skait != 3)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Klaida: ivestas ne skaicius. Iveskite 1 - jei norite ivesti studentus ir atlikti veiksums , 2 - jei norite nuskaityti studentus rasykite :" << endl;
    }
    if (skait == 1) {
        Studentas::mano_funkcija();
    } else if (skait == 2) {
        Studentas::mano_funkcija1();
    } else if  (skait == 3) {
        list<int> sarasas = {1000, 10000, 100000, 1000000, 10000000};
        list<Studentas> grupe;
        list<Studentas> vargsiukai;
        int skaicius;

        int generavimas;
        cout << "Jei norite dirbti su sugeneruotais failais, rasykite 1, jei norite is naujo sugeneruoti, rasykite 2: ";
        while (!(cin >> generavimas) || (generavimas != 1 && generavimas != 2)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Klaida: ivestas ne skaicius arba ne 1 ir ne 2. Prasome dar karta ivesti skaiciu: ";
        }

        int testsk;
        cout << "Kiek kartu noresite daryti laiko testavaima: ";
        while (!(cin >> testsk)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Klaida: ivestas ne skaicius. Iveskite kiek kartu noresite daryti laiko testavaima : ";
        }

        string pagalRusiuoti;
        cout << "Ivesk pagal ka nori rusiuoti ('vardas' - varda, 'pavarde' - pavarde, 'galutinis' - galutini): ";
        cin >> pagalRusiuoti;

        for (int i : sarasas) {
            cout << "\n";
            cout << right << setw(20) << "Darbas su " << left << i << " generuotais studentais" << endl;
            cout << "\n";
            grupe.clear();
            vargsiukai.clear();
            double laikas1 = 0.0;
            double laikas2 = 0.0;
            double laikas3 = 0.0;
            double laikas4 = 0.0;
            double laikas5 = 0.0;

            if (generavimas == 2) {
                Studentas::studFailas(i);}

            for (int j = 0; j < testsk; j++) {
                grupe.clear();
                vargsiukai.clear();

                Timer2 t2;
                Timer1 t1;
                Studentas::nuskaitymas(grupe, i);
                double z1 = t1.elapsed();
                laikas1 += z1;

                Timer1 t3;
                Studentas::surusiuoti(grupe, vargsiukai, pagalRusiuoti);
                double z3 = t3.elapsed();
                laikas3 += z3;

                Timer4 t4;
                Studentas::isvedimas(vargsiukai, "vargsiukai_" + to_string(i) + "." + to_string(j) + ".txt");
                double z4 = t4.elapsed();
                laikas4 += z4;

                Timer5 t5;
                Studentas::isvedimas(grupe, "galvociai_" + to_string(i) + "." + to_string(j) + ".txt");
                double z5 = t5.elapsed();
                laikas5 += z5;

                double z2 = t2.elapsed();
                laikas2 += z2;
            }
            Studentas::isvedimasLaiko(laikas1, laikas2, laikas3, laikas4, laikas5, testsk, i);
        }
    }
    system("pause");
    return 0;
}
