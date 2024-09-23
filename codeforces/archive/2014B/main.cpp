#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    cout << ((K + (K % 2)) / 2 % 2 ? "NO" : "YES") << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
