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

#define cases 0
void solve() {
    int N, M;
    cin >> N >> M;
    map<int, vector<int>> m;
    for (int i = 0; i < M; i++) {
        int a;
        char c;
        cin >> a >> c;
        if (c == 'F') continue;
        m[a].push_back(i);
    }

    vector<string> result(M, "No");
    for (auto [k, v] : m) { result[v[0]] = "Yes"; }
    for (const string& s : result) cout << s << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
