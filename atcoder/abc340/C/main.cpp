#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()
#define has(s, e) s.count(e)

using namespace std;
using ull = long long;

ull result = 0;

void solve(ull n) {
    if (n < 2) {
        return;
    }

    ull a = n / 2,
        b = n / 2 + (n & 1);

    result += a + b;

    solve(a);
    solve(b);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    ull N;
    cin >> N;

    solve(N);

    cout << result;
}