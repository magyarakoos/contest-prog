#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;
    vector<ll> v(N), ps(N + 1);
    for (ll& x : v) cin >> x;

    for (int i = 1; i <= N; i++) {
        ps[i] = ps[i - 1] + v[i - 1];
    }

    while (Q--) {
        int L, R;
        cin >> L >> R;
        cout << ps[R] - ps[L - 1] << "\n";
    }
}
