#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;

struct Point { 
    ll x;
    ll y;
};

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    constexpr Point a = {0, 0};
    
    Point b, c;
    cin >> b.x >> b.y;

    Point rectA = {min({a.x, b})}

    cout << c.x << ' ' << c.y;
}
