#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;

ll result = 0;

void solve(ll n) {
    if (n < 2) {
        return;
    }

    int a = n / 2,
        b = n / 2 + (n & 1);

    solve(n / 2);
    solve(n / 2 + (n & 1));
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    ll N;
    cin >> N;

    solve(N);

    cout << result;
}