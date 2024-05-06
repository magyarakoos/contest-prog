#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<bool> dp(100'001);
    dp[0] = 1;

    while (N--) {
        int X;
        cin >> X;
        dp[X] = 1;
        for (int i = N; i >= X; i--) {
            if (dp[i - X]) dp[i] = 1;
        }
        for (int i = 1; i <= 13; i++) cout << dp[i];
        cout << "\n";
    }

    vector<int> result;
    for (int i = 1; i <= 100'000; i++) {
        if (dp[i]) result.push_back(i);
    }

    cout << result.size() << "\n";
    for (int x : result) cout << x << " ";
    cout << "\n";
}
