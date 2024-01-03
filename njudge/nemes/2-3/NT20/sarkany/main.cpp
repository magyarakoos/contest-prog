#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;
using point = array<int, 2>;

ll digc(ll n) {
    ll result = 1;

    while (n / 10 != 0) {
        n /= 10;
        result++;
    }

    return result;
}

int main() {
    speed;

    int cnt = 3;
    while (cnt--) {
        ll A, B, N;
        cin >> A >> B >> N;
        ll mn = lcm(A, B), rem = N - digc(mn);
        if (rem < 0) {
            cout << -1;
        } else {
            cout << mn;
            for (ll i = 0; i < rem; i++) cout << 0;
        }
        cout << '\n';
    }
}
