#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> v(N), ps(N + 1);
    for (ll& x : v) cin >> x;
    sort(v.begin(), v.end());

    for (int i = 1; i <= N; i++) {
        ps[i] = ps[i - 1] + v[i - 1];
    }

    for (int i = 0; i <= N; i++) {
        cout << ps[i] << " ";
    }
    cout << "\n";

    bool a_turn = 1;


}
