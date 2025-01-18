#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int mpow(int a, int b, int mod) {
    if (!b) return 1;
    return mpow(a * a % mod, b / 2, mod) * (b & 1 ? a : 1) %
           mod;
}

int32_t main() {
    int Q, A, B, C;
    cin >> Q;
    while (Q--) {
        cin >> A >> B >> C;
        cout << mpow(A, mpow(B, C, 1e9 + 6), 1e9 + 7)
             << "\n";
    }
}
