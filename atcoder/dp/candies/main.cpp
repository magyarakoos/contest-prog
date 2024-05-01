#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

void madd(ll& a, ll b) {
    a += b;
    if (a >= MOD) a -= MOD;
}
void msub(ll& a, ll b) {
    a -= b;
    if (a < 0) a += MOD;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int N, K;
    cin >> N >> K;

    vector dp(K + 2, 0LL);
    dp[0] = 1;

    while (N--) {
        int A;
        cin >> A;
        vector ps(K + 2, 0LL);
        for (int k = K; k >= 0; k--) {
            int L = k + 1;
            int R = min(A, K - k);
            if (L <= R) {
                madd(ps[L], dp[k]);
                msub(ps[R + 1], dp[k]);
            }
        }
        for (int i = 1; i <= K; i++) {
            madd(ps[i], ps[i - 1]);
            madd(dp[i], ps[i]);
        }
    }

    cout << dp[K];
}
