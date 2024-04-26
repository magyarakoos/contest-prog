#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, K, prod = 1;
    cin >> N >> K;
    while (N--) {
        ll x;
        cin >> x;
        prod *= x;
    }

    if (!prod || prod > 2023 || 2023 % prod) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n" << 2023 / prod;
    K--;

    while (K--) cout << " 1";
    cout << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
