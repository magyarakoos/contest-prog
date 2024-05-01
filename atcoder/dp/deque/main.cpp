#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> a;
map<array<int, 3>, array<int, 2>> m;

array<int, 2> solve(int l, int r, int turn) {
    if (m.count({l, r, turn})) return m[{l, r, turn}];

    array<int, 2> res {0, 0};

    if (l == r) {
        res[turn] += a[l];
    }
    else if (l <= r) {
        auto a = solve(l + 1, r, turn ^ 1),
             b = solve(l, r - 1, turn ^ 1);
        if (a[turn] - a[turn ^ 1] > b[turn] - b[turn ^ 1]) {
            res = a;
            res[turn] += a[l];
        } else {
            res = b;
            res[turn] += a[r];
        }
    }

    m[{l, r, turn}] = res;
    return res;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    cin >> N;
    a.resize(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    auto res = solve(0, N - 1, 0);
    cout << res[0] << " " << res[1] << "\n";
}