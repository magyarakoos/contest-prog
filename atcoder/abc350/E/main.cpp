#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, A, X, Y;
map<int, pair<int, double>> cache;

pair<int, double> dp(int u) {
    if (u == 0) {
        return {0, 0};
    }
    if (cache.count(u)) {
        return cache[u];
    }

    pair<int, double> a = dp(u / A);
    a.first++; a.second += X;

    
}

#define cases 0
void solve() {
    cin >> N >> A >> X >> Y;
    auto [steps, cost] = dp(N);
    cout << setprecision(15) << cost / steps;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}