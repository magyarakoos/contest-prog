#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, W, w, v;
    cin >> N >> W;
    vector<long long> dp(W + 1);
    while (N--) {
        cin >> w >> v;
        for (int i = W; i >= w; i--) {
            dp[i] = max(dp[i], dp[i - w] + v);
        }
    }
    cout << *max_element(dp.begin(), dp.end());
}

