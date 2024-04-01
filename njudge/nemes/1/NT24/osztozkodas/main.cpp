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
    
    for (int x : ps) cerr << x << " ";

    bool a_turn = 1;

    for (int i = v.size() - 1; i >= 0; i--) {
        if (i + 1 <= K) {
            if ()
        }
    }
}
