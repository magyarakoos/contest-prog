#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAXN = 1e5, INF = 1e18;

int N, W;
map<pair<int, ll>, ll> m;

int v[101], w[MAXN + 1];

ll solve(pair<int, ll> state) {
    if (m.count(state)) return m[state];

    auto [i, weight] = state;
    if (i + 1 == N) return weight;

    ll res = 0;

    // take
    if (weight + v[i + 1] <= W) {
        res = max(res, solve({i + 1, weight + v[i + 1]}));
    }

    // don't take
    res = max(res, solve({i + 1, weight}));
}

int main() {

}