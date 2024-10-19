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
    int N;
    cin >> N;
    vector<int> a(N);
    for (int& x : a) cin >> x;
    sort(rall(a));
    map<int, int> m;
    for (int i = 0; i < N - 1; i++) {
        int b;
        cin >> b;
        m[b]++;
    }
    int x = 0;
    for (int i = 0; i < N; i++) {
        if (!m.empty() &&
            (*m.rbegin()).first >= a[i]) {
            auto it = *(m.lower_bound(a[i]));
            DB(it.first, it.second, a[i]);
            m[it.first]--;
            if (!m[it.first]) {
                m.erase(it.first);
            }
        } else {
            if (x) {
                cout << "-1\n";
                return;
            }
            x = a[i];
        }
    }
    cout << x << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
