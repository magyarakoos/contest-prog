#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

const int INF = 1e9;

#define cases 1
void solve() {
    int N;
    cin >> N;
    vector<int> v(N), a(N);
    for (int i = 1; i < N; i++) cin >> v[i];
    a[0] = v[1] + 1;
    for (int i = 1; i < N; i++) {
        while (a[i - 1] <= v[i]) {
            a[i - 1] += a[i - 2];
        }
        a[i] = a[i - 1] + v[i];
    }
    for (int x : a) cout << x << " ";
    cout << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
