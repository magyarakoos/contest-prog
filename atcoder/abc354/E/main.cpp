#include <bits/stdc++.h>
#ifdef LOCAL
#include <debug.h>
#else
#define DB(...)
#endif
using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

int N;
vector<int> cache;
vector<vector<bool>> ok;

int f(int u) {
    if (cache[u]) return cache[u];
    vector<int> v;

    for (int i = 0; i < N; i++) {
        if ((1 << i) & u) {
    
            for (int j : v) {
                if (ok[i][j] && f(u ^ (1 << i) ^ (1 << j)) == 2) {
                    return cache[u] = 1;
                }
            }
            v.push_back(i);
        }
    }

    return cache[u] = 2;
}

#define cases 0
void solve() {
    cin >> N;
    ok.assign(N, vector<bool>(N));
    cache.resize(1 << N);
    vector<int> A(N), B(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ok[i][j] = A[i] == A[j] || B[i] == B[j];
        }
    }

    if (f((1 << N) - 1) == 1) {
        cout << "Takahashi\n";
    } else {
        cout << "Aoki\n";
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
