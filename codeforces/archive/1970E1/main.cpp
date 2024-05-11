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

    int S_sum = accumulate(all(S), 0),
        L_sum = accumulate(all(L), 0);
    
    int res = 0;

    for (int i = 0; i < N; i++) {
        res += S_sum * S_sum;
        res %= MOD;

    }
}