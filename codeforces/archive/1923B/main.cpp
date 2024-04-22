#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> hpS(N), v(N + 1);
    for (int& x : hpS) cin >> x;

    for (int i = 0; i < N; i++) {
        int X;
        cin >> X;
        v[abs(X)] += hpS[i];
    }

    int cleared = 0;
    for (int pos = 0; pos <= N; pos++) {
        if (cleared == N) break;

        if (v[pos] > 0) {
            cout << "NO\n";
            return;
        }

        int k = K;
        for (int i = cleared + 1; i <= N; i++) {
            if (k < v[i]) {
                v[i] -= k;
                break;
            }
            v[i] = 0;
            cleared = i;
            k -= v[i];
        }
    }
    
    cout << "YES\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}