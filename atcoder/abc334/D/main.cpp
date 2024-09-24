#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> R(N), ps(N + 1);
    for (ll& x : R) cin >> x;

    sort(R.begin(), R.end());
    partial_sum(R.begin(), R.end(), ps.begin() + 1);

    while (Q--) {
        ll X;
        cin >> X;
        int i = lower_bound(ps.begin(), ps.end(), X) - ps.begin();
        cout << (i > N ? N : i - (ps[i] > X)) << "\n";
    }
}
