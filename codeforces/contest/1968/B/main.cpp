#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

#define cases 1
void solve() {
    int N, M;
    string a, b;
    cin >> N >> M >> a >> b;
    int K = 0, bp = 0;
    while (K < N && bp < M) {
        while (bp < M && a[K] != b[bp]) bp++;
        if (bp < M) K++, bp++;
    }
    cout << K << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
