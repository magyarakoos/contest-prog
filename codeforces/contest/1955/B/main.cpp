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
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            
        }
    }
}   

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
