#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector v(N, 0);
    for (int& x : v) cin >> x;

    vector dp(N, vector<ll>(N, INF));

    for (int l = 0; l < N; l++) {
        
    }

    for (int l = N - 1; l >= 0; l--) {
        for (int r = l + 1; r < N; r++) {

        }
    }
}
