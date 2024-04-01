#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> v(N), ps(N);
    for (ll& x : v) cin >> x;
    sort(v.begin(), v.end());

    ps[0] = v[0];
    for (int i = 1; i < N; i++) {
        ps[i] = ps[i - 1] + v[i];
    }

    array<ll, 2> playerS {0, 0};

    bool turn = 0;

    for (int i = v.size() - 1; i >= 0; i--) {
        if (i + 1 <= K && v[i] < ps[i]) {
            playerS[turn] += ps[i];
            break;
        }

        playerS[turn] += v[i];

        turn ^= 1;
    }

    cout << playerS[0] << " " << playerS[1];
}
