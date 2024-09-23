#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    cout << (N - K + 1 % 2 ? (N % 2 ? "NO" : "YES") : (N % 2 ? "NO" : "YES"))
         << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
