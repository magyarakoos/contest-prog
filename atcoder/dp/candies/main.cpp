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

    vector dp(K + 1, 0LL);
    dp[0] = 1;

    while (N--) {
        int A;
        cin >> A;
        vector v(K + 1, 0LL);
        for (int k = K; k >= 0; k--) {
            int L = k + 1;
            int R = min(A, K - k);
            if (L <= R) {
                madd(v[L], dp[k]);
                if (R + 1 <= K) {
                    msub(v[R + 1], dp[k]);
                }
            }
        }
        ll ps = 0;
        for (int i = 0; i <= K; i++) {
            madd(ps, v[i]);
            madd(dp[i], ps);
        }
    }

    cout << dp[K];
}
