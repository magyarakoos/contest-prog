#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, W;
map<pair<int, ll>, ll> m;

int v[101], w[101];

ll solve(pair<int, ll> state) {
    if (m.count(state)) return m[state];

    auto [i, weight] = state;
    if (i + 1 == N) return weight;

    ll res = 0;

    // take
    if (weight + w[i + 1] <= W) {
        res = max(res, solve({i + 1, weight + w[i + 1]}) + v[i + 1]);
    }

    // don't take
    res = max(res, solve({i + 1, weight}));

    cout << i << " " << weight << " : " << res << "\n";
    m[state] = res;
    return res;
}

int main() {
    cin.tie(0), ios::sync_with_stdio();
    cin >> N >> W;
    for (int i = 0; i < N; i++) {
        cin >> v[i] >> w[i];
    }
    cout << solve({-1, 0});
}