#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    
    int N, K;
    cin >> N >> K;
    vector<int> v(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }

    vector dp(N + 1, vector<ll>(K + 1));
    dp[0][0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            
        }
    }
}
