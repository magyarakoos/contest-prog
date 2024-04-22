#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<ll> hpS(N), v(N + 1);
    for (ll& x : hpS) cin >> x;

    for (int i = 0; i < N; i++) {
        ll X;
        cin >> X;
        v[abs(X)] += hpS[i];
    }

    ll rem = 0;
    for (int i = 0; i <= N; i++) {
        if (rem + K < v[i]) {
            cout << "NO\n";
            return;
        }
        rem += K;
        rem -= v[i];
    }

    cout << "YES\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}