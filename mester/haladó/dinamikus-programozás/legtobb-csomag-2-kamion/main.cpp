#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int K, N;
    cin >> K >> N;
    
    vector<int> v(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }

    vector<array<int, 2>> dp(K + 1);

    for (int i = 1; i <= K; i++) {
        dp[i] = dp[i - 1];
        
    }
}