#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

ll calc(const vector<int>& A, const vector<int>& O, int K) {
    vector<ll> B(sz(O));
    for (int i = 0; i < sz(O); i++) {
        B[i] = A[O[i]];
    }
    vector<ll> ps(sz(O) + 1);
    for (int i = 1; i <= sz(O); i++) {
        ps[i] = ps[i - 1] + B[i - 1];
    }
    vector<ll> value(sz(O));
    ll res = 0;
    for (int i = 0; i < sz(O) && i < K; i++) {
        smax(res, ps[i + 1] + B[i] * (K - i - 1));
    }
    return res;
}

#define cases 1
void solve() {
    int N, K, Pb, Ps;
    cin >> N >> K >> Pb >> Ps;
    Pb--, Ps--;
    vector<int> P(N), A(N);
    for (int& x : P) cin >> x, x--;
    for (int& x : A) cin >> x;

    vector<int> Ob {{Pb}};
    while (1) {
        Ob.push_back(P[Ob.back()]);
        if (Ob[0] == Ob.back()) {
            if (sz(Ob) > 1) Ob.pop_back();
            break;
        }
    }

    vector<int> Os {{Ps}};
    while (1) {
        Os.push_back(P[Os.back()]);
        if (Os[0] == Os.back()) {
            if (sz(Os) > 1) Os.pop_back();
            break;
        }
    }

    ll Vb = calc(A, Ob, K);
    ll Vs = calc(A, Os, K);
    if (Vb > Vs) {
        cout << "Bodya\n";
    }
    else if (Vb < Vs) {
        cout << "Sasha\n";
    }
    else {
        cout << "Draw\n";
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
