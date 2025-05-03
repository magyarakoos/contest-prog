#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int N;
    array<int, 2> fire = {0, 0}, taka;
    cin >> N >> taka[0] >> taka[1];
    set<array<int, 2>> a;
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        a.insert(fire);
        if (c == 'N') {
            fire[0]++;
            taka[0]++;
        } else if (c == 'W') {
            fire[1]++;
            taka[1]++;
        } else if (c == 'S') {
            fire[0]--;
            taka[0]--;
        } else {
            fire[1]--;
            taka[1]--;
        }
        cout << a.count(taka);
    }
    cout << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
