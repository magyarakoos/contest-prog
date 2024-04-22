#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> hpS(N);
    for (int& x : hpS) cin >> x;
    vector<int> v(N + 1);
    for (int i = 0; i < N; i++) {
        int X;
        cin >> X;
        v[abs(X)] += hpS[i];
    }

    
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    while (T--) solve();
}