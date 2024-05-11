#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    
    int M, N;
    cin >> M >> N;

    vector<int> S(M), L(M);
    for (int& e : S) cin >> e;
    for (int& e : L) cin >> e;

    ll S_sum = accumulate(all(S), 0),
       L_sum = accumulate(all(L), 0);
    
    ll res = 0;

    for (int i = 0; i < N; i++) {
        res += (S[0] + L[0]) * S_sum;
        res %= MOD;
        res += S[0] * L_sum;
        res %= MOD;
    }

    cout << res;
}