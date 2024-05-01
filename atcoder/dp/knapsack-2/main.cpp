#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAXV = 1e5, INF = 1e18;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int N, W;
    cin >> N >> W;
    vector<int> v(N + 1), w(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
    }

    vector dp(N + 1, vector<ll>(MAXV, INF));
}