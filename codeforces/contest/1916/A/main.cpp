#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;
using point = array<int, 2>;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<ll> v(N);
    for (ll& x : v) cin >> x;
    ll prod = accumulate(all(v), 1, multiplies<ll>());
    
    if (prod > 2023 || 2023 % prod) {
        cout << "NO\n";
        return;
    }

    ll rem = 2023 / prod;
    
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
