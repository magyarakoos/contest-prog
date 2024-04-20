#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, A, X, Y;
map<int, double> m;

double dp(int u) {
    if (u == 0) return 0;
    if (m.count(u)) {
        return m[u];
    }

    double a = X + dp(u / A);
    double b = Y;
    for (int i = 2; i <= 6; i++) {
        pair<double, double> curr_b = dp(u / i);
        value_b += (curr_b.second + Y) / (curr_b.first + 1);
        steps_b += curr_b.first + 1;
    }
    value_b /= 6;
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