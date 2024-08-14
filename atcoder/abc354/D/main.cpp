#include <bits/stdc++.h>
#ifdef LOCAL
#include <debug.h>
#else
#define DB(...)
#endif
using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

ll inner_area(ll A, ll B, ll C, ll D) {
    if (A & 1) A++;
    if (B & 1) B++;
    if (C & 1) C--;
    if (D & 1) D--;

    ll H = D - B;
    ll W = C - A;

    DB(A, B, C, D, W);

    if (W / 2 % 2) {
        ll rem = A / 2 % 2;
        DB(rem);
        if (rem) {
            return H * (W - 2) + H;
        } else {
            return H * (W - 2) + 3 * H;
        }
    } else {
        return H * W;
    }
}

ll outer_area(ll A, ll B, ll C, ll D) {
    // 1 2 1 0
    // 1 2 3 4
    ll res = 0;
    if (B & 1) {
        vector<ll> v {1, 2, 1, 0, 1, 2, 1, 0};
        ll W = C - A;
        res += W / 4 * 4;
        
        ll remW = W % 4, remA = A % 4;
        for (int i = 0; i < remW; i++) {
            res += v[i + remA];
        }
        B++;
    }
    if (D & 1) {
        vector<ll> v {2, 1, 0, 1, 2, 1, 0, 1};
        ll W = C - A;
        res += W / 4 * 4;
        
        ll remW = W % 4, remA = A % 4;
        for (int i = 0; i < remW; i++) {
            res += v[i + remA];
        }
        D--;
    }
    if (A & 1) {
        ll rem = A % 4;
        ll H = D - B;
        if (rem == 1) {
            res += 3 * H / 2;
        } else {
            res += H / 2;
        }
    }
    if (C & 1) {
        ll rem = C % 4;
        ll H = D - B;
        if (rem == 1) {
            res += 3 * H / 2;
        } else {
            res += H / 2;
        }
    }
    return res;
}

#define cases 0
void solve() {
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    A += 1e9;
    B += 1e9;
    C += 1e9;
    D += 1e9;
    ll inner = inner_area(A, B, C, D);
    ll outer = outer_area(A, B, C, D);
    DB(inner, outer);
    cout << inner + outer << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
