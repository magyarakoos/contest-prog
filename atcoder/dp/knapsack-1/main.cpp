#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAXN = 1e5, INF = 1e18;

int N, W;
map<pair<int, ll>, ll> m;

ll solve(pair<int, ll> state) {
    if (m.count(state)) return m[state];

    auto [i, weight] = state;
    if (i == N) return weight;

    
}

int main() {

}