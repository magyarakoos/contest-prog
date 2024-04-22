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

    ll sum = 0;
    for (int i = 0; i <= N; i++) {
        sum += v[i];
        cout << sum << " " << K * (i + 1) << "\n";
        if (K * (i + 1) <= sum) {
            cout << "NO\n";
            return;
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