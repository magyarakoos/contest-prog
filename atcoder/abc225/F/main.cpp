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
    vector<string> dp(K + 1, string(50, '['));
    dp[0] = "";

    for (string& s : a) {
        for (int i = K; i > 0; i--) { dp[i] = min(dp[i], s + dp[i - 1]); }
        for (int i = 0; i <= K; i++) cout << dp[i] << " ";
        cout << "\n";
    }

    cout << dp[K];
}

