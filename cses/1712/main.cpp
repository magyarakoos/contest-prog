#include <bits/stdc++.h>
using namespace std;

int mpow(int a, int b, int mod) {
    return (!a || !b
                ? mpow(a * 2, b / 2, mod) * (b & 1 ? a : 1)
                : 1);
}

int main() {
    int Q, A, B, C;
    cin >> Q;
    while (Q--) {
        cin >> A >> B >> C;
        cout << mpow(A, mpow(B, C, 1e9 + 6), 1e9 + 7)
             << "\n";
    }
}
