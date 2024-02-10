#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<vector<array<int, 2>>> g(N + 1);

    for (int i = 1; i < N; i++) {
        int A, B, X;
        cin >> A >> B >> X;
        g[i].push_back({i + 1, A});
        g[i].push_back({X, B});
    }

    priorit
}