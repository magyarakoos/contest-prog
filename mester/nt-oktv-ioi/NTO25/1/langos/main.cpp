#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> T(N);
    for (ll& x : T) cin >> x;

    auto f = [&](ll x) -> bool {
        ll result = 0;
        for (int i = 0; i < N; i++) {
            if (x / T[i] > M - result) return 1;
            result += x / T[i];
        }
        return 0;
    };

    ll l = 0, r = 1e18;
    while (l < r) {
        ll m = l + (r - l) / 2;
        if (f(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    cout << l << "\n";
}
