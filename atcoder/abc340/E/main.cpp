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

    int N, M;
    cin >> N >> M;

    vector<ll> A(N);
    cinv(A);

    while (M--) {
        int B;
        cin >> B;

        ll balls = A[B];
        A[B] = 0;

        ll div = balls / N;
        for (ll& x : A) {
            x += div;
        }

        int mod = balls % N;

        for (int i = 0; i < mod; i++) {
            int p = B + i + 1;
            if (p >= N) {
                p = 0;
            }

            A[p]++;
        }
    }

    for (ll x : A) cout << x << ' ';
    cout << '\n';
}