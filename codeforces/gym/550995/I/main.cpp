#include <iostream>
using namespace std;

inline constexpr int MAXN = 7368790, MAXK = 5e6,
                     ROUND_1 = 10;

int a[MAXN], b[MAXK], bp = 0;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    a[0] = a[1] = 1;
    for (int i = 2; i < ROUND_1; i++) {
        if (!a[i]) {
            for (int j = 2 * i; j < ROUND_1; j += i) {
                a[j] = 1;
            }
            b[bp++] = i;
        }
    }

    for (int i = ROUND_1; i < MAXN; i++) {
        if (!a[(i + 1) % ROUND_1] && !a[i]) {
            for (int j = 2 * i; j < MAXN; j += i) {
                a[j] = 1;
            }
            b[bp++] = i;
        }
    }

    for (int i = 0; i < 100; i++) { cout << b[i] << "\n"; }

    // int Q;
    // cin >> Q;
    // while (Q--) {
    //     int K;
    //     cin >> K;
    //     cout << b[K - 1] << "\n";
    // }
}
