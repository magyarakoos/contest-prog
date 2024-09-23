#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    cout << (K % 2 ? ((K + N % 2) / 2 % 2 ? "NO" : "YES")
                   : (K / 2 % 2 ? "NO" : "YES"))
         << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
