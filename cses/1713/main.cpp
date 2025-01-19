#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int N, X;
    cin >> N;
    while (N--) {
        cin >> X;
        int d = 0;
        for (int i = 1; i * i <= X; i++) {
            if (X % i == 0) d += 1 + (i * i != X);
        }
        cout << d << "\n";
    }
}
