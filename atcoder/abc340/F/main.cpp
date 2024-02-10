#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    constexpr ll X1 = 0, Y1 = 0;
    
    ll X2, Y2;
    cin >> X2 >> Y2;

    ll X3, Y3;

    ll bottomX = min({X1, X2, X3}), bottomY = min({Y1, Y2, Y3}),
       topX = max({X1, X2, X3}), topY =     

    cout << X3 << ' ' << Y3;
}