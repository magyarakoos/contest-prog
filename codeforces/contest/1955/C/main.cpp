#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

#define cases 1
void solve() {
    ll N, K;
    cin >> N >> K;
    deque<int> q;
    while (N--) {
        int X;
        cin >> X;
        q.push_back(X);
    }
    while (q.size() >= 2) {
        
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
