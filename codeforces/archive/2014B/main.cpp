#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    cout << (N - K + 1 % 2 ? (N ? "YES" : "NO") : (N ? "YES" : "NO"));
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
