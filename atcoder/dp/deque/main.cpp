#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int N;
vector<int> v;
map<array<int, 3>, ll> m;

ll solve(int l, int r, int turn) {
    if (m.count({l, r, turn})) return m[{l, r, turn}];

    ll res = 0;

    if (l == r) {
        res += v[l] * (turn ^ 1);
    }
    else if (l < r) {
        ll a = solve(l + 1, r, turn ^ 1),
           b = solve(l, r - 1, turn ^ 1);
        if (turn) {
            res = min(a, b);
        } else {
            if (a > b) {
                res = a + v[l];
            } else {
                res = b + v[r];
            }
        }
    }

    m[{l, r, turn}] = res;
    return res;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    cout << solve(0, N - 1, 0);
}
