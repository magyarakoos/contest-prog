#include <cstring>
#include <iostream>
using namespace std;

inline constexpr int MAXN = 7368790, MAXK = 5e5;

int a[MAXN], b[MAXK], bp = 0;
int main() {
    ios::sync_with_stdio(0);
    a[0] = a[1] = 1;
    int result = 0;
    for (int i = 2; i < MAXN; i++) {
        if (!a[i]) {
            for (int j = 2 * i; j < MAXN; j += i) {
                a[j] = 1;
            }
            b[bp++] = i;
        }
    }
    for (int i = 0; i < MAXK; i++) {
        cout << b[i] << ",\n";
    }
    // int Q;
    // cin >> Q;
    // while (Q--) {
    //     int K;
    //     cin >> K;
    //     cout << b[K - 1] << "\n";
    // }
}
