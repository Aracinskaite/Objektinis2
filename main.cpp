#include "mylib.h"

using namespace std;

int main() {
    int skait;
    cout << "Jei norite ivesti studentus ir atlikti veiksums rasykite 1, jei norite nuskaityti studentus rasykite 2:";
    while (!(cin >> skait) || (skait != 1 && skait != 2)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Klaida: ivestas ne skaicius. Iveskite 1 - jei norite ivesti studentus ir atlikti veiksums , 2 - jei norite nuskaityti studentus rasykite :" << endl;
    }
    if (skait == 1) {
        mano_funkcija();

    } else if (skait == 2) {
        mano_funkcija1();
    }
    return 0;
}
