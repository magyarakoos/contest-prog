#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    
    int N, K;
    cin >> N >> K;
    vector<int> v(N);
    for (int& x : v) cin >> x;

    vector dp(N + 1, vector<ll>(K + 1));
    dp[0][0] = 1;


}
