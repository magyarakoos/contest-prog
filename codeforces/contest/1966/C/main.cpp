#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

#define cases 1
void solve() {
    int N;
    cin >> N;
    set<int> s;
    while (N--) {
        int X;
        cin >> X;
        s.insert(X);
    }

    N = sz(s);
    vector<int> v(N + 1);
    int i = 0;
    for (int x : s) {
        v[++i] = x;
    }

    vector<int> d(N);
    for (int i = 0; i < N; i++) {
        int d = v[i + 1] - v[i];
        if (d != 1) {
            cout << (i & 1 ? "Bob" : "Alice") << "\n";
            return;
        }
    }
    cout << (N & 1 ? "Alice" : "Bob") << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
