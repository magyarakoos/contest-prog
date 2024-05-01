#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5;

int N, W, v[100], w[100];
map<pair<int, ll>, ll> m;
int m[101][]

ll solve(pair<int, ll> state) {
    if (m.count(state)) return m[state];
    auto [i, weight] = state;
    if (i == N) return 0;
    // don't take
    ll res = solve({i + 1, weight});
    // take
    if (weight + w[i] <= W) {
        res = max(res, solve({i + 1, weight + w[i]}) + v[i]);
    }
    m[state] = res;
    return res;
}

int main() {
    cin.tie(0), ios::sync_with_stdio();
    cin >> N >> W;
    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }
    cout << solve({0, 0});
}