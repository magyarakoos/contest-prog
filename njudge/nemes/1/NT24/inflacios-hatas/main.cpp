#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, K;
    cin >> N >> K;
    vector<ll> v(N);
    for (ll& x : v) cin >> x;

    sort(v.begin(), v.end());

    ll result = 0;

    for (int i = 0; i < N; i++) {
        for (int j = max(i + 1, N - K); j < N; j++) {
            v[j] += v[i];
        }
        result += v[i];
    }

    cout << result;
}
