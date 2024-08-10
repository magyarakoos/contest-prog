/* konzolra való íráshoz, olvasáshoz */
#include <iostream>
/* vector: lista C++-ban */
#include <vector>

/*
 * így nem kell minden felhasznált függvény elé kiírni,
 * hogy 'std::'
 */
using namespace std;

int main() {
    /* bemenet beolvasása */
    int N = 0;
    int Q = 0;

    cin >> N;
    cin >> Q;

    /* szövegek listája, minden elem egy sor */
    vector<vector<char>> erdo(N + 1, vector<char>(N + 1, ' '));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> erdo[i][j];
        }
    }

    /*
     * db_eddig[i][j]: az erdő 'i'-edik sorának 'j'-edik
     * oszlopáig ennyi fa található
     */
    vector<vector<int>> db_eddig(N + 1, vector<int>(N + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i > 0) {
                db_eddig[i][j] += db_eddig[i - 1][j];
            }
            if (j > 0) {
                db_eddig[i][j] += db_eddig[i][j - 1];
            }
            if (i > 0 && j > 0) {
                db_eddig[i][j] -= db_eddig[i - 1][j - 1];
            }

            bool van_itt_fa = erdo[i][j] == '*';
            if (van_itt_fa) {
                db_eddig[i][j] += 1;
            }
        }
    }

    /*
     * egyesével megválaszoljuk a kérdéseket,
     * az adatok kiolvasásával az előre
     * kiszámolt táblából
     */
    for (int i = 0; i < Q; i++) {
        int i1 = 0;
        int j1 = 0;
        int i2 = 0;
        int j2 = 0;

        cin >> i1;
        cin >> j1;
        cin >> i2;
        cin >> j2;

        int A = db_eddig[i2][j2];
        int B = db_eddig[i2][j1 - 1];
        int C = db_eddig[i1 - 1][j2];
        int D = db_eddig[i1 - 1][j1 - 1];

        cout << A - B - C + D << "\n";
    }
}
