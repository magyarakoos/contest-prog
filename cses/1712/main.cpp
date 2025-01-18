#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q, A, B, C;
    cin >> Q;
    while (Q--) {
        cin >> A >> B >> C;
        cout << mpow(A, mpow(B, C, 1e9 + 6), 1e9 + 7)
             << "\n";
    }
}
