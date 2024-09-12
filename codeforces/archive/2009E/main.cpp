#include <iostream>

using namespace std;
using ll = long long;

const ll INF = 1e15;

void solve() {
    ll N, K;
    cin >> N >> K;

    auto sum = [](ll a, ll b) -> ll {
        return b * (b + 1) / 2 - a * (a - 1) / 2;
    };

    auto f = [&](ll i) -> ll { return abs(sum(N, i) - sum(i + 1, N + K - 1)); };

    for (int i = N; i < N + K; i++) { cout << f(i) << " "; }
    cout << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
