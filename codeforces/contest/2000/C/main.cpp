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
    vector<int> a(N);
    for (int& x : a) cin >> x;
    int M;
    cin >> M;
    while (M--) {
        string s;
        cin >> s;
        bool ok = 1;
        if (s.size() != N) {
            cout << "NO\n";
            continue;
        }

        map<char, int> m;
        for (int i = 0; i < N; i++) {
            if (!m.count(s[i])) {
                m[s[i]] = a[i];
            } else {
                if (m[s[i]] == a[i]) continue;
                ok = 0;
            }
        }

        map<int, char> m2;
        for (int i = 0; i < N; i++) {
            if (!m2.count(a[i])) {
                m2[a[i]] = s[i];
            } else {
                if (m2[a[i]] == s[i]) continue;
                ok = 0;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
