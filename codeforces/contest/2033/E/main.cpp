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

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    int N;
    cin >> N;
    vector<int> p(N), pi(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
        p[i]--;
        pi[p[i]] = i;
    }

    int result = 0;
    for (int i = 0; i < N; i++) {
        if (p[i] == i) continue;
        if (p[p[i]] == i) continue;
        result++;
        int &j = pi[p[p[i]]], k = pi[i];
        swap(p[p[i]], p[pi[i]]);
        swap(j, k);
    }
    cout << result << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
