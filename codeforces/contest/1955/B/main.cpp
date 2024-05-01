#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

#define cases 1
void solve() {
    int N, C, D;
    cin >> N >> C >> D;
    set<int> s;
    for (int i = 0; i < N * N; i++) {
        int X;
        cin >> X;
        s.insert(X);
    }
    vector grid(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << N + i * C + j + D << " ";
            if (s.count(N + i * C + j + D)) {
                s.erase(N + i * C + j + D);
            } else {
                //cout << "NO\n";
                //return;
            }
        }
        cout << "\n";
    }
    cout << "\n";
    //cout << "YES\n";
}   

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
