#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    ll N, K;
    cin >> N >> K;

    ll result = 0;

    vector<ll> a(K);
    for (ll& x : a) cin >> x;

    for (int mask = 1; mask < (1 << K); mask++) {
        ll curr = N;
        for (int i = 0; i < K; i++) {
            if (mask >> i & 1) curr /= a[i];
        }

        if (__builtin_popcount(mask) & 1) {
            result += curr;
        } else {
            result -= curr;
        }
    }

    cout << result << "\n";
}
