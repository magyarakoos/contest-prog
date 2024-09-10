#include "debug.h"
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<string> a(N);
    for (string& s : a) cin >> s;

    sort(a.begin(), a.end(),
         [](const string& s, const string& t) { return s + t > t + s; });

    // knapsack
    vector<string> dp(K + 1, "[");
    dp[0] = "";

    for (string& s : a) {
        for (int i = K; i > 0; i--) { dp[i] = min(dp[i], s + dp[i - 1]); }
        DB(dp);
    }

    cout << dp[K];
}

