#include <iostream>

using namespace std;
using ll = long long;

ll sum(ll a, ll b) { return b * (b + 1) / 2 - a * (a - 1) / 2; }

void solve() {
    ll N, K;
    cin >> N >> K;

    ll l = N, r = N + K - 1;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
