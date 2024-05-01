#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using state = struct { int i; ll weight; };

const ll MAXN = 1e5, INF = 1e18;

int N, W;
map<state, ll> m;

ll solve(state s) {
    if (m.count(s)) return m[s];

    auto [i, weight] = s;
    if (i == N) return weight;

    
}

int main() {

}