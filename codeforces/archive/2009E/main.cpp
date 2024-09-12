#include <iostream>

using namespace std;
using ll = long long;

const ll INF = 1e18;

void solve() {
    ll N, K;
    cin >> N >> K;

    auto sum = [](ll a, ll b) -> ll {
        return b * (b + 1) / 2 - a * (a - 1) / 2;
    };

    auto f = [&](ll i) -> ll { return abs(sum(N, i) - sum(i + 1, K + N - 1)); };

    ll l = K, r = K + N - 1;
    while (r - l > 2) {
        ll m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        if (INF - f(m1) < INF - f(m2)) {
            l = m1;
        } else {
            r = m2;
        }
    }
    cout << f(l) << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
