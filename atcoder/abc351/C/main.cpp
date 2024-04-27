#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

#define cases 0
void solve() {
    vector<ll> v;
    int N;
    cin >> N;
    while (N--) {
        int A;
        cin >> A;
        v.push_back(A);
    
    beginning:
        if (sz(v) <= 1) continue;
        if (v[sz(v) - 2] != v[sz(v) - 1]) continue;
        v.pop_back();
        v[sz(v) - 1]++;
        goto beginning;
    }
    cout << sz(v);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
