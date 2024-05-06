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
        for (int i = N; i >= X; i--) {
            if (dp[i - X]) dp[i] = 1;
        }
    }

    vector<int> result;
    for (int i = 1; i <= 100'000; i++) {
        if (dp[i]) result.push_back(i);
    }

    cout << result.size() << "\n";
    for (int x : result) cout << x << " ";
    cout << "\n";
}
