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

    vector dp(N + 1, vector<ll>(M));
    dp[0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < M; k++) {
                dp[i + 1][k] += dp[i][j] * (S[j] + L[j]) * S[k];
                dp[i + 1][k] %= MOD;
                dp[i + 1][k] += dp[i][j] * S[j] * L[k];   
                dp[i + 1][k] %= MOD;
            }
        }
    }

    ll res = 0;
    for (int j = 0; j < M; j++) {
        res += dp[N][j];
        res %= MOD;
    }
    cout << res;
}